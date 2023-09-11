/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/11 11:59:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	need_substitute(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) == 1 || str[i + 1] == '_'))
			return (1);
		i++;
	}
	return (0);
}

// void	process_expand(t_cmd_lst *cmd, t_env *env)
// {
// 	t_cmd	*lst;
// 	int		i;

// 	lst = cmd->head;
// 	while (lst)
// 	{
// 		i = 0;
// 		while (lst->cmd[i])
// 		{
// 			expand(lst->cmd[i], env);
// 			i++;
// 		}
// 		lst = lst->next
// 	}
// }

// void	expand(char *str, t_env *env)
// {
// 	int	i;
// 	int	d_qh;
// 	int	s_qh;

// 	if (!str)
// 		return ;
// 	i = 0;
// 	d_qh = 0;
// 	s_qh = 0;
// 	while (str[i])
// 	{
// 		if (d_qh == 0 && str[i] == '"')
// 			d_qh = 1;
// 		if (s_qh == 0 && str[i] == '\'')
// 			s_qh = 1;
// 		while (str[i] && d_qh == 1)
// 		{
// 		}
// 		i++;
// 	}
// }
