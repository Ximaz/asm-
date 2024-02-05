#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int is_valid_char(int c)
{
    return c > ' ' && c < 127;
}

char *trim(char const *string, size_t end)
{
    char *trimmed = NULL;
    size_t start = 0;

    if (ULONG_MAX == end)
        end = strlen(string) - 1;
    while (!is_valid_char(string[start]) && 0 != string[start])
        ++start;
    while (!is_valid_char(string[end]) && string != &string[end])
        --end;
    trimmed = (char *) calloc(end - start + 2, sizeof(char));
    if (NULL == trimmed)
        return NULL;
    trimmed = strncpy(trimmed, &string[start], end - start + 1);
    return trimmed;
}
