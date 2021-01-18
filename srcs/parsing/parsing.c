/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 19:00:07 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_parsing_data(char *line, t_data *data)
{
	if (!line)
		return (0);
	else if (line[0] == 0)
		return (1);
	else if (line[0] == 'R' && ft_isspace(line[1]))
		return (ft_resolution(data, &line[1]));
	else if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_north(data, &line[2]));
	else if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return (ft_south(data, &line[2]));
	else if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
		return (ft_west(data, &line[2]));
	else if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
		return (ft_east(data, &line[2]));
	else if (line[0] == 'S' && ft_isspace(line[1]))
		return (ft_sprite(data, &line[1]));
	else if ((line[0] == 'F') && ft_isspace(line[1]))
		return (ft_color_ground(data, &line[1]));
	else if ((line[0] == 'C') && ft_isspace(line[1]))
		return (ft_color_sky(data, &line[1]));
	else
		ft_error_exit("Error\nA line is wrong in the .cub\nExit Program");

	/*
	** if 'SO' = 'S O' -> conflit avec 'S'-> error 'S'
	** si tout n'existe qu'une seule fois ok
	**		si il manque un truc pas ok
	**		si il y a 2x un truc pas ok
	*/
	return (1);
}

int		ft_gnl(int fd, char *line, t_data *data)
{
	int		res;
	int		compteur;

	res = 0;
	compteur = 0;
	printf("\ndata->width = [%d]\n", data->width);
	printf("\ndata->height = [%d]\n", data->height);
	printf("\ndata->path_sprite = [%s]\n", data->path_sprite);
	printf("\ndata->path_north = [%s]\n", data->path_north);
	printf("\ndata->path_south = [%s]\n", data->path_south);
	printf("\ndata->path_west = [%s]\n", data->path_west);
	printf("\ndata->path_east = [%s]\n", data->path_east);
	printf("\ndata->r_ground = [%d]\n", data->r_ground);
	printf("\ndata->g_ground = [%d]\n", data->g_ground);
	printf("\ndata->b_ground = [%d]\n", data->b_ground);
	printf("\ndata->r_sky = [%d]\n", data->r_sky);
	printf("\ndata->g_sky = [%d]\n", data->g_sky);
	printf("\ndata->b_sky = [%d]\n", data->b_ground);
	while (get_next_line(fd, &line))
	{
		res = 1;
		ft_parsing_data(line, data);
		free(line);
	}
	return (res);
}

int		ft_get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nTask - Reading File : Fail_1!", 1);
		return (0);
	}
	res = ft_gnl(fd, line, data);
	/* while (get_next_line(fd, &line))
	{
		res = 1;
		ft_parsing_data(line, data);
		free(line);
	} */
	free(line);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}

t_data	*ft_data(char *file, int ac)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_bzero(data, sizeof(t_data));
	if (ac == 1)
		if ((data->mlx_ptr = mlx_init()) == NULL)
			return (0);
	if (!(ft_get_data(data, file)))
		ft_free_data(data, "Error\nTask - parsing : Fail_2 !");
	if (ac == 1)
		if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "CUB3D")) == NULL)
			ft_free_data(data, "Error\nTask - parsing : Fail_3 !");
	return (data);
}

	// printf("no error here (1)\n");
	// printf("no error here (2)\n");
	// printf("no error here (3)\n");
	// printf("no error here (4)\n");
	// printf("no error here (5)\n");
	// printf("no error here (6)\n");
	// printf("no error here (7)\n");
	// printf("no error here (8)\n");
	// printf("no error here (9)\n");