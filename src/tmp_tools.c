
#include "lem_in.h"

/*
**		JUST FOR TESTING**********************
*/ 

void		print_input(t_input *input)
{
	t_input		*copy;

	copy = input;

	printf("\n---PRINT INPUT---\n");
	while (copy)
	{
		printf("%s\n", copy->line);
		copy = copy ? copy->next : NULL;
	}
}





/*
**********************************************
*/