/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_simple.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalferov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:06:32 by aalferov          #+#    #+#             */
/*   Updated: 2024/10/26 20:12:16 by aalferov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_SIMPLE_H
# define GET_NEXT_LINE_SIMPLE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strchr(char *s, int c);
void	*gnl_ft_calloc(size_t nmemb, size_t size);
char	*gnl_ft_strjoin(char *old_str, char *new_str);
char	*get_next_line_simple(int fd);

#endif
