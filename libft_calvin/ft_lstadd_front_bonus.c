/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:21:00 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:30 by cchabeau          #+#    #+#             */
/*   Updated: 2022/11/04 15:58:19 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
