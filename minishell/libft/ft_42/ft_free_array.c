/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:40:44 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 15:47:16 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_free_array(char **arr)
{
	int	row;

	row = 0;
	while (arr != NULL && arr[row] != NULL)
	{
		free(arr[row]);
		row++;
	}
	free(arr);
	return (NULL);
}
