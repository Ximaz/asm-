#include <stdlib.h>
#include <criterion/criterion.h>
#include "../include/asm++.h"

Test(replace, test_impl_one)
{
    char const *haystack = "Hello, World !\n";
    char const *needle = "l";
    char const *value = "BLA";
    char const *haystack_bkp = haystack;
    char const *needle_bkp = needle;
    char const *value_bkp = value;
    char *repl = replace(haystack, needle, value);

    if (NULL != repl) {
        cr_assert_str_eq(repl, "HeBLABLAo, WorBLAd !\n");
        free(repl);
    }
    cr_assert(haystack == haystack_bkp);
    cr_assert(needle == needle_bkp);
    cr_assert(value == value_bkp);
}

Test(replace, test_impl_two)
{
    char const *haystack = "Hello, World !\n";
    char const *needle = "A";
    char const *value = "BLA";
    char const *haystack_bkp = haystack;
    char const *needle_bkp = needle;
    char const *value_bkp = value;
    char *repl = replace(haystack, needle, value);

    if (NULL != repl) {
        cr_assert_str_eq(repl, "Hello, World !\n");
        free(repl);
    }
    cr_assert(haystack == haystack_bkp);
    cr_assert(needle == needle_bkp);
    cr_assert(value == value_bkp);
}
