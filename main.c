#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

#define NSEC_PER_SEC 1000000000L

void add_milliseconds(struct timespec *, long);

int main(void) {

    // Initialize the value of mp
    const auto mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "GeeksforGeeks");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));


    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");

    // Deletion of key
    delete (mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));
    freeHashMap(mp);


    struct timespec current_time = {0};
    timespec_get(&current_time, TIME_UTC);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&current_time.tv_sec));
    printf("Current time: %s\n", buffer);
    current_time.tv_sec++;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&current_time.tv_sec));
    printf("Current time after one second: %s\n", buffer);

    add_milliseconds(&current_time, 6200);


    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&current_time.tv_sec));
    printf("Current time after one minute: %s\n", buffer);

    return EXIT_SUCCESS;

}
void add_milliseconds(struct timespec *time, const long milliseconds) {

    printf("Adding %ld milliseconds to time: %ld seconds, %ld nanoseconds\n", milliseconds, time->tv_sec, time->tv_nsec);
    time->tv_nsec = (time->tv_nsec + (milliseconds * 1000)) % NSEC_PER_SEC;
    printf("%ld\n", time->tv_nsec);
    printf("Resulting time: %ld seconds, %ld nanoseconds\n", time->tv_sec, time->tv_nsec);
    time->tv_sec = time->tv_sec + (time->tv_nsec + (milliseconds * 1000))/NSEC_PER_SEC;
    printf("Resulting time after addition: %ld seconds, %ld nanoseconds\n", time->tv_sec, time->tv_nsec);

}

