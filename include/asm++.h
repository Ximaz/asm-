#pragma once

#include <stddef.h>

static char const *const calling_convention[] = {
    "rdi",
    "rsi",
    "rdx",
    "r10",
    "r8",
    "r9",
    NULL
};

size_t find_occurences(char const *haystack, char const *needle);
char *replace(char const *haystack, char const *needle, char const *value);
char *trim(char const *string, size_t end);
char **split(char const *string, char const *sep);
void delete_split(char **split);
