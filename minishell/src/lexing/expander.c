/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:22 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/17 18:21:57 by cchabeau         ###   ########.fr       */
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

static int	verify_closed_qhotes(char *str)
{
	int	i;
	int	d_qh;
	int	s_qh;

	i = 0;
	d_qh = 0;
	s_qh = 0;
	while (str[i])
	{
		if ((str[i] == '"' && !d_qh) && !s_qh)
		{
			d_qh = 1;
			i++;
		}
		if ((str[i] == '"' && d_qh) && !s_qh)
			d_qh = 0;
		if ((str[i] == '\'' && !s_qh) && !d_qh)
		{
			s_qh = 1;
			i++;
		}
		if ((str[i] == '\'' && s_qh) && !d_qh)
			s_qh = 0;
		i++;
	}
	if (!s_qh && !d_qh)
		return (1);
	return (-1);
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

char	*handle_s_qhote(char *str)
{
	int		i;
	int		status;
	char	*res;

	i = 0;
	status = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !status)
		{
			status = 1;
			i++;
		}
		if (str[i] == '\'' && status)
			break ;
		i++;
	}
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[1], i);
	return (res);
}

static char	*extract_key(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?')
			j++;
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '?')
			break ;
		i++;
	}
	result = ft_substr(str, 0, j);
	if (!result)
		return (NULL);
	return (result);
}

char	*get_key_value(char *key, t_env_lst *env, int status)
{
	t_env	*cpy;
	char	*value;

	if (ft_strncmp(key, "?", 1) == 0)
	{
		value = ft_itoa(status);
		if (!value)
			return (NULL);
		return (value);
	}
	cpy = env->head;
	while (cpy)
	{
		if (ft_strncmp(key, cpy->key, ft_strlen(key)) == 0)
		{
			value = ft_strdup(cpy->value);
			if (!value)
				return (NULL);
			break ;
		}
		cpy = cpy->next;
	}
	return (value);
}

char	*substitute_env(char *key, t_env_lst *env, int status)
{
	char	*value;

	value = get_key_value(key, env, status);
	if (!value)
		return (NULL);
	free(key);
	return (value);
}

char	*handle_d_qhote(char *str, t_env_lst *env, int status)
{
	int		i;
	char	*tmp;
	char	*res;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$' && str[i] != '"')
		{
			tmp = extract_key(&str[i + 1]);
			i += ft_strlen(tmp) + 1;
			if (search_in_env(tmp, env))
				tmp = substitute_env(tmp, env, status);
			else
				tmp = ft_strdup("");
			res = ft_strjoin_null(tmp, res);
		}
		else if (str[i] != '$' && str[i] != '"')
		{
			tmp = extract_word_sep(&str[i], "$\"");
			i += ft_strlen(tmp);
			res = ft_strjoin_null(tmp, res);
		}
	}
	return (res);
}

char *handle_without_q(char *str, t_env_lst *env, int status)
{
	int i;
	char *tmp;
	char *res;
	
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
