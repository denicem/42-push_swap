/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:08:42 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/21 23:08:42 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/linked_list.h"

#include <stdio.h>

// OWN INT LINKED LIST
// TODO: replace og funcs with own func (have to use the og funcs, because own funcs doesn't work on Win - still have to figure that out)
// TODO: each node func in to seperate .c-files
// TODO: operations to own directory and .c-files
// TODO: create linked list initializer for the input (argv)
// TODO: handle error input (letters and duplicates)

t_node *new_node(int nbr)
{
	t_node *res;

	res = (t_node *) malloc(sizeof(t_node *));
	res->content = nbr;
	res->next = NULL;
	return (res);
}

int	get_listsize(t_node *list)
{
	int res;

	if (list == NULL)
		return (0);
	res = 1;
	while (list->next != NULL)
	{
		res++;
		list = list->next;
	}
	return (res);
}

t_node	*get_last(t_node *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_front(t_node **list, t_node *new)
{
	t_node *tmp;

	if (*list == NULL || new == NULL)
		return ;
	tmp = *list;
	*list = new;
	new->next = tmp;
}

void	add_back(t_node **list, t_node *new)
{
	t_node *last;

	if (new == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		(*list)->next = new;
		return ;
	}
	last = get_last(*list);
	last->next = new;
}

void	clear_list(t_node **list)
{
	t_node *tmp = *list;

	if (*list == NULL)
		return ;
	while (tmp->next != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	list = NULL;
}

void print_list(t_node **list) //TODO: after pushing last element from b to a and want to print out b, it segfaults.
{
	t_node *tmp;

	tmp = *list;
	while (list != NULL)
	{
		printf("%d", tmp->content);
		if (tmp->next == NULL)
			break ;
		printf(" - ");
		tmp = tmp->next;
	}
	printf("\n");
}

///////////////////////////////////////////////////////////////////////
// PUSH_SWAP OPERATIONS

void	swap(t_node **list, char *str)
{
	t_node *tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;

	printf("%s\n", str);
}

void	push(t_node **list_a, t_node **list_b, char *str) // TODO: think of a solution, how to update a new tail if you push something.
{
	t_node *tmp;

	tmp = *list_a;
	*list_a = tmp->next;
	tmp->next = *list_b;
	*list_b = tmp;

	printf("%s\n", str);
}

void	rotate(t_node **list, t_node *tail, char *str)
{
	t_node *tmp;

	tmp = *list;
	*list = (*list)->next;
	tail->next = tmp;
	tmp->next = NULL;

	printf("%s\n", str);
}

void	rev_rotate(t_node **list, char *str)
{
	t_node *ptr1;
	t_node *ptr2;

	ptr1 = *list;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		if (ptr2->next == NULL)
		{
			ptr2->next = *list;
			ptr1->next = NULL;
			*list = ptr2;
			break ;
		}
		ptr1 = ptr1->next;
	}
	printf("%s\n", str);
}

///////////////////////////////////////////////////////////////////////

int main (int argc, char **argv)
{
	t_node *n1 = new_node(123);
	t_node *n2 = new_node(42);
	t_node *n3 = new_node(4);
	t_node *n4 = new_node(56);
	t_node *n5 = new_node(21);
	t_node *head = n1;

	add_back(&head, n2);
	add_back(&head, n3);
	add_back(&head, n4);
	add_back(&head, n5);
	t_node *tail = get_last(head);

	t_node *list_b;

	add_front(&head, new_node(890));

	// rev_rotate(&head, "ra");
	// rotate(&head, tail, "ra");
	// swap(&head, "sa");
	push(&head, &list_b, "pb");
	push(&list_b, &head, "pa");

	print_list(&head);
	//print_list(&list_b);
	printf("\nHEAD: %d\n", head->content);
	printf("\nTAIL: %d\n", tail->content);
	printf("%d\n%s\n", argc, argv[0]);
	return (0);
}