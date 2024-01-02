/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/02 13:01:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PRINTF_H
# define FD_PRINTF_H

# include "libft.h"

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_puthexl_fd(unsigned int number, int fd);
int		ft_puthexu_fd(unsigned int number, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		fd_printf(int fd, const char *s, ...);

#endif
