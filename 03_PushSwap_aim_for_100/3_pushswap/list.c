/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:54:38 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:41:02 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* Checks if there are any duplicates in the list
*/
static int	intchr(int *data, int sample, int len)
{
	int	occurence;
	int	cursor;

	cursor = 0;
	occurence = cursor;
	while (cursor < len)
		if (*(cursor++ + data) == sample)
			occurence++;
	if (occurence != 1)
		return (1);
	return (0);
}

/* Checks if there are any duplicates in the list
*/
static void	check_duplicate(int *data, int len)
{
	int	cursor;

	cursor = 0;
	while (cursor < len)
	{
		if (intchr(data, *(data + cursor++), len))
		{
			free(data);
			error(NULL, 2);
		}
	}
}

/* initializes chained list of stack a*/
t_list	*create(int *data, int len)
{
	int		cursor;
	t_list	*result;
	t_list	*buffer;

	if (!data)
		error(NULL, 2);
	check_duplicate(data, len);
	cursor = 0;
	result = malloc(sizeof(t_list));
	if (!result)
		error(NULL, 2);
	buffer = result;
	buffer->data = *data;
	cursor++;
	while (cursor < len)
	{
		buffer->next = malloc(sizeof(t_list));
		buffer = buffer->next;
		if (!buffer)
			error(&result, 2);
		buffer->data = *(data + cursor);
		cursor++;
	}
	buffer->next = NULL;
	return (result);
}

int	get_next_data(t_list *list, int data)
{
	while (list->data != data)
		list = list->next;
	return (list->next->data);
}

/* frees the list */
void	clear_list(t_list **list)
{
	t_list	*buffer;
	t_list	*buffer_next;

	if (list)
	{
		buffer = *list;
		while (buffer->next)
		{
			buffer_next = buffer->next;
			free(buffer);
			buffer = buffer_next;
		}
		free(buffer);
	}
}
