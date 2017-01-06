/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:43:49 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/06 19:43:18 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		placement_ok(char **square, char **piece, int posicase);
char	**site_piece(char **square, char **piece, int posicase);

char	**solvfillit(char **square, t_trimino *current,
		char **solution, int squarsize)
{
	int		posicase;
	char	**tmp;

	if (current == NULL)
		return(square);
	posicase = 0;
	tmp = square;
	while (posicase < squarsize * squarsize)
	{
		if (placement_ok(square, current->piece, posicase))
		{
			square = site_piece(square, current->piece, posicase);
			solution = solvfillit(square, current->next, solution, squarsize);
			square = tmp;
		}
		posicase += 1;
	}
	return (solution);
}
