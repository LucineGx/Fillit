/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:19:15 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/06 18:32:48 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_line(char **sudoku, int posicas, int val);

int	check_column(char **sudoku, int posicas, int val);

int	check_cell(char **sudoku, int i, int j, char val);


char	**solve_sudoku(char **sudoku, int posicase, char **solution)
{
	char	valcase;
	if (posicase == 81)
	{
      if (solution[0][0] == '0')
		  solution = sudoku;
	  else
			solution[0][0] = '!';
	}
	else if (sudoku[posicase / 9][posicase % 9] != '.')
		solution = solve_sudoku(sudoku, posicase + 1, solution);
	else
	{
		valcase = '1';
		while (valcase <= '9')
		{
			if ((check_line(sudoku, posicase, valcase) == 1)
			    && (check_column(sudoku, posicase, valcase) == 1)
			    && (check_cell(sudoku, (posicase / 9), (posicase % 9), valcase) == 1))
			{
				sudoku[posicase / 9][posicase % 9] = valcase;
				solution = solve_sudoku(sudoku, posicase + 1, solution);
			}
			valcase++;
		}
		sudoku[posicase / 9][posicase % 9] = '.';
	}
	return (solution);
}
