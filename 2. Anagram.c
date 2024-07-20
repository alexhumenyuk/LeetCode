#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char* list;
} Object;

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

bool function1(char* s, char* t) {
    Object S, T;

    // Allocate memory for S.list and T.list
    S.list = malloc((strlen(s) + 1) * sizeof(char));
    T.list = malloc((strlen(t) + 1) * sizeof(char));

    // Copy characters from s and t to S.list and T.list
    strncpy(S.list, s, strlen(s) + 1);
    strncpy(T.list, t, strlen(t) + 1);

    // Sort the characters in S.list and T.list
    qsort(S.list, strlen(S.list), sizeof(char), compare);
    qsort(T.list, strlen(T.list), sizeof(char), compare);

    // Compare S.list and T.list and return true if they are equal, false otherwise
    return strcmp(S.list, T.list) == 0;
}

int main() {
    char* s = "amor";
    char* t = "roma";
    bool result = function1(s, t);
    printf(result ? "true" : "false");
    return 0;
}