/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:31:46 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/04 16:27:18 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	displaytetri(t_trimino **first)
{
	t_trimino *tmp;
	tmp = *first;
	if (tmp != NULL)
	{
		displaytetri(&(*tmp).next);
		display_tab((*tmp).piece);
	}
}
