/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:40 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

static char	**expand_cmd_table(char **cmd_table, t_env_lst *env)
{
	int	i;

	i = 0;
	while (cmd_table[i])
	{
		if (verify_closed_quotes(cmd_table[i]) == -1)
		{
			printf("ERROR: quote unclosed\n");
			return (NULL);
		}
		if (have_quotes(cmd_table[i]) || need_substitute(cmd_table[i])
			|| ft_strcmp(cmd_table[i], "~") == 0)
			cmd_table[i] = expand(cmd_table[i], env);
		i++;
	}
	return (cmd_table);
}

static t_redir_lst	*expand_redir(t_redir_lst *redir, t_env_lst *env)
{
	t_redir_node	*lst;

	lst = redir->head;
	if (!lst)
		return (NULL);
	{
		while (lst)
		{
			if (verify_closed_quotes(lst->file) == -1)
			{
				printf("ERROR: quote unclosed\n");
				return (NULL);
			}
			if ((have_quotes(lst->file) || need_substitute(lst->file))
				&& lst->type != 'H')
				lst->file = expand(lst->file, env);
			lst = lst->next;
		}
		return (redir);
	}
}

void	process_expand(t_cmd_lst *cmd, t_env_lst *env)
{
	t_cmd	*lst;

	if (!cmd)
		return ;
	lst = cmd->head;
	if (!lst || !lst->cmd)
		return ;
	while (lst)
	{
		if (lst->cmd)
			lst->cmd = expand_cmd_table(lst->cmd, env);
		if (lst->redir_in->head)
			lst->redir_in = expand_redir(lst->redir_in, env);
		if (lst->redir_out->head)
			lst->redir_out = expand_redir(lst->redir_out, env);
		lst = lst->next;
	}
}

static char	*process_quote(char *str, int i, t_env_lst *env)
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
		tmp = handle_d_quote(&str[i + 1], env);
		res = ft_strjoin_null(tmp, res);
		return (res);
	}
	return (res);
}

char	*expand(char *str, t_env_lst *env)
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
			tmp = process_quote(str, i, env);
			i = escape_quotes(str, i) + 1;
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '"' || str[i] != '\'')
		{
			tmp = handle_without_q(&str[i], env);
			i += compute_len(&str[i], "\"'");
			res = ft_strjoin_null(tmp, res);
		}
	}
	free(str);
	return (res);
}
