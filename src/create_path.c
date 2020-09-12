/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:38:39 by user              #+#    #+#             */
/*   Updated: 2020/09/13 01:05:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "lem_parser.h"

t_path		*create_path_node(t_frame *stor)
{
	t_path		*path;

	if (!(path = ft_calloc(1, sizeof(t_path))))
		lem_error(PATH_ERR, stor);
	path->start = create_link(stor->start, stor);
	path->next = NULL;
	path->len = 0;
	return (path);
}

void		add_path(t_path *path, t_frame *stor)
{
	t_path		*cur;
	t_path		*prev;

	if (!path || !stor)
		lem_error(PATH_ERR, stor);
	cur = stor->paths;
	prev = NULL;
	if (cur)
	{
		while (cur && path->len > cur->len)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!prev)
			stor->paths = path;
		else
			prev->next = path;
		path->next = cur;
	}
	else
		stor->paths = path;
}

void		construct_path(t_path *path, t_link *lev1_link, t_frame *stor)
{
	t_link		*deep_link;
	t_link		*path_link;

	path_link = path->start;
	path_link->next = create_link(lev1_link->room, stor);
	path->len++;
	path_link = path_link->next;
	deep_link = path_link->room->links->next;
	while (deep_link && deep_link->room->level != INT_MAX)
	{
		path_link->next = create_link(deep_link->room, stor);
		path->len++;
		path_link = path_link->next;
		deep_link = deep_link->room->links->next;
	}
	path_link->next = create_link(deep_link->room, stor);
	path->len++;
}

t_path		*create_paths(t_frame *stor)
{
	set_levels(stor);		// tmp func to set bfs levels	**** DELETE

	t_path		*path;
	t_link		*lev1_link;
	int			i;

	i = -1;
	path = NULL;
	if (!stor)
		lem_error(PATH_ERR, NULL);
	lev1_link = stor->start->links;
	while (++i < stor->start->num_links)
	{
		path = create_path_node(stor);
		construct_path(path, lev1_link, stor);
		add_path(path, stor);
		lev1_link = lev1_link->next;
	}
	// print_path_list(stor);	// tmp func for testing	**** DELETE

	return (path);
}