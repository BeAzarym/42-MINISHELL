/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:35:24 by angassin          #+#    #+#             */
/*   Updated: 2023/08/07 16:37:24 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execution(t_cmd *cmd, char **envp)
{
	int i;
	int j;
	int	fdin;
	int	fdout;

	// if (cmd->type_in == HEREDOC)
	// 	heredoc(cmd->cmd[2]);
	// else 
	if (cmd->type_in == INFILE)
	{
		fdin = infile_open(cmd->cmd[1]);
		duplicate(fdin, STDIN_FILENO, "duplication of the infile failed");
	}
	else
		fdin = STDIN_FILENO;
	if (cmd->type_out == TRUNCATE)
		fdout = outfile_truncate_open(cmd->outfile);
	else if (cmd->type_out == APPEND)
		fdout = outfile_append_open(cmd->outfile);
	else
		fdout = STDOUT_FILENO;
	
}