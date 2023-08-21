/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
=======
<<<<<<< HEAD
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:22:40 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:21:56 by angassin         ###   ########.fr       */
=======
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
>>>>>>> Anaïs
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/05/02 14:56:35 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:22 by angassin         ###   ########.fr       */
=======
/*   Created: 2022/10/25 18:22:40 by cchabeau          #+#    #+#             */
/*   Updated: 2022/11/07 17:57:30 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
>>>>>>> Anaïs
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//	Iterates the list and applies the function ’f’ on the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}	
}
