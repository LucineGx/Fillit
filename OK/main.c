/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:31:46 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/13 17:16:28 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

int		validtetri(char *buf)
{
	int	i;
	int	connections;
	int	blocs;

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
	}
	if (blocs != 4 || connections < 6)
		return (0);
	return (1);
}

int		test(char *buf)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else
			if (!(buf[i] == '.' || buf[i] == '#'))
				return (0);
		i += 1;
	}
	if (!(i == 19 || (i == 20 && buf[i] == '\n')))
		return (0);
	if (!(validtetri(buf)))
		return (0);
	return (1);
}

int		add_to_list(t_trimino **head, char *buf)
{
	t_trimino	*newtetri;
	char		**piece;
	int			x;
	int			y;

	if (!(test(buf)) || ((x = 0)) || ((y = 0)))
		return (0);
	if ((newtetri = (t_trimino*)malloc(sizeof(t_trimino))) == 0)
		return (0);
	piece = buf_to_tab(buf);
	newtetri->piece = piece;
	while (piece[y])
		y += 1;
	newtetri->y = y;
	while (piece[0][x])
		x += 1;
	newtetri->x = x;
	newtetri->next = *head;
	*head = newtetri;
	return (1);
}


int		main(int ac, char **av)
{
	int			fd;
	char		*buf;
	t_trimino	**first;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
		write(1, "error\n", 6);
	if ((buf = (char *)malloc(sizeof(char) * 21)) == 0)
		return (0);
	*first = NULL;
	while (read(fd, buf, 21))
	{
		if (!(add_to_list(&(*first), buf)))
			//free
