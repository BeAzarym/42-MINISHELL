/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/17 19:13:30 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	have_qhotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	need_substitute(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_'
				|| str[i + 1] == '?'))
			return (1);
		i++;
	}
	return (0);
}

void	process_expand(t_cmd_lst *cmd, t_env_lst *env, int status)
{
	t_cmd	*lst;
	int		i;

	lst = cmd->head;
	while (lst)
	{
		i = 0;
		while (lst->cmd[i])
		{
			if (have_qhotes(lst->cmd[i]) || need_substitute(lst->cmd[i]))
				lst->cmd[i] = expand(lst->cmd[i], env, status);
			i++;
		}
		lst = lst->next;
	}
}

char	*handle_without_q(char *str, t_env_lst *env, int status)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			if (search_in_env(tmp, env))
				tmp = substitute_env(tmp, env, status);
			else
				tmp = ft_strdup("");
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$')
		{
			tmp = extract_word_sep(&str[i], "$");
			i += ft_strlen(tmp);
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}
char	*expand(char *str, t_env_lst *env, int status)
{
	int		i;
	char	*tmp;
	char	*res;

	if (verify_closed_qhotes(str) == -1)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			tmp = handle_s_qhote(&str[i]);
			i += escape_quotes(&str[i], i);
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] == '"')
		{
			tmp = handle_d_qhote(&str[i], env, status);
			i += escape_quotes(&str[i], i);
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '"' || str[i] != '\'')
		{
			tmp = handle_without_q(&str[i], env, status);
			i += compute_len(&str[i], "\"'");
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}
