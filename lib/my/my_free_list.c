/*
** EPITECH PROJECT, 2019
** my_free_list
** File description:
** Free data in list
*/

#include <mylist.h>

void my_free_list(linked_list_t **list)
{
    linked_list_t *element;

    while ((*list) != NULL) {
        element = *list;
        *list = (*list)->next;
        if (element->string != NULL)
            free(element->string);
        free(element);
    }
}
