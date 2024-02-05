#include <criterion/criterion.h>
#include "../include/asm++.h"

static void cmp_split(char **split, char const *const *const expected)
{
    size_t i = 0;

    while (NULL != split[i]) {
        cr_assert_str_eq(split[i], expected[i]);
        ++i;
    }
    cr_assert(NULL == split[i]);
    cr_assert(NULL == expected[i]);
}

Test(split, test_impl_one)
{
    char const *string = "this,is,my,args,list";
    char const *const expected[] = { "this", "is", "my", "args", "list", NULL };
    char **chunks = split(string, ",");

    if (NULL != chunks) {
        cmp_split(chunks, expected);
        delete_split(chunks);
    }
}

Test(split, test_impl_two)
{
    char const *string = "this,   is   ,   my,args   , l i s t ";
    char const *const expected[] = { "this", "   is   ", "   my", "args   ", " l i s t ", NULL };
    char **chunks = split(string, ",");

    if (NULL != chunks) {
        cmp_split(chunks, expected);
        delete_split(chunks);
    }
}
