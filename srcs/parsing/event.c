/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:28:35 by namenega          #+#    #+#             */
/*   Updated: 2021/02/03 19:14:34 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_keyrelease_hook(int key, t_global *glb)
{
	(void)glb;
	if(key == KEYCODE_ESC)
		ft_error_exit(" ------------------------ \n|Merci pour les services.|\n ------------------------ ");
	// if(key == KEYCODE_RIGHTARROW)
	// 	ft_rotate_right(glb->pos, glb);
	// if(key == KEYCODE_LEFTARROW)
	// 	ft_rotate_left(glb->pos);
	return (0);
}

int		ft_keypress_hook(int key, t_global *glb)
{
	if(key == KEYCODE_ESC)
	{
		ft_error_exit(" ------------------------ \n|Merci pour les services.|\n ------------------------ ");
	}
	if (key == KEYCODE_W)
	{
		// printf("dvv\n");
		ft_mvforward(glb->pos, glb->map);
		// ft_affichage(glb);
		mlx_put_image_to_window(glb->data->mlx_ptr, glb->data->mlx_win, glb->data->img, 0, 0);
	}
	// if(key == KEYCODE_RIGHTARROW)
	// {
	// 	ft_rotate_right(glb->pos, glb);
	// }
	// if(key == KEYCODE_LEFTARROW)
	// 	ft_rotate_left(glb->pos);
	return (0);
}

int		ft_exit_hook(void *x)
{
	ft_free_data(((t_data*)x), "Close Window !\n");
	ft_error_exit("Merci pour les services.");
	return (0);
}

int		ft_test(t_global *glb)
{
	int key;

	key = 0;
	// ft_mlx_data(glb->data);
	ft_keypress_hook(key, glb);
	ft_keyrelease_hook(key, glb);
	ft_affichage(glb);
	//printf("_____[%p]\n", glb->data->img);
	mlx_put_image_to_window(glb->data->mlx_ptr, glb->data->mlx_win, glb->data->img, 0, 0);
	// ft_affichage(glb);
	// mlx_put_image_to_window(glb->data->mlx_ptr, glb->data->mlx_win, glb->data->img, 0, 0);
	return (1);
}

int		hook_loop(t_global *glb)
{
	// if (ac == 1)
	mlx_hook(glb->data->mlx_win, XEVENT_KEYPRESS, 0, &ft_keypress_hook, (void *)glb);
	mlx_hook(glb->data->mlx_win, XEVENT_KEYRELEASE, 0, &ft_keyrelease_hook, (void *)glb);
	mlx_hook(glb->data->mlx_win, XEVENT_EXIT, 0, &ft_exit_hook, (void *)glb);
	mlx_loop_hook(glb->data->mlx_ptr, &ft_test, (void *)glb);
	mlx_loop(glb->data->mlx_ptr);
	return (1);
}

// int		ft_event(t_global *glb)
// {
// 	// mlx_hook(data->mlx_win, 17, 0, ft_exit_hook, (void*)data);
// 	// mlx_key_hook(data->mlx_win, ft_key, (void*)data);
// 	printf("evbesv\n");

// 	// mlx_hook(glb->data->mlx_win, XEVENT_KEYPRESS, 0, &ft_keypress_hook, (void *)glb);
// 	// mlx_hook(glb->data->mlx_win, XEVENT_KEYRELEASE, 0, &ft_keyrelease_hook, (void *)glb);
// 	// mlx_hook(glb->data->mlx_win, XEVENT_EXIT, 0, &ft_exit_hook, (void *)glb);
// 	// mlx_loop(glb->data->mlx_ptr);
// 	return (0);
// }
