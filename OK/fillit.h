/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:38:54 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/13 17:12:18 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>

typedef	struct	s_trimino
{
	char				**piece;
	int					y;
	int					x;
	struct s_trimino	*next;
}				t_trimino;

int		validtetri(char *buf);
int		test(char *buf);
char	*cut_whitecolumns(char *buf, int lines);
char	*cut_whitelines(char *buf);
char	**buf_to_tab(char *buf);
int		add_to_list(t_trimino **head, char *buf);

#endif
