/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:03:42 by angassin          #+#    #+#             */
/*   Updated: 2023/09/11 11:06:15 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		if (nb > LLONG_MAX && sign == 1)
			return (-1);
		if (nb > LLONG_MAX && sign == -1)
			return (0);
		str++;
	}
	return (nb * sign);
}
