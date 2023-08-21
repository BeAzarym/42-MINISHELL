/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
=======
<<<<<<< HEAD
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:24:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:22:25 by angassin         ###   ########.fr       */
=======
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
>>>>>>> Anaïs
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/05/02 15:11:05 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:31 by angassin         ###   ########.fr       */
=======
/*   Created: 2022/10/25 18:24:10 by cchabeau          #+#    #+#             */
/*   Updated: 2022/11/04 16:14:00 by cchabeau         ###   ########.fr       */
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
	Iterates the list ’lst’ and applies the function ’f’ on the content of each 
	node. Returns a new list resulting of the successive applications of
	the function ’f’. Returns NULL if the allocation fails.
	The ’del’ function is used to delete the content of a node if needed.

*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = NULL;
	while (lst)
	{
		temp = ft_lstnew((f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
