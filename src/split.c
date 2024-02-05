#include <stdlib.h>
#include <string.h>

static size_t count_blocks(char const *string, char const *sep, size_t sep_len)
{
    size_t count = 1;
    char const *tmp = strstr(string, sep);

    while (NULL != tmp) {
        tmp = strstr(tmp + sep_len, sep);
        ++count;
    }
    return count;
}

static char *strdup(char const *string, size_t length)
{
    char *block = NULL;

    block = (char *) calloc(length + 1, sizeof(char));
    if (NULL != block)
        strncpy(block, string, length);
    return block;
}

static char *new_block(char const *string, char const *sep)
{
    char const *tmp = strstr(string, sep);

    if (NULL == tmp)
        return NULL;
    return strdup(string, tmp - string);
}

char **split(char const *string, char const *sep)
{
    size_t block_idx = 0;
    size_t cursor = 0;
    char *block = NULL;
    char **blocks = NULL;
    size_t sep_len = strlen(sep);
    size_t blocks_count = count_blocks(string, sep, sep_len);

    blocks = (char **) calloc(blocks_count + 1, sizeof(char *));
    if (NULL == blocks)
        return NULL;
    block = new_block(&string[cursor], sep);
    while (NULL != block) {
        blocks[block_idx] = block;
        ++block_idx;
        cursor += strlen(block) + sep_len;
        block = new_block(&string[cursor], sep);
    }
    blocks[block_idx] = strdup(&string[cursor], strlen(&string[cursor]));
    return blocks;
}

void delete_split(char **split)
{
    size_t i = 0;

    if (NULL != split)
        while (NULL != split[i]) {
            free(split[i]);
            ++i;
        }
    free(split);
}
