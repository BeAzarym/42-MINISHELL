/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:20:02 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 17:53:31 by angassin         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
=======
<<<<<<< HEAD
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:25:33 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:19:56 by angassin         ###   ########.fr       */
=======
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/10/04 12:25:33 by cchabeau          #+#    #+#             */
/*   Updated: 2023/08/15 14:19:56 by angassin         ###   ########.fr       */
=======
<<<<<<<< HEAD:libft_calvin/ft_isalnum.c
/*   Created: 2022/10/04 12:25:33 by cchabeau          #+#    #+#             */
/*   Updated: 2022/10/20 11:39:26 by cchabeau         ###   ########.fr       */
<<<<<<< HEAD
========
/*   Created: 2023/05/25 17:34:10 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/16 16:27:32 by angassin         ###   ########.fr       */
=======
/*   Updated: 2023/08/10 11:29:20 by cchabeau         ###   ########.fr       */
>>>>>>> phoenix
>>>>>>>> merge ok, commented main.c and buggy code minishell.c:src/minishell.c
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
>>>>>>> 11d7b2b8f4e9c4c32f69e3c557b139a744cea52e
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
>>>>>>> Anaïs
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
<<<<<<< HEAD
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
	{
=======
<<<<<<< HEAD
	if (ft_isalpha(c) || ft_isdigit(c))
=======
<<<<<<<< HEAD:libft_calvin/ft_isalnum.c
	if (ft_isalpha(c) || ft_isdigit(c))
========
	t_tkn_lst	*stack;
	t_tkn_lst	*lst;
<<<<<<< HEAD
	t_env_lst *env_lst;
	char *res;
	char		**tab;
	int			i;
	int			x;
	(void)envp;
=======
	t_env_lst	*env_lst;
	t_cmd_node	*cmd;
	char		*res;

>>>>>>> phoenix
	(void)argv;
	(void)argc;
	lst = NULL;
	env_lst = init_envp(envp);
	cmd = init_cmd_node();
	if (!cmd)
>>>>>>>> merge ok, commented main.c and buggy code minishell.c:src/minishell.c
>>>>>>> merge ok, commented main.c and buggy code minishell.c
>>>>>>> Anaïs
		return (1);
	}
	return (0);
}
