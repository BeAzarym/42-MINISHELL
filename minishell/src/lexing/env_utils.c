/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:57:11 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/24 16:39:38 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_lst	*init_env_lst(void)
{
	t_env_lst	*lst;

	lst = malloc(sizeof(t_env_lst));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return (lst);
}

t_env_lst	*add_lst_env(char *key, char *value, t_env_lst *lst)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	if (!new->key || (value != NULL && !new->value))
		return (NULL);
	new->next = NULL;
	if (!lst->head)
	{
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		lst->tail = new;
	}
	lst->size++;
	return (lst);
}

char	**envp_split(char *str)
{
	int		i;
	int		j;
	char	**array;
	int		len;

	array = malloc(sizeof(char *) * 3);
	if (!array)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	j = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	array[j] = ft_substr(str, 0, i);
	if (!array[j])
		return (NULL);
	j++;
	array[j] = ft_substr(str, i + 1, len);
	if (!array[j])
		return (NULL);
	j++;
	array[j] = NULL;
	return (array);
}

int	search_in_env(char *key, t_env_lst *env)
{
	t_env	*cpy;

	if (!key || !env)
		return (-1);
	cpy = env->head;
	while (cpy)
	{
		if (ft_strncmp(key, "?", ft_strlen(key)) == 0)
			return (1);
		if (ft_strncmp(key, cpy->key, ft_strlen(key)) == 0)
			return (1);
		cpy = cpy->next;
	}
	return (0);
}
