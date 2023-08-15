/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 03:46:17 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/20 03:56:18 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char *ft_strndup(char *s, int n)
{
	
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (s[i] != '\0' && i <= n)
	{
		dup[i] = s[i];
		i++;
	}
	*dup = '\0';
	return (dup);
}