/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
=======
<<<<<<< HEAD
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:19:57 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:21:22 by angassin         ###   ########.fr       */
=======
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
>>>>>>> Anaïs
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/05/02 14:41:35 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:15 by angassin         ###   ########.fr       */
=======
/*   Created: 2022/10/25 18:19:57 by cchabeau          #+#    #+#             */
/*   Updated: 2022/11/04 13:04:33 by cchabeau         ###   ########.fr       */
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
	Deletes and frees the given node and every successor of that node, 
	using the function ’del’ and free(3).
    Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
