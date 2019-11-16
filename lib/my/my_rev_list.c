/*
** EPITECH PROJECT, 2019
** my_rev_list
** File description:
** Reverse a linked list
*/

#include <mylist.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    int size_list = my_list_size(*begin);
    linked_list_t **arr = malloc(sizeof(linked_list_t *) * size_list);
    int i = 0;

    while (tmp != NULL) {
        arr[i] = tmp;
        tmp = tmp->next;
        i += 1;
    }
    arr[0]->next = NULL;
    i = 1;
    while (i < size_list) {
        arr[i]->next = arr[i - 1];
        i += 1;
    }
    *begin = arr[i - 1];
    free(arr);
}
