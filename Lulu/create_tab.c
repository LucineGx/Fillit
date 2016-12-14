/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:24 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/14 21:49:16 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"
#include <stdio.h>

char	*cut_whitelines(char *buf)
{
	int		i;
	int		j;
	int		empty;
	char	*ret;

	i = 0;
	j = 0;
	while ( i < 15)
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
	if ((ret = malloc(sizeof(char) * ((4 - empty) * 5 + 1))) == 0)
		return (0);
	if (empty != 0)
		ret = ft_strsub(buf, empty * 5, (4 - empty) * 5);
	else
		ret = ft_strdup(buf);
	return (ret);
}


char	**buf_to_tab(char *buf)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(cut_whitelines(buf), '\n');
	display_tab(tab);
	return (tab);
}

void	display_tab(char **tab)
{
	int y;
	int x;

	y = 0;
	if (!tab)
		ft_putstr("pas ok du tout\n");
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
