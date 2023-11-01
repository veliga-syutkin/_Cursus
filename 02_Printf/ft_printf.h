/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/01 18:20:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd); //utiliser la mienne
int		ft_puthexl_fd(unsigned int number, int fd);
int		ft_puthexu_fd(unsigned int number, int fd);
int		ft_putnbr_fd(long long int n, int fd); // wtf
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putstr_fd(char *s, int fd); // idem
int		ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_strlen(const char*s);


#endif