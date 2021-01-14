/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:41:43 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 17:16:10 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_error_sky_4(char *line)
{
	int	i;

	i = 0;
	if (line[i])
	{
		while (line[i])
		{
			if (!ft_isspace(line[i]))
				ft_error_exit("Error\nToo many arguments(R).\nExit Program");
			i++;
		}
	}
}

void		ft_error_sky_3(char *line)
{
	if (!(*line))
		ft_error_exit("Error\nMissing an argument(C).\nExit Program");
	while (ft_isspace(*line) || *line == ',')
		line++;
	if (!ft_isdigit(*line))
		ft_error_exit("Error\nMissing an argument(C).\nExit Program");
}

void		ft_error_sky_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			ft_error_exit("Error\nOnly digits & whitespaces allowed(C).\n\
Exit Program");
		i++;
	}
}

int			ft_color_sky(t_data *data, char *line)
{
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sky_1(line);
	data->r_sky = ft_atoi(line);
	printf("r_sky = [%d]\n\n\n", data->r_sky);
	line += ft_next_arg_2(line);

	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sky_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->g_sky = ft_atoi(line);
	printf("g_sky = [%d]\n\n\n", data->g_sky);
	line += ft_next_arg_2(line);

	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sky_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->b_sky = ft_atoi(line);
	printf("b_sky = [%d]\n\n\n", data->b_sky);

	line += ft_next_arg_2(line);
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sky_4(line);

	if (!data->r_sky || !data->g_sky || !data->b_sky)
		return (0);
	return (1);
}
