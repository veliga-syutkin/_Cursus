/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 14:55:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

# define ERROR -1
# define LLONGI long long int

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd); //utiliser la mienne
int		ft_puthexl_fd(unsigned int number, int fd);
int		ft_puthexu_fd(unsigned int number, int fd);
int		ft_putnbr_fd(long long int n, int fd); // wtf
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putstr_fd(char *s, int fd); // idem
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_flag_check(char c);
int		ft_flag_sharp(char flag, char c, unsigned int number, int fd);
size_t	ft_strlen(const char*s);

//flags

int		ft_putarg_minus_flag(char c, va_list args);

//utils

bool	ft_str_is_sym(char c, const char *charset);
LLONGI	ft_diff_padd(const char *s, int cursor, LLONGI num);
void	ft_cursor_move(char s, int *cursor);
int		ft_intlen(long long int n);
LLONGI	ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putnchar_fd(LLONGI n, char c, int fd);

#endif