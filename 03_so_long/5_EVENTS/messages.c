/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 00:11:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-12 00:11:49 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	message(char *s)
{
	static char	*last;

	if (s)
	{
		if (last != s)
			ft_printf (s);
		last = s;
	}
}

void	notification(void)
{
	bool	end;

	end = false;
	if (exit_game(player(map, -1)))
		end = true;
	if (end)
		message(MSG_WON);
	else
		collectible(player(map, -1));
}
