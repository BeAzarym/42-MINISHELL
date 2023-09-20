/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/20 11:21:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

void	process_expand(t_cmd_lst *cmd, t_env_lst *env, int status)
{
	t_cmd	*lst;
	int		i;

	lst = cmd->head;
	if (!lst->cmd)
		return ;
	while (lst)
	{
		i = 0;
		while (lst->cmd[i])
		{
			if (verify_closed_quotes(lst->cmd[i]) == -1)
				error_exit("ERROR: quote unclosed\n");
			if (have_quotes(lst->cmd[i]) || need_substitute(lst->cmd[i]))
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

	res = NULL;
	i = 0;
	while (str[i] && !is_sep(str[i], "\"'"))
	{
		if (str[i] == '$')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			tmp = process_substitution(tmp, env, status);
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$')
		{
			tmp = extract_word_sep(&str[i], "$\"'");
			i += ft_strlen(tmp);
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}

static char	*process_quote(char *str, int i, t_env_lst *env, int status)
{
	char	*tmp;
	char	*res;

	res = NULL;
	if (str[i] == '\'')
	{
		tmp = handle_s_quote(&str[i]);
		res = ft_strjoin_null(tmp, res);
		return (res);
	}
	else
	{
		tmp = handle_d_quote(&str[i + 1], env, status);
		res = ft_strjoin_null(tmp, res);
		return (res);
	}
	return (res);
}

char	*expand(char *str, t_env_lst *env, int status)
{
	int		i;
	char	*tmp;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			tmp = process_quote(str, i, env, status);
			i = escape_quotes(str, i) + 1;
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
