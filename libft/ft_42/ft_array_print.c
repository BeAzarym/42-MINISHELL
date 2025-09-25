/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:59:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/25 14:43:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_array_print(char **array)
{
	if (!array)
		return ;
	while (*array != NULL)
	{
		ft_printf("|		  {%s}		     |\n", *array);
		array++;
	}
}
