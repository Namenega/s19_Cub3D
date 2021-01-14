/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:57:45 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 15:10:49 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** LIBFT FUNCTIONS_1
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_isspace(int c);
void		ft_bzero(void *b, size_t len);
int			ft_atoi(const char *s);

/*
** LIBFT FUNCTIONS_2
*/

int			ft_inset(int c, char *set);
int			ft_isdigit(int c);
int			ft_next_arg(char *l);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);

/*
** LIBFT FUNCTIONS_3
*/

int			ft_next_arg_2(char *l);

char		*ft_strtrim(char const *s1, char const *set);

#endif