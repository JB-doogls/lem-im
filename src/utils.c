/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:39:09 by user              #+#    #+#             */
/*   Updated: 2020/09/10 18:10:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_map(t_room *room)
{
	t_room		*tmproom;
	t_link		*tmplink;

	while (room)
	{
		free(room->name);
		tmproom = room;
		while (room->link)
		{
			tmplink = room->link;
			// free(room->link->room);
			room->link = room->link->next;
			free(tmplink);
		}
		room = room->next;
		free(tmproom);
	}
	ft_memdel((void*)room);
}

void		free_stor(t_frame **stor)
{
	free((*stor)->start);
	free((*stor)->end);
	ft_memdel((void**)stor);
}

void		free_input(t_input *input)
{
	t_input		*tmp;

	while (input)
	{
		free(input->line);
		tmp = input;
		input = input->next;
		free(tmp);
	}
	ft_memdel((void*)input);
}

/*
**	Check input funcs: is_cmd, is_room, is_comment, is_link
*/

int			is_valid_ants(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '0' || !ft_isposint_str(str))
		lem_error(NO_ANTS_ERR);
	return (1);
}

int			is_link(char *line)
{	
	char	**split;

	if (!line)
		lem_error(READ_ERR);
	if (!(split = ft_strsplit(line, '-')))
		lem_error(ALLOC_ERR);
	if (ft_len_splited(split) != 2 || !is_room_name(split[0]) ||
	!is_room_name(split[1]))
	{
		ft_free_splited(split);
		return (0);
	}
	ft_free_splited(split);
	return (1);
}

int			is_hash(char *line)
{
	if (!line)
		lem_error(READ_ERR);
	return (line[0] == '#'); 
}

int			is_room_name(char *line)
{
	if (!line)
		lem_error(READ_ERR);
	return (line[0] != 'L' || line[0] != '#');
}

int			is_room(char *line)
{
	char	**split;
	int		res;

	res = 1;
	if (!line)
		lem_error(READ_ERR);
	if (!(split = ft_strsplit(line, ' ')))
		lem_error(ALLOC_ERR);
	if (ft_len_splited(split) != 3 || !is_room_name(split[0]) ||
	!ft_isint_str(split[1]) || !ft_isint_str(split[2]))
		res = 0;
	ft_free_splited(split);
	return (res);
}

/*
**	Other funcsroom
*/


void		lem_error(char *str)
{
	if (errno == 0)
		perror(str);
	else
		ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}