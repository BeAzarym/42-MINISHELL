/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:05 by angassin          #+#    #+#             */
/*   Updated: 2023/10/09 09:23:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
	Checks if the infile is the stdin
	Otherwise, loops over all the infiles to check that they exist,
	if all valids, saves the last one in memory
	printf("get input\n");
	printf("redir_in == STDIN\n");
	printf("type of in : %c\n", cmd_table->type_in);
	printf("infile in get_input : %s\n", cmd_table->infile);
*/
int	get_input_output(t_cmd *cmd_table)
{
	t_redir_node	*in;

	in = cmd_table->redir_in->head;
	if (in == NULL)
		cmd_table->fdin = STDIN_FILENO;
	else if (in->type == HEREDOC)
		cmd_table->type_in = in->type;
	else
	{
		if (!can_access_infiles(cmd_table))
			return (EXIT_FAILURE);
		cmd_table->type_in = in->type;
		cmd_table->infile = ft_strdup(in->file);
	}
	if (get_outfile(cmd_table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cmd_table->type_in == INFILE)
		cmd_table->fdin = infile_open(cmd_table->infile);
	return (EXIT_SUCCESS);
}

/*
	cmd_table->outfile = out->file;
*/
int	get_outfile(t_cmd *cmd_table)
{
	t_redir_node	*out;

	out = cmd_table->redir_out->head;
	if (out == NULL)
		cmd_table->fdout = STDOUT_FILENO;
	else
	{
		while (out != NULL)
		{
			if (out->type == TRUNCATE)
				cmd_table->fdout = outfile_truncate_open(out->file);
			else if (out->type == APPEND)
				cmd_table->fdout = outfile_append_open(out->file);
			if (cmd_table->fdout == CLOSED)
				return (EXIT_FAILURE);
			out = out->next;
		}
	}
	return (EXIT_SUCCESS);
}
