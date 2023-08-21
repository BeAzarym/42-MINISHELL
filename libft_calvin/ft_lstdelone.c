/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
=======
<<<<<<< HEAD
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:18:57 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:21:39 by angassin         ###   ########.fr       */
=======
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
>>>>>>> Anaïs
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/05/02 13:52:48 by angassin          #+#    #+#             */
/*   Updated: 2023/03/30 11:52:12 by angassin         ###   ########.fr       */
=======
/*   Created: 2022/10/25 18:18:57 by cchabeau          #+#    #+#             */
/*   Updated: 2022/11/04 15:58:45 by cchabeau         ###   ########.fr       */
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
	Takes as a parameter a node and frees the memory of the node’s content 
	using the function ’del’ given as a parameter and free the node. 
	The memory of ’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
