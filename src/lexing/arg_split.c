/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:33:53 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/16 16:21:58 by angassin         ###   ########.fr       */
=======
/*   Updated: 2023/06/30 16:34:45 by cchabeau         ###   ########.fr       */
>>>>>>> end token
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	escape_quotes(char *str, int n)
{
	int	i;

	i = n;
	if (str[n] == '"')
	{
		i++;
		while (str[i] != '"' && str[i])
			i++;
		if (str[i] == '"')
			return (i);
	}
	else if (str[n] == '\'')
	{
		i++;
		while (str[i] != '\'' && str[i])
			i++;
		if (str[i] == '\'')
			return (i);
	}
	return (n);
}

<<<<<<< HEAD
<<<<<<< HEAD
int	is_sep(char c, char *sep)
=======
static int	is_sep(char c, char *sep)
>>>>>>> lexing part one
=======
int	is_sep(char c, char *sep)
>>>>>>> end token
{
	if (!sep)
		return (-1);
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static size_t	ft_count_word(char *s, char *sep)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		if (s[i])
		{
			if (s[i] == '"' || s[i] == '\'')
				i = escape_quotes(s, i);
			count++;
		}
		while (s[i] && !is_sep(s[i], sep))
			i++;
	}
	// printf("WC: [%ld]\n", count);
	return (count);
}

static int	jump_to_next_sep(char *s, char *sep, int i)
{
	while (s[i] && !is_sep(s[i], sep))
		{
			if (s[i] == '"' || s[i] == '\'')
				i = escape_quotes(s, i);
			i++;
		}
		return (i);
}

char	**arg_split(char *s, char *sep)
{
	char	**strs;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_count_word(s, sep) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		if (!s[i])
			break ;
		start = i;
		i = jump_to_next_sep(s, sep, i);
<<<<<<< HEAD
		strs[j] = ft_substr(s, start, (i - start));
		if (!strs[j])
			return (ft_array_clear(strs));
=======
		// printf("start : %d | i : %d\n", start, i);
		strs[j] = ft_substr(s, start, (i - start));
		if (!strs[j])
			return (ft_array_clear(strs));
		// printf("strs: %s\n", strs[j]);
>>>>>>> lexing part one
		j++;
	}
	strs[j] = NULL;
	return (strs);
}
