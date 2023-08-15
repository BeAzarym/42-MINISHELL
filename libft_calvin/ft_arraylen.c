/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:54:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:19:07 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:54:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/16 22:54:58 by cchabeau         ###   ########.fr       */
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arraylen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
