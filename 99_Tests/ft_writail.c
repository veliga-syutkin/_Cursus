/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:22:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/14 06:24:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_writail(int fd, char c, int n)
{
	static int i = 0;

	if (i++ < 5)
		return (write(fd, &c, n));
	return (-1);
}
# define write(x, y, z) ft_writail(x, y, z)

