/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qhote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:45:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/09/18 15:19:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	set_status_true(int *dq_status, int index)
{
	*dq_status = 1;
	return (index + 1);
}

int	verify_closed_quotes(char *str)
{
	int	i;
	int d_qh;
	int s_qh;

	d_qh = 0;
	s_qh = 0;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '"' && !d_qh) && !s_qh)
			i = set_status_true(&d_qh, i);
		if ((str[i] == '"' && d_qh) && !s_qh)
			d_qh = 0;
		if ((str[i] == '\'' && !s_qh) && !d_qh)
			i = set_status_true(&s_qh, i);
		if ((str[i] == '\'' && s_qh) && !d_qh)
			s_qh = 0;
		i++;
	}
	if (!s_qh && !d_qh)
		return (1);
	return (-1);
}
