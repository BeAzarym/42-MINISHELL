/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:56:49 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/27 13:20:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_s1(char *s1, char *s2)
{
	size_t	len;
	size_t	len_s1;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	free(s1 - len_s1);
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - len);
}

char	*ft_strjoin_null(char *s1, char *s2)
{
	size_t	len;
	size_t	len_s1;
	char	*str;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (!s2)
		len = len_s1;
	else
		len = len_s1 + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (s2)
	{
		while (*s2)
			*str++ = *s2++;
	}
	while (*s1)
		*str++ = *s1++;
	free(s1 - len_s1);
	free(s2 - (len - len_s1));
	*str = '\0';
	return (str - len);
}
