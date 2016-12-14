/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:47:24 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/13 19:53:53 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

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
	if (empty != 0)
	{
		i = 5 * empty;
		ret = ft_strsub(buf, empty * 5, (4 - empty) * 5);
	}
	return (ret);
}


char	**buf_to_tab(char *buf)
{
	int		i;
	char	**ret;

	i = 0;
	buf = cut_whitelines(buf);
	return (ft_strsplit(buf, '\n'));
}

void	display_tab(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y += 1;
	}
}
