/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:57:45 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 16:14:22 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** LIBFT FUNCTIONS
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_isspace(int c);
void		ft_bzero(void *b, size_t len);

#endif