/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:54:18 by user              #+#    #+#             */
/*   Updated: 2020/09/10 18:54:59 by user             ###   ########.fr       */
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