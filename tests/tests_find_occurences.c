#include <criterion/criterion.h>
#include "../include/asm++.h"

Test(find_occurences, test_impl_one)
{
    char const *haystack = "Hello, World !\n";
    char const *needle = "l";
    size_t occurences = find_occurences(haystack, needle);

    cr_assert(occurences == 3);
}

Test(find_occurences, test_impl_two)
{
    char const *haystack = "Hello, World !\n";
    char const *needle = "A";
    size_t occurences = find_occurences(haystack, needle);

    cr_assert(occurences == 0);
}
