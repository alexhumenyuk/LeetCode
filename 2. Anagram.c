#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len != t_len) {
        return 0;
    }

    qsort(s, s_len, sizeof(char), compare);
    qsort(t, t_len, sizeof(char), compare);

    return (strncmp(s, t, s_len) == 0) ? 1 : 0;
}

int main() {
    char s[] = "amores";
    char t[] = "roma";

    printf("%d\n", isAnagram(s, t));

    return 0;
}