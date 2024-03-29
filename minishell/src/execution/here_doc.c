/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:18:52 by angassin          #+#    #+#             */
/*   Updated: 2023/10/05 12:52:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	read_stdin(const char *limiter, int fd);

/*
	Creates a child process to prompt the user.
	Stores the user input in a temporary file. 
	printf("in heredoc\n"); 
*/
void	heredoc(t_cmd *cmd_table)
{
	int				pid;
	t_redir_node	*in;

	set_heredoc_signals(PARENT_H);
	in = cmd_table->redir_in->head;
	while (in->type == HEREDOC)
	{
		pid = fork();
		if (pid == -1)
			error_exit("could not create here_doc process");
		cmd_table->limiter = in->file;
		cmd_table->fdin = outfile_truncate_open("/tmp/.heredoc.tmp");
		if (pid == CHILD)
		{
			set_heredoc_signals(CHILD_H);
			read_stdin(cmd_table->limiter, cmd_table->fdin);
			close(cmd_table->fdin);
		}
		free(cmd_table->infile);
		cmd_table->infile = ft_strdup("/tmp/.heredoc.tmp");
		wait(NULL);
		if (in->next == NULL)
			break ;
		in = in->next;
	}
}

//printf("\nline : %s in read_stdin\n", line);
//printf("exit read_stdin\n");
static void	read_stdin(const char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit(127);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == OK
			&& ft_strlen(limiter) == (ft_strlen(line) - 1))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
}
