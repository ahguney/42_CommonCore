/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:57:36 by bkeskint          #+#    #+#             */
/*   Updated: 2022/02/12 16:10:50 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<ctype.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include 	<fcntl.h> 

char	*get_next_line(int fd)
{
	int		rd;
	int		i;
	char	c;
	char	*buffer;

	i = 0;
	buffer = malloc(4096);
	while ((rd = read(fd, &c, 1) > 0))
	{
		buffer[i] = c;
		if (c == '\n')
			break;
		i++;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	buffer[i] = '\0';
	return (buffer);
}

/* You do not need main; it is just for testing*/

int main(void)
{	
	int		fd;
	// int		fd2;
	char	*str;

	// fd = open("GiveHereFilePATH", O_RDONLY);
	// fd2 = open("GiveHereFilePATH", O_RDONLY);
	for (size_t i = 0; i < 10; i++)
    {
        str = get_next_line(fd);
        printf("%s", str);
		free(str);
        // str = get_next_line(fd2);
        // printf("%s", str);
		// free(str);
    }
	printf("\n");
	close(fd);
	return (0);
}