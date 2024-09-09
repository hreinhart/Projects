//Hunter Reinhart 11886420
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <"mytime.h">

typedef struct customer{
    int ticket;
    sem_t sDone;
} customer;

typedef struct lunch {
    pthread_t *customerTIDS;
    pthread_t *serverTIDS;
    customer *customers;
    customer *queue[50];
    pthread_mutex_t ticketStop;
    pthread_mutex_t queueStop;
    pthread_mutex_t dequeueStop;
    sem_t CustReady;
    sem_t queueSpots;
    int tickCount;
    int numServ;
    int numCust;
    int queueBegin;
    int queueEnd;
} lunch;

    void lunch_init(struct lunch *lunch){
        lunch->tickerCounter = 1;
        lunch->queueStart = 0;
        lunch->queueEnd = -1;

        lunch->ticketStop = (pthread_mutex_t)PTHREAD_MUTEX_INTITIALIZER;
        lunch->queueStop = (pthread_mutex_t)PTHREAD_MUTEX_INTITIALIZER;
        lunch->dequeueStop = (pthread_mutex_t)PTHREAD_MUTEX_INTITIALIZER;

        sem_init(&(lunch->readyCustomers), 0, 0);
        sem_init(&(lunch->queueSlots), 0, 50);

        lunch->customers = (customer *)malloc(sizeof(customer) * (lunch->numCust));
        lunch->servers = (pthread_t *)malloc(sizeof(pthread_t) * (lunch->numServers));
    }
    int lunch_get_ticket(struct lunch *lunch){
        printf("%lu enter lunch_get_ticket\n", (long unsigned int)pthread_self());
        pthread_mutex_lock(&(lunch->tickerStop));
        sem_wait(&(lunch->queueSpots));
        int ticket = (lunch->tickCount)++;

        lunch->customers[ticket - 1].ticket = ticket;
        printf("%lu get ticket %d\n", (long unsigned int)pthread_self(), ticket);
    pthread_mutex_unlock(&(lunch->tickerStop));
    int waitTime = mytime(0, 10);
    printf("Sleeping Time: %d sec; Thread ID = %lu\n", waitTime, (long unsigned int)pthread_self());
    sleep(waitTime);
    printf("%lu leave lunch_get_ticket%d\n", (long unsigned int)pthread_self());
    return ticket;
    }
    void lunch_wait_turn(struct lunch *lunch){
        int ticket = lunch_get_ticket(lunch);
        printf("%lu enter lunch_wait_turn with %d\n", (long unsigned int)pthread_self(), ticket);
        pthread_mutex_lock(&(lunch->queueLock));
        (lunch->queueEnd)++;
        lunch->queueEnd %= 50;
        lunch->ticketQueue[lunch->queueEnd] = lunch->customers[ticket-1];
        sem_post(&(lunch->readyCustomers));
        pthread_mutex_unlock(&(lunch->queueStop));
        sem_wait(&(lunch->customers[ticket -1].sDone));
        printf("%lu leave lunch_wait_turn after %d served.\n", (long unsigned int)pthread_self(), ticket);
        pthread_exit(NULL);
    }
    void lunch_wait_customer(struct lunch *lunch){
        customer *served;
        printf("%lu enter lunch_wait_customer\n", (long unsigned int)pthread_self());
        int waitTime = mytime(10, 20);
        printf("Sleeping Time: %d sec; Thread ID = %lu\n", waitTime, (long unsigned int)pthread_self());
        sleep(waitTime);
        pthread_mutex_lock(&(lunch->dequeueStop));
        sem_wait(&(lunch->CustReady));
        served = lunch->ticketQueue[lunch->queueBegin];
        (lunch->queueBegin)++;
        lunch->queueStart %= 50;
        show_serving(served->ticket);
        sem_post(&(served->sDone));
        printf("%lu after served ticket %d\n", (long unsigned int)pthread_self(), served->ticket);
        sem_post(&(lunch->queueSpots));
        pthread_mutex_unlock(&(lunch->dequeueStop));
        printf("%lu leave lunch_wait_customer\n", (long unsigned int)pthread_self());
        pthread_exit(NULL);
    }
    void show_serving(int number){
        printf("Serving %d\n", number);
        return;
    }

    void enqueue(struct lunch *lunch, struct customer *customer){
        (lunch->queueEnd)++;
        lunch->queueEnd %= 50;
        lunch->ticketQueue[lunch->queueEnd] = customer;
        return;
    }
    



    int main(int argc, char **argv){
        lunch *lunch = (struct lunch*)malloc(sizeof(struct lunch));

        if(argc < 3){
            printf("Invalid argument. Enter the servers and customers seperated by space.\n");
            scanf("%d %d", &(lunch->numServ), &(lunch->numCust));
        }
        else{
            lunch->numServ = atoi(argv[1]);
            lunch->numCust = atoi(argv[2]);
        }

        lunch_init(lunch);
        int i;
        for(i = 0; i < lunch->numServ; i++){
            pthread_create(&(lunch->servers[i]), NULL, (void*)lunch_wait_customer, lunch);
        }
        for(i= 0; i < lunch->numCust; i++){
            pthread_create(&(lunch->customers[i].threadID), NULL, (void*)lunch_wait_turn, lunch);
        }
        for(i=0; i < lunch->numServ; i++){
            pthread_join(lunch->serverTIDS[i], NULL);
        }
        for(i=0; i< lunch->numCust; i++){
            pthread_join(lunch->customerTIDs[i].threadID, NULL);
        }

        free(lunch->customers);
        free(lunch->serversTIDS);
        free(lunch->customerTIDS);
        free(lunch);
        return 0;
    }