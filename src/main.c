/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:40 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/11/24 18:33:47 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_images(t_data *data)
{
	int	i;

	i = 0;
	data->img = malloc((sizeof(t_img)));
	data->img->mlx_img = 0;
	data->tex_img = ft_calloc(4 + 1, sizeof(t_img *));
	while (i < 4)
	{
		data->tex_img[i] = malloc(sizeof(t_img));
		data->tex_img[i]->mlx_img = 0;
		i++;
	}
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map_start = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->map_array = NULL;
	map->p_init_dir = 0;
	map->p_init_y = 0;
	map->p_init_x = 0;
	map->duplicated_elements = false;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->moves.w = false;
	data->moves.a = false;
	data->moves.s = false;
	data->moves.d = false;
	data->moves.rotate_r = false;
	data->moves.rotate_l = false;
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	init_images(data);
	data->win.x = 1024;
	data->win.y = 720;
	data->map = NULL;
	return (data);
}

void	print_messages(t_data *data, t_map *map)
{
	printf("\033[1;32mMap is VALID!\033[0m\n");
	printf("%s", data->map->map_array[0]);
	printf("Ceiling_color: %i - %i - %i\n", data->map->ceiling_color[0],
		data->map->ceiling_color[1], data->map->ceiling_color[2]);
	printf("Floor_color: %i - %i - %i\n", data->map->floor_color[0],
		data->map->floor_color[1], data->map->floor_color[2]);
	printf("Player start pos x: %i y: %i direction: %c\n",
		map->p_init_x, map->p_init_y, map->p_init_dir);
	printf("NO texture: %s\n", data->map->no);
	printf("SO texture: %s\n", data->map->so);
	printf("WE texture: %s\n", data->map->we);
	printf("EA texture: %s\n", data->map->ea);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		init_map(map);
		data = init_data();
		if (validate_file(av[1], map))
		{
			data->map = map;
			print_messages(data, map);
			init_game(data);
		}
		free_fail(data, map);
	}
	else
	{
		printf("Error\n\033[1;31mNumber of Arguments is INVALID!\033[0m\n");
		printf("How to use it ->  ./cub3D <map_file>\n");
	}
}
