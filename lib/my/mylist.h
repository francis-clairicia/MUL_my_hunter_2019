/*
** EPITECH PROJECT, 2019
** mylist.h
** File description:
** Header for linked list functions
*/

#include <stdlib.h>
#include <my.h>

#ifndef HEADER_MY_LIST
#define HEADER_MY_LIST

typedef struct linked_list
{
    int number;
    char character;
    char *string;
    struct linked_list *next;
} linked_list_t;

int my_list_size(linked_list_t const *begin);
int my_put_char_in_list(linked_list_t **list, char c);
int my_put_nbr_in_list(linked_list_t **list, int nbr);
int my_put_str_in_list(linked_list_t **list, char *str);
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
void my_free_list(linked_list_t **list);
void my_rev_list(linked_list_t **begin);
char *my_list_to_string(linked_list_t *list);

#endif
