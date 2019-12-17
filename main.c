#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

int main() {
    FILE*  sortReads;
    FILE*  testReads;
    FILE*  matchedReads;

    char*  currentLine;
    size_t len = 0;
    int    count = 0;

    sortReads = fopen("sort_reads.txt", "r");
    testReads = fopen("test_reads.txt", "r");

    ht_hash_table* ht = ht_new();

    currentLine = NULL;
    while (getline(&currentLine, &len, sortReads) != -1) {
        ht_insert(ht, currentLine, "");
    }

    fclose(sortReads);

    matchedReads = fopen("matched_reads.txt", "w");

    len = 0;
    currentLine = NULL;
    while (getline(&currentLine, &len, testReads) != -1) {
        char* keyFound = ht_search(ht, currentLine);
        if (keyFound != NULL) {
            fwrite(currentLine, 101 * sizeof(char), 1, matchedReads);
            count += 1;
        }
    }

    free(currentLine);
    fclose(testReads);
    fclose(matchedReads);

    ht_del_hash_table(ht);
}
