/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:16 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:18:14 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:38:16 by cchabeau          #+#    #+#             */
/*   Updated: 2023/06/20 01:50:29 by cchabeau         ###   ########.fr       */
>>>>>>> merge ok, commented main.c and buggy code minishell.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_array_clear(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}
