#include "push_swap.h"

// Function to free everything
void    free_everything(t_node list)
{
    free_parsed_nums(&list);
    return;
}

// FREE PARSED LIST
void    free_parsed_nums(t_node *list)
{
    // while (list->a->next != NULL && list->b->next != NULL)
    // {
	// 	ft_printf("hi\n");
    //     free(list->a);
    //     free(list->b);
	// 	list->a = list->a->next;
	// 	list->b = list->b->next;
    // }
	// free(list);
	list = NULL;
    return ;
}