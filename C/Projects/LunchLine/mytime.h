#ifndef MYTIME_H
#define MYTIME_H

#include <stdlib.h>
#include <time.h>

// Generates a random time between the given min and max (inclusive)
int mytime(int min, int max) {
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));
    
    // Generate a random number between min and max
    return min + rand() % (max - min + 1);
}

#endif // MYTIME_H