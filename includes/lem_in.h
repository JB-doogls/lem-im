/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:23:10 by user              #+#    #+#             */
/*   Updated: 2020/09/10 21:55:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# include "libft.h"


/*
**	Error messages
*/

# define READ_ERR		"ERROR: Reading error occured"
# define INP_ERR		"ERROR: incorrect input"
# define NO_ANTS_ERR	"ERROR: No ants on input"
# define ROOM_ADD_ERR	"ERROR: Room creation failed"
# define ALLOC_ERR		"ERROR: Allocation error"
# define LINKS_ERR		"ERROR: Links creation failed"
# define CMD_ERR_ST		"ERROR: More then one ##start cmd"
# define CMD_ERR_END	"ERROR: More then one ##end cmd"

/*
** Other defines
*/

# define START_SIG	1
# define END_SIG	2
# define NO_SIG		0


/*
**	Structures
*/

typedef struct s_link		t_link;
typedef struct s_room		t_room;
typedef struct s_frame		t_frame;
typedef struct s_input		t_input;

struct				s_input
{
	char			*line;
	t_input			*next;
};

struct				s_link
{
	t_room			*room;
	t_link			*next;
};

struct				s_room
{
	char			*name;
	int				coord[2];
	int				level;
	int				num_links;
	int				visit;
	t_room			*next;
	t_link			*link;
};

struct				s_frame
{
	t_room			*start;
	t_room			*end;
	int				cmd;
	int				num_ants;
	int				num_rooms;
	t_input			*input;
	t_room			*room;
};


/*
**	Functions
*/

void				lem_in();
t_input				*read_input();
t_input				*create_input_item(char *line);

t_room				*parse_input(t_input *input, t_frame *stor);
t_frame				*init_storage(t_input **input);
void				parse_start_end(char *line, t_frame *stor);

t_room				*create_room(t_frame *stor, char *line);
t_room				*add_room(t_room *room, t_room *new_room, t_frame *stor);

int					is_valid_ants(char *str, t_frame *stor);
int					is_room(char *line, t_frame *stor);
int					is_hash(char *line, t_frame *stor);
int					is_room_name(char *line);
int					is_link(char *line, t_frame *stor);
int					check_parsing(t_frame *stor);

void				handle_links(t_room *room, char *line, t_frame *stor);
void				find_rooms(t_room *room, const char *r1, const char *r2, t_frame *stor);
void				set_links(t_room *room1, t_room *room2, t_frame *stor);
t_link				*create_link(t_room *room, t_frame *stor);


void				lem_error(char *str, t_frame *stor);
void				lem_free(t_frame *stor);
void				free_input(t_input *input);
void				free_stor(t_frame *stor);
void				free_map(t_room *room);

/*
**	JUST FOR TESTING ********************** DELETE
*/ 

void				print_input(t_input *input);
void				print_room(t_room *room);
void				print_room_list(t_frame *stor, t_room *room);

#endif
