/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:29:17 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/04 17:05:52 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	deltetri(t_trimino **first)
{
	t_trimino *tmp;

	tmp = *first;
	if (tmp != NULL)
		deltetri(&(tmp->next));
	else
		free(*first);
	first = NULL;
}

void	display_tab(char **tab)
{
	int y;
	int x;

	y = 0;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x])
		{
			ft_putchar(tab[y][x]);
			x += 1;
		}
		ft_putchar('\n');
		y += 1;
	}
	ft_putchar('\n');
}
