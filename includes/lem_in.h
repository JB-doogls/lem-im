/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:23:10 by user              #+#    #+#             */
/*   Updated: 2020/08/25 16:00:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <errno.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_links		t_links;
typedef struct s_room		t_room;
typedef struct s_frame		t_frame;
typedef struct s_input		t_input;

struct				s_input
{
	char			*line;
	t_input			*next;
};

struct				s_linked
{
	t_room			*room;
	t_links			*next;
};

struct				s_room
{
	char			*name;
	int				x;
	int				y;
	int				level;
	int				num_links;
	int				visit;
	t_links			*link;
};

struct				s_frame
{
	char			*start;
	char			*end;
	int				num_ants;
	int				num_rooms;
};


#endif
