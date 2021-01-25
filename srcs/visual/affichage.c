/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/25 15:07:08 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Jumping to next square (or x/y direction)
*/

// void		ft_move_square(t_move *move)
// {
// 	while (move->hit == 0)
// 	{
// 		if (move->side_dist.x < move->side_dist.y)
// 		{
// 			move->side_dist.x += move->d_dist.x;
// 			move->map.x += move->step.x;
// 			move->side = 0;
// 		}
// 		else
// 		{
// 			move->side_dist.y += move->d_dist.y;
// 			move->map.y += move->step.y;
// 			move->side = 1;
// 		}
// 	}
// }

/*
** Calculate step and initial side_dist
*/

// void		ft_condition_ray(t_ray *ray, t_move *move, t_pos *posi)
// {
// 	if (ray->dir.x < 0)
// 	{
// 		move->step.x = -1;
// 		move->side_dist.x = (posi->pos.x - move->map.x) * move->d_dist.x;
// 	}
// 	else
// 	{
// 		move->step.x = 1;
// 		move->side_dist.x = (move->map.x + 1.0 - posi->pos.x) * move->d_dist.x;
// 	}
// 	if (ray->dir.y < 0)
// 	{
// 		move->step.y = -1;
// 		move->side_dist.y = (posi->pos.y - move->map.y) * move->d_dist.y;
// 	}
// 	else
// 	{
// 		move->step.y = 1;
// 		move->side_dist.y = (move->map.y + 1.0 - posi->pos.y) * move->d_dist.y;
// 	}
// }

void		ft_start_position(/*t_pos *posi, */t_ray *ray, t_map *map/*, t_data *data*/)
{
	t_move		*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return ;
	ft_init_move(move, ray, map);
	printf("----------\nmove->map.x = [%f]\n----------\n", move->map.x);
	// ft_condition_ray(ray, move, posi);
	// ft_move_square(move);
	// //check if ray has hit a wall
	// if (map->real_map[(int)move->map.x][(int)move->map.y] > 0)
	// 	move->hit = 1;
	// //calc the distance projected on camera direction (w/o fisheye effect)
	// if (move->side == 0)
	// 	move->perp_wall_dist = (move->map.x - posi->pos.x + (1 - move->step.x) / 2) /
	// 		ray->dir.x;
	// else
	// 	move->perp_wall_dist = (move->map.y - posi->pos.y + (1 - move->step.y) / 2) /
	// 		ray->dir.y;
	// //calc height of line to draw on screen
	// move->line_h = (int)(data->height / move->perp_wall_dist);
	// //calc lowest and highest pixel to fill in current stripe
	// move->draw_start = (-move->line_h / 2) + (data->height / 2);
	// if (move->draw_start < 0)
	// 	move->draw_start = 0;
	// move->draw_end = (move->line_h / 2) + (data->height / 2);
	// if (move->draw_end >= data->height)
	// 	move->draw_end = data->height - 1;
	// //choose wall color


}

int			ft_affichage(t_map *map, t_data *data)
{
	int			i;
	t_pos		*pos;
	t_ray		*ray;

	i = 0;
	pos = (t_pos*)malloc(sizeof(t_pos));
	if (!pos)
		return (0);
	ray = (t_ray*)malloc(sizeof(t_ray));
	if (!ray)
		return (0);
	ft_init_pos_vec(pos);
	printf("----------\ntest_1\n----------\n");
	while (i < data->width)
	{
		// calculate ray position & direction
		pos->camera.x = 2 * (double)i / (double)data->width - 1;
		ray->dir.x = pos->dir.x + (pos->plane_cam.x * pos->camera.x);
		ray->dir.y = pos->dir.y + (pos->plane_cam.y * pos->camera.y);
		i++;
	}
	printf("----------\ntest_2\n----------\n");
	ft_start_position(/*pos, */ray, map/*, data*/);
	return (1);
}
