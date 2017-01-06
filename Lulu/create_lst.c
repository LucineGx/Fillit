/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:13:54 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/06 19:43:21 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*cut_white_lines(char *buf)
{
	int		i;
	int		j;
	int		empty;

	i = 0;
	j = 0;
	empty = 0;
	while (i < 15)
	{
		if (buf[i] == '.' && buf[i + 1] == '.'
				&& buf[i + 2] == '.' && buf[i + 3] == '.')
		{
			i += 5;
			empty += 1;
		}
		else
			i = 15;
	}
	return (ft_strsub(buf, empty * 5, (4 - empty) * 5));
}

char	**buf_to_tab(char *buf, char letter)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			buf[i] = letter;
		i += 1;
	}
	return(ft_strsplit(cut_white_lines(buf), '\n'));
}

t_trimino	*newtetri(char **piece, t_trimino **head, t_trimino *lst)
{
	int y;
	int x;

	if ((lst = malloc(sizeof(t_trimino))) == 0)
		return (0);
	lst->piece = piece;
	y = 0;
	while (piece[y])
		y += 1;
	lst->y = (piece == NULL) ? 0 : y;
	x = 0;
	while (piece[0][x])
		x += 1;
	lst->x = (piece == NULL) ? 0 : x;
	lst->next = *head;
	*head = lst;
	return (lst);
}
