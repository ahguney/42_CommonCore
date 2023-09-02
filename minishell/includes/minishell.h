/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:50:51 by ahguney           #+#    #+#             */
/*   Updated: 2023/01/12 12:50:55 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include "readline.h"
# include "history.h"
# include "rlstdc.h"
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>

typedef struct t_cmd
{
	char	*buffer;
	char	**token;
	char	**save;
	int		nb_token;
	int		fd;
	int		open_error;
}					t_cmd;

typedef struct t_shell
{
	char	*buffer;
	int		nb_cmd;
	pid_t	*pid;
	t_cmd	*cmd;
	char	expand[2];
	char	heredoc[2];
	int		error;

}					t_shell;

char	**g_env;

int		ft_parse(t_shell *shell);
int		ft_buffer_integrity(t_shell *shell);
char	*ft_get_variable(char *buffer, int flag);
int		ft_find_redirect(t_shell *shell, int nb);
void	ft_clean_token(t_shell *shell, char **token);
void	ft_execute_cmd(t_shell *shell, int nb);
void	ft_parse_export(t_shell *shell, int nb);
void	ft_parse_unset(t_shell *shell, int nb);
void	ft_execve(t_shell *shell, int nb);
int		ft_open(t_cmd *cmd, char *str, int i);
void	ft_clear_command(t_shell *shell);

void	ft_env(int flag);
void	ft_unset(char *buffer);
void	ft_export(t_shell *shell, char *arg, int flag);
void	ft_cd(t_shell *shell, char *buffer);
void	ft_echo(char **arg);

void	ft_signal_off(void);
void	ft_signal_on(void);

void	ft_exit(t_shell *shell, char *msg, int errno);
void	ft_unlink_heredoc(t_shell *shell);
void	ft_export_error(t_shell *shell);

int		ft_array_size(char **array);
void	**ft_free_array(char **array);
void	*ft_free(void *ptr);
int		ft_isalpha(int nbr);
void	ft_putstr_fd(char *s, int fd);
char	**ft_remalloc(char **old, int size, int f);
char	*ft_strchr(const char *str, int nbr);
char	*ft_strjoin(char *s1, char const *s2, int f);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *src, unsigned int start, size_t len);
int		ft_check_closed_quote(char *buf);
void	ft_clear_fd(void);
int		ft_close_fd(int fd);
bool	ft_is_only(char *buffer, char c);
int		ft_pipe_check(char *buf);
char	**ft_split(char *src, char sep);
char	*ft_strtok(char *buffer, char sep);
char	*ft_trim_token(char *token, char sep);
char	*ft_strdup(const char *src);
void	*ft_memset(void *str, int nbr, size_t len);
int		ft_open_fd(char *str, int i);
int		ft_token_count(char *buffer, char sep);
void	*ft_calloc(size_t nbr, size_t size);
int		ft_isalnum(int nbr);
char	*ft_remove_char(char *token, char sep);
char	*ft_itoa(int nbr);
void	ft_bzero(void *str, size_t len);
void	ft_putstr(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	ft_putchar(char src);
int		ft_split_size(char *src, char sep);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
