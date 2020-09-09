/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:44:30 by user              #+#    #+#             */
/*   Updated: 2020/09/10 01:43:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input		*create_input_item(char *line)
{
	t_input		*item;

	if (!line || !(item = ft_memalloc(sizeof(t_input))))
		return (NULL);
	item->line = line;
	item->next = NULL;
	return (item);
}

t_input		*read_input()
{
	t_input		*input;
	t_input		*tmp;
	char		*line;

	input = NULL;
	while (get_next_line(0, &line, 0))
	{
		if (!input)
		{
			if ((!(input = create_input_item(line)) && get_next_line(0, NULL, 1))
			|| !(tmp = input))
				return (NULL);
		}
		else
		{
			if ((!(tmp->next = create_input_item(line)) && get_next_line(0, NULL, 1))
			|| !(tmp = tmp->next))
				return (NULL);
		}
	}
	get_next_line(0, NULL, 1);
	return (input);
}

void		lem_in()
{
	t_room		*map;
	t_input		*input;

	if (!(input = read_input()))
		lem_error(READ_ERR);
	map = parse_input(input);
	
	// print_input(input);

}

int			main(int ac, char **av)
{
	errno = 0;

	// if (ac >= 2) 	// Here is to handle possible bonus-flags
	// {				// --help, --verbose, --debug, etc
	// }
	if (ac == 1)
		lem_in();
	// else
	// 	lem_error(SMTH_HERE)
	
	return(0);
}
