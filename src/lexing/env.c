/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:54:49 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/08/09 15:31:38 by cchabeau         ###   ########.fr       */
=======
/*   Updated: 2023/08/07 10:12:24 by cchabeau         ###   ########.fr       */
>>>>>>> env update
=======
/*   Updated: 2023/08/09 15:31:38 by cchabeau         ###   ########.fr       */
>>>>>>> phoenix
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env_lst	*init_envp(char **envp)
{
	int i;
	t_env_lst *lst;
	char **tmp;

	lst = init_env_lst();
	if (!lst)
		return (NULL);
	i = 0;
	
	while (envp[i])
	{
		tmp = envp_split(envp[i]);
		lst = add_lst_env(tmp[0], tmp[1], lst);
<<<<<<< HEAD
<<<<<<< HEAD
		// printf("[KEY] >> %s	[VALUE] >> %s\n", tmp[0], tmp[1]);
=======
		printf("[KEY] >> %s	[VALUE] >> %s\n", tmp[0], tmp[1]);
>>>>>>> env update
=======
		// printf("[KEY] >> %s	[VALUE] >> %s\n", tmp[0], tmp[1]);
>>>>>>> phoenix
		ft_array_clear(tmp);
		i++;
	}
	return (lst);
}