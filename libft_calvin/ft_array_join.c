/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:39:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:18:43 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:39:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/09 15:37:09 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_join(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**new_arr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	while (s1[size])
		size++;
	while (s2[size])
		size++;
	new_arr = malloc(sizeof(char *) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_arr[i] = ft_strdup(s1[i]);
	j = -1;
	while (s2[++j])
		new_arr[i + j] = ft_strdup(s2[j]);
	new_arr[i + j] = NULL;
	return (new_arr);
}

char	**ft_array_join_s1(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**new_arr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	while (s1[size])
		size++;
	while (s2[size])
		size++;
	new_arr = malloc(sizeof(char *) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_arr[i] = ft_strdup(s1[i]);
	ft_array_clear(s1);
	j = -1;
	while (s2[++j])
		new_arr[i + j] = ft_strdup(s2[j]);
	new_arr[i + j] = NULL;
	return (new_arr);
}

char	**ft_array_join_s2(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**new_arr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	while (s1[size])
		size++;
	while (s2[size])
		size++;
	new_arr = malloc(sizeof(char *) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_arr[i] = ft_strdup(s1[i]);
	j = -1;
	while (s2[++j])
		new_arr[i + j] = ft_strdup(s2[j]);
	ft_array_clear(s2);
	new_arr[i + j] = NULL;
	return (new_arr);
}

char	**ft_array_join_all(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**new_arr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	while (s1[size])
		size++;
	while (s2[size])
		size++;
	new_arr = malloc(sizeof(char *) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_arr[i] = ft_strdup(s1[i]);
	ft_array_clear(s1);
	j = -1;
	while (s2[++j])
		new_arr[i + j] = ft_strdup(s2[j]);
	ft_array_clear(s2);
	new_arr[i + j] = NULL;
	return (new_arr);
}
