/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:48 by angassin          #+#    #+#             */
/*   Updated: 2023/08/14 14:24:43 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Recursive function to display an unsigned number in the given base
void	ft_put_unbr_base_fd(unsigned long n, char *base, int fd)
{
	unsigned int	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_put_unbr_base_fd(n / base_len, base, fd);
		ft_put_unbr_base_fd(n % base_len, base, fd);
	}
	if (n < base_len)
		ft_putchar_fd(base[n], fd);
}
