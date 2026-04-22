#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

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

    return EXIT_SUCCESS;
}