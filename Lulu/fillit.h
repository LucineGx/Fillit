/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:38:54 by lgaveria          #+#    #+#             */
/*   Updated: 2016/12/14 19:21:34 by lgaveria         ###   ########.fr       */
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

int			validtetri(char *buf);
int			test(char *buf);
t_trimino	*newtetri(char **piece, t_trimino **head, t_trimino *lst);
void		deltetri(t_trimino **first);
char		*cut_whitelines(char *buf);
char		**buf_to_tab(char *buf);
void		display_tab(char **tab);

#endif
