/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:01:22 by user              #+#    #+#             */
/*   Updated: 2020/09/10 18:21:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		parse_start_end(char *line, t_frame *stor)
{
	if (!line)
		lem_error(READ_ERR);
	if (line && !ft_strcmp(line, "##start"))
	{
		if (stor->start)
			lem_error(CMD_ERR_ST);
		stor->cmd = START_SIG;
	}
	if (line && !ft_strcmp(line, "##end"))
	{
		if (stor->end)
			lem_error(CMD_ERR_END);
		stor->cmd = END_SIG;
	}
}

t_frame		*init_storage(t_input **input)
{
	t_frame		*stor;

	if (!(stor = ft_memalloc(sizeof(t_frame))))
		return (NULL);
	while (*input && is_hash((*input)->line))
		(*input) = (*input)->next;
	if (*input && ft_isdigit((*input)->line[0]) &&
		is_valid_ants((*input)->line))
		stor->num_ants = ft_atoi((*input)->line);
	else
		lem_error(NO_ANTS_ERR);
	stor->num_rooms = 0;
	stor->cmd = NO_SIG;
	stor->end = NULL;
	stor->start = NULL;
	return (stor);
	
}

t_room		*parse_input(t_input *input)
{
	t_room		*room;
	t_frame		*stor;

	if (!input)
		lem_error(READ_ERR);
	room = NULL;
	stor = init_storage(&input);
	input = input->next;
	while (input)
	{
		if (is_hash(input->line))
			parse_start_end(input->line, stor);
		else
		{
			if (is_room(input->line))
				room = add_room(room, create_room(stor, input->line));
			if (is_link(input->line))
				handle_links(room, input->line);
		}
		input = input->next;
	}
	print_room_list(stor, room ? room : NULL);			// func to print rooms list (testing)
	free_stor(&stor);
	return (room);
}