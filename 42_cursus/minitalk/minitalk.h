/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahguney <ahguney@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:44:42 by ahguney           #+#    #+#             */
/*   Updated: 2022/06/04 13:44:44 by ahguney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PIDERROR "PID numarasını ve mesajınızı girin!\n"
# define ARGERROR "Argüman sayısı yanlış!\n"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

char	*ft_itoa(int n);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char const s2);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);

#endif
