/*
** EPITECH PROJECT, 2019
** my_put_in_list
** File description:
** Put an element into a list
*/

#include <mylist.h>

int my_put_char_in_list(linked_list_t **list, char c)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    if (element != NULL) {
        element->number = 0;
        element->character = c;
        element->string = NULL;
        element->next = *list;
        *list = element;
        return (0);
    }
    return (1);
}

int my_put_nbr_in_list(linked_list_t **list, int nbr)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    if (element != NULL) {
        element->number = nbr;
        element->character = 0;
        element->string = NULL;
        element->next = *list;
        *list = element;
        return (0);
    }
    return (1);
}

int my_put_str_in_list(linked_list_t **list, char *str)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));
    if (element != NULL) {
        element->number = 0;
        element->character = 0;
        element->string = str;
        element->next = *list;
        *list = element;
        return (0);
    }
    return (1);
}
