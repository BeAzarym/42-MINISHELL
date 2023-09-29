/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:05 by angassin          #+#    #+#             */
/*   Updated: 2023/09/29 11:52:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
	Check if the infile is the stdin
	Otherwise, loops over all the infiles to check that they exist,
	if all valids, save the last one in memory
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
	get_outfile(cmd_table);
	if (cmd_table->type_in == INFILE)
		cmd_table->fdin = infile_open(cmd_table->infile);
	return (EXIT_SUCCESS);
}
