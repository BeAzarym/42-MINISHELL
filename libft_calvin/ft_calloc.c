/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:24:36 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:56:46 by angassin         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:24:05 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:19:26 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:24:05 by cchabeau          #+#    #+#             */
/*   Updated: 2022/12/23 15:27:55 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
>>>>>>> Anaïs
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	The calloc() function contiguously allocates enough space for count objects 
	that are size bytes of memory each and returns a pointer to the allocated 
	memory.  The allocated memory is filled with bytes of value zero.
	If successful return a pointer to allocated memory. 
	If there is an error, they return a NULL pointer and set errno to ENOMEM.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*em;

	em = malloc(count * size);
	if (!em)
		return (NULL);
	ft_bzero(em, count * size);
	return (em);
}
