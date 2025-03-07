/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:11:01 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/06 00:11:25 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	init_th_box(char **map)
{
	box()->map = map;
	box()->mlx = mlx_init();
	box()->width = ft_strlen(map[0]) * 32;
	box()->hight = export_y(map) * 32 + 32;
	box()->win = mlx_new_window(box()->mlx, box()->width, box()->hight, "so_long");
}

void	init_wall()
{
	int garbage;
	
	wall()->img_top = mlx_xpm_file_to_image(box()->mlx, "./textures/top.xpm",  &garbage, &garbage);
	wall()->img_left = mlx_xpm_file_to_image(box()->mlx, "./textures/left.xpm", &garbage, &garbage);;
	wall()->img_right = mlx_xpm_file_to_image(box()->mlx, "./textures/right.xpm", &garbage, &garbage);
	wall()->img_normal = mlx_xpm_file_to_image(box()->mlx, "./textures/block00.xpm", &garbage, &garbage);
	wall()->img_tright = mlx_xpm_file_to_image(box()->mlx, "./textures/topright.xpm", &garbage, &garbage);
	wall()->img_tleft = mlx_xpm_file_to_image(box()->mlx, "./textures/topleft.xpm", &garbage, &garbage);
	wall()->img_sea = mlx_xpm_file_to_image(box()->mlx, "./textures/sea.xpm", &garbage, &garbage);
	wall()->floor = mlx_xpm_file_to_image(box()->mlx, "./textures/b00.xpm", &garbage, &garbage);
}

void	init_frames()
{
	int	garbage;

	player_dir()->rframe = mlx_xpm_file_to_image(box()->mlx, "./textures/r00.xpm", &garbage, &garbage);
	player_dir()->lframe = mlx_xpm_file_to_image(box()->mlx, "./textures/l00.xpm", &garbage, &garbage);
	player_dir()->tframe = mlx_xpm_file_to_image(box()->mlx, "./textures/t00.xpm", &garbage, &garbage);
	box()->p_status = player_dir()->rframe;
}

void	set_colictables()
{
	int	garbage;
	
	player_dir()->colictable[0] = mlx_xpm_file_to_image(box()->mlx, "./textures/col00.xpm", &garbage, &garbage);
	player_dir()->colictable[1] = mlx_xpm_file_to_image(box()->mlx, "./textures/col01.xpm", &garbage, &garbage);
	player_dir()->colictable[2] = mlx_xpm_file_to_image(box()->mlx, "./textures/col02.xpm", &garbage, &garbage);
	player_dir()->colictable[3] = mlx_xpm_file_to_image(box()->mlx, "./textures/col03.xpm", &garbage, &garbage);
	player_dir()->colictable[4] = mlx_xpm_file_to_image(box()->mlx, "./textures/col04.xpm", &garbage, &garbage);
	player_dir()->colictable[5] = mlx_xpm_file_to_image(box()->mlx, "./textures/col05.xpm", &garbage, &garbage);
	player_dir()->colictable[6] = mlx_xpm_file_to_image(box()->mlx, "./textures/col06.xpm", &garbage, &garbage);
	player_dir()->colictable[7] = mlx_xpm_file_to_image(box()->mlx, "./textures/col07.xpm", &garbage, &garbage);
	player_dir()->colictable[8] = mlx_xpm_file_to_image(box()->mlx, "./textures/col08.xpm", &garbage, &garbage);
	player_dir()->colictable[9] = mlx_xpm_file_to_image(box()->mlx, "./textures/col09.xpm", &garbage, &garbage);
}

void	set_exit()
{
	int garbage;

	player_dir()->exit_hole[0] = mlx_xpm_file_to_image(box()->mlx, "./textures/e04.xpm", &garbage, &garbage);
	player_dir()->exit_hole[1] = mlx_xpm_file_to_image(box()->mlx, "./textures/e03.xpm", &garbage, &garbage);
	player_dir()->exit_hole[2] = mlx_xpm_file_to_image(box()->mlx, "./textures/e02.xpm", &garbage, &garbage);
	player_dir()->exit_hole[3] = mlx_xpm_file_to_image(box()->mlx, "./textures/e01.xpm", &garbage, &garbage);
	player_dir()->exit_hole[4] = mlx_xpm_file_to_image(box()->mlx, "./textures/e00.xpm", &garbage, &garbage);
}