#include <stdlib.h>
#include <string.h>
#include "../include/asm++.h"

static size_t compute_new_len(char const *haystack, char const *needle,
    char const *value)
{
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    size_t value_len = strlen(value);
    size_t occurences = find_occurences(haystack, needle);

    return haystack_len - (needle_len * occurences) + (value_len * occurences);
}

char *replace(char const *haystack, char const *needle, char const *value)
{
    char const *tmp = NULL;
    size_t new_len = compute_new_len(haystack, needle, value);
    size_t cursor = 0;
    size_t needle_len = strlen(needle);
    size_t value_len = strlen(value);
    char *new_string = (char *) calloc(new_len + 1, sizeof(char));

    if (NULL == new_string)
        return NULL;
    tmp = strstr(haystack, needle);
    while (NULL != tmp) {
        strncpy(&new_string[cursor], haystack, tmp - haystack);
        cursor += tmp - haystack;
        strncpy(&new_string[cursor], value, value_len);
        cursor += value_len;
        haystack = tmp + needle_len;
        tmp = strstr(haystack, needle);
    }
    strncpy(&new_string[cursor], haystack, strlen(haystack));
    return new_string;
}
