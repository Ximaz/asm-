#include <stdlib.h>
#include <string.h>

size_t find_occurences(char const *haystack, char const *needle)
{
    char const *next = NULL;
    size_t needle_len = strlen(needle);
    size_t occurences = 0;

    next = strstr(haystack, needle);
    while (NULL != next) {
        ++occurences;
        next = strstr(next + needle_len, needle);
    }
    return occurences;
}
