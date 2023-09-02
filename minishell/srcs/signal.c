/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:43:52 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:43:52 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_interactive(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
		rl_redisplay();
}

void	ft_signal_on(void)
{
	signal(SIGINT, ft_interactive);
	signal(SIGQUIT, ft_interactive);
}

void	ft_clear_command(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->nb_cmd)
		ft_free(shell->cmd[i].save);
	shell->cmd = ft_free(shell->cmd);
	shell->pid = ft_free(shell->pid);
	shell->buffer = ft_free(shell->buffer);
	shell->nb_cmd = 0;
	ft_clear_fd();
}
