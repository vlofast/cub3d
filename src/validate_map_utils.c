/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:49:59 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/11/24 19:50:12 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_line(char *line, int width)
{
	char	*str;
	int		i;

	i = 0;
	if (ft_strlen(line) < (size_t)width)
	{
		str = malloc((width + 1) * sizeof(char));
		while (line[i] && line[i] != '\n')
		{
			str[i] = line[i];
			i++;
		}
		while (i < (width - 1))
		{
			str[i] = ' ';
			i++;
		}
		str[i] = '\n';
		str[i + 1] = '\0';
		free(line);
		return (str);
	}
	return (line);
}

bool	is_texture_valid(char *path)
{
	int	fd;

	if (!path)
		return (false);
	if (!ft_strnstr(path, ".xpm", ft_strlen(path)))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	check_all_elements(t_map *map)
{
	if (map->p_init_dir == 0)
	{
		printf("Error\n\033[1;31mThe map doesn't contain a player's start "
			"position\033[0m\n");
	}
	else if (map->p_init_dir == 'X')
		printf("Error\n\033[1;31mDuplicated player's start position\033[0m\n");
	else if (!map->ceiling_color)
		printf("Error\n\033[1;31mWrong or inexistent Ceiling color\033[0m\n");
	else if (!map->floor_color)
		printf("Error\n\033[1;31mWrong or inexistent Floor color\033[0m\n");
	else if (!map->no || !is_texture_valid(map->no))
		printf("Error\n\033[1;31mWrong or inexistent North texture\033[0m\n");
	else if (!map->so || !is_texture_valid(map->so))
		printf("Error\n\033[1;31mWrong or inexistent South texture\033[0m\n");
	else if (!map->we || !is_texture_valid(map->we))
		printf("Error\n\033[1;31mWrong or inexistent West texture\033[0m\n");
	else if (!map->ea || !is_texture_valid(map->ea))
		printf("Error\n\033[1;31mWrong or inexistent East texture\033[0m\n");
	else
		return (true);
	return (false);
}

int	check_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line [i - 1] != '\n')
		return (i);
	return (i - 1);
}
