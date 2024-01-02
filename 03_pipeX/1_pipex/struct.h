/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:25:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/02 13:01:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "pipex.h"

typedef struct s_pipex
{
	char	**cmd;
	char	**env;
	char	*infile;
	char	*outfile;
	int		pipe[2];
	int		fd_in;
	int		fd_out;
	int		pid;
	int		status;
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		n;
	int		o;
	int		p;
	int		q;
	int		r;
	int		s;
	int		t;
	int		u;
	int		v;
	int		w;
	int		x;
	int		y;
	int		z;
}				t_pipex;

#endif