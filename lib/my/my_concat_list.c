/*
** EPITECH PROJECT, 2019
** my_concat_list
** File description:
** Concatenate two linked lists
*/

#include <mylist.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp;

    if ((*begin1) == NULL) {
        (*begin1) = begin2;
    } else {
        tmp = (*begin1);
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = begin2;
    }
}
