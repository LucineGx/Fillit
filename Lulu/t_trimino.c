/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_trimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:01:00 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/14 19:23:59 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

t_trimino	*newtetri(char **piece, t_trimino **head, t_trimino *lst)
{
	int			y;
	int			x;

	if ((lst = malloc(sizeof(t_trimino))) == 0)
		return (0);
	lst->piece = piece;
	if (piece == NULL)
	{
		lst->x = 0;
		lst->y = 0;
	}
	if (piece != NULL)
	{
		y = 0;
		while (piece[y])
			y += 1;
		lst->y = y;
		x = 0;
		while (piece[0][x])
			x += 1;
		lst->x = x;
	}
	lst->next = *head;
	*head = lst;
	return (lst);
}

void		deltetri(t_trimino **first)
{
	t_trimino *tmp;

	tmp = *first;
	if (tmp ->next != NULL)
		deltetri(&(*tmp).next);
	free((*first)->piece);
	free(*first);
	*first = NULL;
}
