/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:47:06 by angassin          #+#    #+#             */
/*   Updated: 2023/08/25 12:54:56 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cat_size(int argc, va_list strs);
static void	get_next_str(va_list *strs, char *cat, int *index);

/*
	Allocates (with malloc(3)) and returns a new string, which is the result of
	the concatenation of ’s1’ and ’s2’.
	Returns the new string or NULL if allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	cat_size;

	if (!s1 || !s2)
		return (NULL);
	cat_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = malloc(sizeof(*cat) * cat_size);
	if (!cat)
		return (NULL);
	ft_strlcpy(cat, s1, ft_strlen(s1) + 1);
	ft_strlcat(cat, s2, cat_size);
	return (cat);
}

/*
	Same as strjoin but concatenating the number of strings sent in argument
*/
char	*variadic_strjoin(int argc, ...)
{
	va_list	strs;
	va_list	strs_cpy;
	char	*cat;
	int		index;
	int		strs_count;

	va_start(strs, argc);
	va_copy(strs_cpy, strs);
	cat = malloc(sizeof(*cat) * (cat_size(argc, strs_cpy) + 1));
	if (cat == NULL)
		return (NULL);
	index = 0;
	strs_count = -1;
	while (++strs_count < argc)
		get_next_str(&strs, cat, &index);
	cat[index] = '\0';
	return (cat);
}

static int	cat_size(int argc, va_list strs)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < argc)
	{
		size += ft_strlen(va_arg(strs, char *));
		++i;
	}
	return (size);
}

static void	get_next_str(va_list *strs, char *cat, int *index)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = va_arg(*strs, char *);
	len = ft_strlen(tmp);
	i = 0;
	while (i < len)
	{
		cat[*index] = tmp[i];
		++i;
		++(*index);
	}
}

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
