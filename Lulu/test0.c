/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:31:46 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/14 21:49:19 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void	displaytetri(t_trimino **first)
{
	t_trimino *tmp;
	while (tmp != NULL)
		displaytetri(&(*tmp).next);
	display_tab((*tmp).piece);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*buf;
	t_trimino	*lst;
	t_trimino	*head;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1)
		write(1, "error\n", 6);
	if ((buf = (char*)malloc(sizeof(char) * 22)) == 0)
		return (0);
	head = NULL;
	while ((read(fd, buf, 21)))
	{
		if (!(test(buf)))
		{
			deltetri(&lst);
			free(buf);
			return (0);
		}
		buf_to_tab(buf);
//		lst = newtetri(buf_to_tab(buf), &head, lst);
	}
//	displaytetri(&head);
	return (0);
}
