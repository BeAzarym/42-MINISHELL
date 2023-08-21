/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_put_unbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:48 by angassin          #+#    #+#             */
/*   Updated: 2023/08/14 14:24:43 by cchabeau         ###   ########.fr       */
=======
<<<<<<< HEAD
<<<<<<< HEAD
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
=======
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:17:23 by cchabeau          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/06/24 19:22:34 by cchabeau         ###   ########.fr       */
=======
/*   Updated: 2022/11/04 15:57:43 by cchabeau         ###   ########.fr       */
>>>>>>> merge ok, commented main.c and buggy code minishell.c
=======
/*   Updated: 2023/06/24 19:22:34 by cchabeau         ###   ########.fr       */
>>>>>>> aa0ee6d47bc72e27cf4d9e385551ba86e312b03b
>>>>>>> Anaïs
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Recursive function to display an unsigned number in the given base
void	ft_put_unbr_base_fd(unsigned long n, char *base, int fd)
{
	unsigned int	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_put_unbr_base_fd(n / base_len, base, fd);
		ft_put_unbr_base_fd(n % base_len, base, fd);
	}
	if (n < base_len)
		ft_putchar_fd(base[n], fd);
}
