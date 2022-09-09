/**
 * @file 
 * @brief union_find implements the union_find datastructure
 */
#ifndef UNION_FIND_H
#define UNION_FIND_H

/**
 * @struct union_find
 * @brief The structure is an element of the union_find
 */
typedef struct union_find
{
    struct union_find *parent;
    void *value;
    int height;
} union_find_t;

/**
 * Creates a set for the given element
 * @param elem a void pointer to the element
 * @return a pointer to the created element
 */
union_find_t *uf_make_set(void *elem);

/**
 * Finds the parent element of the given element
 * @param elem a pointer to the union_find element
 * @return a pointer to the parent
 */
union_find_t *uf_find(union_find_t *elem);

/**
 * Merges to sets
 * @param set_1 The first set
 * @param set_2 The second set
 * @return The merged set
 */
union_find_t *uf_merge(union_find_t *set_1, union_find_t *set_2);

#endif // UNION_FIND_H
