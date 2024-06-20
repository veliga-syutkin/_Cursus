/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:03:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/23 03:26:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate_string(int *str, int len)
{
	int		temp;
	int		cursor;

	temp = str[0];
	cursor = 0;
	while (cursor < len - 1)
	{
		str[cursor] = str[cursor + 1];
		cursor++;
	}
	str[cursor] = temp;
}

void	reverse_rotate_string(int *str, int len)
{
	int		temp;
	int		cursor;

	cursor = len;
	temp = str[len];
	while (cursor > 0)
	{
		str[cursor] = str[cursor - 1];
		cursor--;
	}
	str[cursor] = temp;
}

void	order_string(int *data, int len)
{
	int		cursor;
	int		temp;

	cursor = 0;
	while (cursor < len - 1)
	{
		if (data[cursor] > data[cursor + 1])
		{
			temp = data[cursor];
			data[cursor] = data[cursor + 1];
			data[cursor + 1] = temp;
			cursor = 0;
		}
		else
			cursor++;
	}
}

int	*list_a_to_string(t_list **list_a, t_list **list_b)
{
	int		*data;
	int		cursor;
	t_list	*temp;

	temp = *list_a;
	cursor = 0;
	data = (int *)malloc(sizeof(int) * get_len(*list_a) - 1);
	if (!data)
	{
		clear_list(list_b);
		error(list_a);
	}
	while (temp && cursor < get_len(*list_a))
	{
		data[cursor] = temp->data;
		temp = temp->next;
		cursor++;
	}
	return (data);
}

int	*list_b_to_string(t_list **list_a, t_list **list_b)
{
	int		*data;
	int		cursor;
	t_list	*temp;

	temp = *list_b;
	cursor = 0;
	data = (int *)malloc(sizeof(int) * get_len(*list_b) - 1);
	if (!data)
	{
		clear_list(list_b);
		error(list_a);
	}
	while (temp && cursor < get_len(*list_b))
	{
		data[cursor] = temp->data;
		temp = temp->next;
		cursor++;
	}
	return (data);
}
