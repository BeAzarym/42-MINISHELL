/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:59:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:18:51 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_print(char **array)
{
	if (!array)
		return ;
	while (*array != NULL)
	{
		ft_printf("|	{%s}	|\n", *array);
		array++;
	}
}
