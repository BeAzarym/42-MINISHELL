/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:10:33 by angassin          #+#    #+#             */
/*   Updated: 2023/08/07 11:53:01 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	int		status;
	char	*cmd_line;

	while (true)
	{
		status = 0;
		cmd_line = readline("[Minishell] > ");
		if (ft_strlen(cmd_line) > 0)
			add_history(cmd_line);
		printf("%s\n", cmd_line);
		if (ft_strncmp(cmd_line, "cd", 2) == OK)
			status = cd(cmd_line);
	}
	return (status);
}
