/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:38:54 by lgaveria          #+#    #+#             */
/*   Updated: 2017/01/06 17:34:46 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_trimino
{
	char				**piece;
	int					y;
	int					x;
	struct s_trimino	*next;
}				t_trimino;

int			validtetri(char *buf);
int			test(char *buf, t_trimino *head);
char		*cut_white_lines(char *buf);
char		**buf_to_tab(char *buf, char letter);
t_trimino	*newtetri(char **piece, t_trimino **head, t_trimino *lst);
void		deltetri(t_trimino **first);
void		display_tab(char **tab);
void		displaytetri(t_trimino **first);

char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		**ft_strsplit(char const *s, char c);
void		ft_putchar(char c);

#endif
