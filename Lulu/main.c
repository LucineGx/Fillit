/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:51:37 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/06 17:34:53 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validtetri(char *buf)
{
	int i;
	int connections;
	int blocs;

	i = 0;
	connections = 0;
	blocs = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			blocs += 1;
			connections += (buf[i - 1] == '#' && i - 1 >= 0) ? 1 : 0;
			connections += (buf[i + 1] == '#' && i + 1 <= 18) ? 1 : 0;
			connections += (buf[i - 5] == '#' && i - 5 >= 0) ? 1 : 0;
			connections += (buf[i + 5] == '#' && i + 5 <= 18) ? 1 : 0;
		}
		i += 1;
	}
	if (blocs != 4 || connections < 6)
		return (0);
	return (1);
}

int		test(char *buf, t_trimino *head)
{
	int i;
	int err;

	i = 0;
	err = 1;
	while (i < 20)
	{
		if (i % 5 == 4)
			err = (buf[i] != '\n') ? 0 : err;
		else
			err = (buf[i] == '.' || buf[i] == '#') ? err : 0;
		i += 1;
	}
	err = (i == 19 || (i == 20 && buf[i] == '\n')) ? err : 0;
	err = (validtetri(buf)) ? err : 0;
	if (err == 0)
	{
		deltetri(&head);
		free(buf);
		write(1, "error\n", 6);
	}
	return (err);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*buf;
	t_trimino	*lst;
	t_trimino	*head;
	char		letter;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || (buf = (char*)malloc(sizeof(char) * 22)) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	head = NULL;
	letter = 'A';
	while ((read(fd, buf, 21)))
	{
		if (!(test(buf, head)))
			return (0);
		lst = newtetri(buf_to_tab(buf, letter), &head, lst);
		letter++;
	}
	displaytetri(&head);
	return (0);
}
