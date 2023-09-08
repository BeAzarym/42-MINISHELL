/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:18:52 by angassin          #+#    #+#             */
/*   Updated: 2023/09/08 17:19:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	read_stdin(const char *limiter, int fd);

/*
	printf("in heredoc\n"); 
*/
void	heredoc(t_cmd_lst *cmd_table)
{
	int				pid;
	t_redir_node	*in;

	in = cmd_table->head->redir_in->head;
	while (in->type == HEREDOC)
	{
		pid = fork();
		if (pid == -1)
			error_exit("could not create here_doc process");
		cmd_table->head->limiter = in->file;
		cmd_table->head->fdin = outfile_truncate_open("/tmp/.heredoc.tmp");
		if (pid == CHILD)
		{
			read_stdin(cmd_table->head->limiter, cmd_table->head->fdin);
			close(cmd_table->head->fdin);
		}
		free(cmd_table->head->infile);
		cmd_table->head->infile = ft_strdup("/tmp/.heredoc.tmp");
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