/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/22 13:59:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MHANDLER_H
# define MHANDLER_H

# include "../so_long.h"

typedef struct s_allocs
{
	unsigned int	id;
	void			*content;
	struct s_allocs	*next;
} t_allocs;

#endif