/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:42:43 by user              #+#    #+#             */
/*   Updated: 2020/09/14 22:53:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "lem_parser.h"

t_link		*create_link(t_room *room, t_frame *stor)
{
	t_link	*link;

	if (!(link = ft_calloc(1, sizeof(t_room))))
		lem_error(LINKS_ERR, stor);
	link->room = room;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

void		set_links(t_room *room1, t_room *room2, t_frame *stor)
{
	t_link		*link;

	if (!(link = room1->links))
	{
		if (!(room1->links = create_link(room2, stor)))
			lem_error(LINKS_ERR, stor);
		room1->num_links++;
		return ;
	}
	while (link)
	{
		if (!ft_strcmp(link->room->name, room1->name) ||
		!ft_strcmp(link->room->name, room2->name))
			lem_error(LINKS_DUPL_ERR, stor);
		if (link->next)
			link = link->next;
		else
			break ;
	}
	room1->num_links++;
	if (!(link->next = create_link(room2, stor)))
		lem_error(LINKS_ERR, stor);
	return ;
}

void		find_rooms(t_room *room, char *r1, char *r2, t_frame *stor)
{
	t_room		*copy;
	t_room		*room1;
	t_room		*room2;

	room1 = NULL;
	room2 = NULL;
	copy = room;
	while (copy && (!room1 || !room2))
	{
		if (!ft_strcmp(copy->name, r1))
			room1 = copy;
		else if (!ft_strcmp(copy->name, r2))
			room2 = copy;
		copy = copy->next;
	}
	if (!room1 || !room2)
		lem_error(LINKS_ERR, stor);
	set_links(room1, room2, stor);
	set_links(room2, room1, stor);
}

int			handle_links(t_room *room, char *line, t_frame *stor)
{
	char		*room1;
	char		*room2;
	char		**split;

	if (!(split = ft_strsplit(line, '-')))
	{
		ft_free_splited(split);
		lem_error(ALLOC_ERR, stor);
	}
	if (!(room1 = split[0]) ||
	!(room2 = split[1]))
		lem_error(LINKS_ERR, stor);
	find_rooms(room, room1, room2, stor);
	ft_free_splited(split);
	return (1);
}
