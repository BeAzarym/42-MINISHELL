/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:04 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:19:20 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:16:04 by cchabeau          #+#    #+#             */
/*   Updated: 2023/02/21 13:54:05 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	if (n > 0)
	{
		while (++i < n)
			ft_memset(s, 0, n);
	}
}
