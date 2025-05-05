#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For memory allocation and conversion functions
#include <string.h>     // For string manipulation functions
#include <pthread.h>    // For thread creation and synchronization
#include <semaphore.h>  // For semaphore operations
#include "mytime.h"     // Custom header for generating random sleep times

// Structure to represent a customer
typedef struct customer {
    int ticket;         // Ticket number assigned to the customer
    sem_t sDone;        // Semaphore to signal when the customer is served
    pthread_t threadID; // Thread ID for the customer
} customer;

// Structure to represent the lunch system
typedef struct lunch {
    pthread_t *customerTIDS;  // Array of customer thread IDs
    pthread_t *serverTIDS;    // Array of server thread IDs
    customer *customers;      // Array of customer structures
    customer *queue[50];      // Circular queue to hold customers waiting to be served
    pthread_mutex_t ticketStop;  // Mutex to protect ticket generation
    pthread_mutex_t queueStop;   // Mutex to protect queue operations
    pthread_mutex_t dequeueStop; // Mutex to protect dequeue operations
    sem_t CustReady;          // Semaphore to signal when a customer is ready
    sem_t queueSpots;         // Semaphore to track available spots in the queue
    int tickCount;            // Counter for ticket numbers
    int numServ;              // Number of servers
    int numCust;              // Number of customers
    int queueBegin;           // Index of the front of the queue
    int queueEnd;             // Index of the end of the queue
} lunch;

// Function to initialize the lunch system
void lunch_init(struct lunch *lunch) {
    lunch->tickCount = 1; // Start ticket count at 1
    lunch->queueBegin = 0; // Initialize queue front index
    lunch->queueEnd = -1;  // Initialize queue end index

    // Initialize mutexes
    lunch->ticketStop = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    lunch->queueStop = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    lunch->dequeueStop = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;

    // Initialize semaphores
    sem_init(&(lunch->CustReady), 0, 0);  // No customers ready initially
    sem_init(&(lunch->queueSpots), 0, 50); // Queue can hold up to 50 customers

    // Allocate memory for customers and threads
    lunch->customers = (customer *)malloc(sizeof(customer) * (lunch->numCust));
    lunch->serverTIDS = (pthread_t *)malloc(sizeof(pthread_t) * (lunch->numServ));
    lunch->customerTIDS = (pthread_t *)malloc(sizeof(pthread_t) * (lunch->numCust));
}

// Function for customers to get a ticket
int lunch_get_ticket(struct lunch *lunch) {
    printf("%lu enter lunch_get_ticket\n", (long unsigned int)pthread_self());
    pthread_mutex_lock(&(lunch->ticketStop)); // Lock ticket generation
    sem_wait(&(lunch->queueSpots));           // Wait for an available spot in the queue
    int ticket = (lunch->tickCount)++;        // Assign a ticket to the customer

    lunch->customers[ticket - 1].ticket = ticket; // Store the ticket in the customer structure
    printf("%lu get ticket %d\n", (long unsigned int)pthread_self(), ticket);
    pthread_mutex_unlock(&(lunch->ticketStop)); // Unlock ticket generation

    // Simulate random wait time
    int waitTime = mytime(0, 10);
    printf("Sleeping Time: %d sec; Thread ID = %lu\n", waitTime, (long unsigned int)pthread_self());
    sleep(waitTime);
    printf("%lu leave lunch_get_ticket %d\n", (long unsigned int)pthread_self(), ticket);
    return ticket;
}

// Function for customers to wait for their turn
void lunch_wait_turn(struct lunch *lunch) {
    int ticket = lunch_get_ticket(lunch); // Get a ticket
    printf("%lu enter lunch_wait_turn with %d\n", (long unsigned int)pthread_self(), ticket);
    pthread_mutex_lock(&(lunch->queueStop)); // Lock the queue for adding the customer
    (lunch->queueEnd)++;
    lunch->queueEnd %= 50; // Ensure circular queue behavior
    lunch->queue[lunch->queueEnd] = &(lunch->customers[ticket - 1]); // Add customer to the queue
    sem_post(&(lunch->CustReady)); // Signal that a customer is ready
    pthread_mutex_unlock(&(lunch->queueStop)); // Unlock the queue
    sem_wait(&(lunch->customers[ticket - 1].sDone)); // Wait until the customer is served
    printf("%lu leave lunch_wait_turn after %d served.\n", (long unsigned int)pthread_self(), ticket);
}

// Function for servers to serve customers
void lunch_wait_customer(struct lunch *lunch) {
    customer *served;
    printf("%lu enter lunch_wait_customer\n", (long unsigned int)pthread_self());
    int waitTime = mytime(10, 20); // Simulate random wait time
    printf("Sleeping Time: %d sec; Thread ID = %lu\n", waitTime, (long unsigned int)pthread_self());
    sleep(waitTime);
    pthread_mutex_lock(&(lunch->dequeueStop)); // Lock the queue for removing a customer
    sem_wait(&(lunch->CustReady)); // Wait for a customer to be ready
    served = lunch->queue[lunch->queueBegin]; // Get the customer at the front of the queue
    (lunch->queueBegin)++;
    lunch->queueBegin %= 50; // Ensure circular queue behavior
    show_serving(served->ticket); // Display the ticket being served
    sem_post(&(served->sDone)); // Signal that the customer has been served
    printf("%lu after served ticket %d\n", (long unsigned int)pthread_self(), served->ticket);
    sem_post(&(lunch->queueSpots)); // Signal that a spot in the queue is now available
    pthread_mutex_unlock(&(lunch->dequeueStop)); // Unlock the queue
    printf("%lu leave lunch_wait_customer\n", (long unsigned int)pthread_self());
}

// Function to display the ticket being served
void show_serving(int number) {
    printf("Serving %d\n", number);
}

// Main function to initialize and run the lunch system
int main(int argc, char **argv) {
    lunch *lunch = (struct lunch *)malloc(sizeof(struct lunch)); // Allocate memory for the lunch system

    // Validate command-line arguments
    if (argc < 3) {
        printf("Invalid argument. Enter the number of servers and customers separated by space.\n");
        return 1;
    } else {
        lunch->numServ = atoi(argv[1]); // Number of servers
        lunch->numCust = atoi(argv[2]); // Number of customers
    }

    lunch_init(lunch); // Initialize the lunch system

    int i;
    // Create server threads
    for (i = 0; i < lunch->numServ; i++) {
        pthread_create(&(lunch->serverTIDS[i]), NULL, (void *)lunch_wait_customer, lunch);
    }
    // Create customer threads
    for (i = 0; i < lunch->numCust; i++) {
        pthread_create(&(lunch->customerTIDS[i]), NULL, (void *)lunch_wait_turn, lunch);
    }
    // Wait for all server threads to finish
    for (i = 0; i < lunch->numServ; i++) {
        pthread_join(lunch->serverTIDS[i], NULL);
    }
    // Wait for all customer threads to finish
    for (i = 0; i < lunch->numCust; i++) {
        pthread_join(lunch->customerTIDS[i], NULL);
    }

    // Free allocated memory
    free(lunch->customers);
    free(lunch->serverTIDS);
    free(lunch->customerTIDS);
    free(lunch);
    return 0;
}