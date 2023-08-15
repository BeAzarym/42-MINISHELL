/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:18:59 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:59:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 22:27:13 by cchabeau         ###   ########.fr       */
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_array(char **strs, int size)
{
	while (--size >= 0)
		free(strs[size]);
	free(strs);
	return (NULL);
}

char	**ft_arraydup(char **array, int size)
{
	int		i;
	char	**new_arr;

	if (!array)
		return (NULL);
	new_arr = malloc(sizeof(char *) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (array[i] && i < size)
	{
		new_arr[i] = ft_strdup(array[i]);
		if (!new_arr[i])
			ft_free_array(new_arr, i);
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
