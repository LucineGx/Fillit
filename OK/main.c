/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:51:37 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/05 16:45:15 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	displaytetri(t_trimino **first);

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

int		test(char *buf)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else
		{
			if (!(buf[i] == '.' || buf[i] == '#'))
				return (0);
		}
		i += 1;
	}
	if (!(i == 19 || (i == 20 && buf[i] == '\n')))
		return (0);
	if (!(validtetri(buf)))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*buf;
	t_trimino	*lst;
	t_trimino	*head;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((buf = (char*)malloc(sizeof(char) * 22)) == 0)
		return (0);
	head = NULL;
	while ((read(fd, buf, 21)))
	{
		if (!(test(buf)))
		{
			deltetri(&head);
			free(buf);
			write(1, "error\n", 6);
			return (0);
		}
		lst = newtetri(buf_to_tab(buf), &head, lst);
	}
	return (0);
}
