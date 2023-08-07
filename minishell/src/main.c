/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:10:33 by angassin          #+#    #+#             */
/*   Updated: 2023/08/07 16:09:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(char **argv, char	**envp)
{
	int		status;
	t_cmd	cmd;

	cmd.type_in = STDIN_OUT;
	cmd.type_out = STDIN_OUT;
	cmd.infile = NULL;
	cmd.outfile = NULL;
	cmd.cmd = &argv[1];

	execution(cmd, envp);
	// char	*cmd_line;

	// while (true)
	// {
	// 	status = 0;
	// 	cmd_line = readline("[Minishell] > ");
	// 	if (ft_strlen(cmd_line) > 0)
	// 		add_history(cmd_line);
	// 	printf("%s\n", cmd_line);
	// 	if (ft_strncmp(cmd_line, "cd", 2) == OK)
	// 		status = cd(cmd_line);
	// }
	return (status);
}
