#include "union_find.h"
#include <stdlib.h>

int id = 0;

union_find_t *uf_make_set(void *elem)
{
    union_find_t *ret = (union_find_t *)malloc(sizeof(union_find_t));
    ret->height = 1;
    ret->parent = ret;
    ret->value = elem;
    ret->id = id;
    id++;
    return ret;
}

union_find_t *uf_find(union_find_t *elem)
{
    if (elem == NULL)
    {
        return NULL;
    }
    union_find_t *tmp = elem;
    while (elem->parent != NULL)
    {
        elem = elem->parent;
    }
    if (elem != tmp->parent && elem != tmp)
    {
        tmp->parent = elem;
    }
    return elem;
}

union_find_t *uf_merge(union_find_t *set_1, union_find_t *set_2)
{
    if (set_1 == NULL || set_2 == NULL)
    {
        return NULL;
    }
    union_find_t *root_1 = uf_find(set_1);
    union_find_t *root_2 = uf_find(set_2);
    union_find_t *ret = set_1;
    if (root_1 != root_2)
    {
        if (root_1->height > root_2->height)
        {
            root_2->parent = root_1;
            root_1->height++;
        }
        else
        {
            root_1->parent = root_2;
            root_2->height++;
            ret = root_2;
        }
    }
    return ret;
}