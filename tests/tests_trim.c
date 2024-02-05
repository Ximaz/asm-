#include <stdlib.h>
#include <criterion/criterion.h>
#include "../include/asm++.h"

Test(trim, test_impl_one)
{
    char const *string = "\r\n\t    Hello, World !\n  \t";
    char *trimmed = trim(string, -1);

    if (NULL != trimmed) {
        cr_assert_str_eq(trimmed, "Hello, World !");
        free(trimmed);
    }
}

Test(trim, test_impl_two)
{
    char const *string = "Hello, World !";
    char *trimmed = trim(string, -1);

    if (NULL != trimmed) {
        cr_assert_str_eq(trimmed, "Hello, World !");
        free(trimmed);
    }
}
