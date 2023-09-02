/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:43:52 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:43:52 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse_export(t_shell *shell, int nb)
{
	int	i;

	if (shell->cmd[nb].nb_token == 1)
		ft_env(0);
	else
	{
		i = 0;
		while (++i < shell->cmd[nb].nb_token)
			ft_export(shell, shell->cmd[nb].token[i], 1);
	}
}

void	ft_parse_unset(t_shell *shell, int nb)
{
	int	i;

	i = 0;
	while (++i < shell->cmd[nb].nb_token)
		ft_unset(shell->cmd[nb].token[i]);
}

void	ft_exit(t_shell *shell, char *msg, int errno)
{
	ft_putstr_fd(msg, 2);
	ft_clear_command(shell);
	g_env = (char **)ft_free_array(g_env);
	rl_clear_history();
	exit(errno);
}

void	ft_init_shell(t_shell *shell, char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_memset(shell, 0, sizeof(t_shell));
	shell->expand[0] = 'a';
	shell->heredoc[0] = 'a';
	g_env = ft_remalloc(env, 0, 0);
	if (!g_env)
		ft_exit(shell, "Error: malloc failed\n", 1);
	ft_export_error(shell);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	ft_init_shell(&shell, env, ac, av);
	while (1)
	{
		ft_signal_on();
		shell.buffer = readline("\033[32;1m$ \033[0m");
		if (ft_parse(&shell) == 1)
		{
			ft_execute_cmd(&shell, 0);
		}
		ft_clear_command(&shell);
	}
	return (0);
}
