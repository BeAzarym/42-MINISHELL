/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:19:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:20:46 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:19:55 by cchabeau          #+#    #+#             */
/*   Updated: 2022/10/29 15:49:39 by cchabeau         ###   ########.fr       */
>>>>>>> merge ok, commented main.c and buggy code minishell.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_digit(long int n, int *is_neg)
{
	size_t	result;

	*is_neg = 0;
	result = 1;
	if (n < 0)
	{
		n *= -1;
		*is_neg = 1;
	}
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result + *is_neg);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;
	int			is_neg;

	nb = n;
	len = nbr_digit(nb, &is_neg);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
		nb *= -1;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		--len;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
