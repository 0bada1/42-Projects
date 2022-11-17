#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// typedef struct s_push_swap_stacks
// {
// 	t_stack	*a;
// 	t_stack	*b;
// }
// t_all_stacks;

typedef struct s_counter
{
	int i;
	int	j;
	int	k;
}
t_counter;

typedef struct s_stack
{
	int				chunk_num;
	int				index;
	int				num;
	struct s_stack	*next;
}
t_stack;

typedef struct s_node
{
	t_stack			*a;
	t_stack			*b;
	int				number_of_ints;
	int				chunk_size;
	int 			num_of_steps;
	int				largest_num;
	int				smallest_num;
}
t_node;


/*----------PUUUSSHHHH_SSWWAAAPPP----------*/
/*-------------------MAIN------------------*/


/*-----------------PARSING-----------------*/
t_node 		*parse(char *argv[]);	
t_node		*get_index(t_node *stack);
t_node		*get_chunk_num(t_node *stack);
// int			*parse(char *cnums[]);

/*-----------------MOVEMENTS---------------*/
t_node		*sa(t_node *stack);
t_node		*sb(t_node *stack);
t_node		*ss(t_node *stack);
t_node		*pa(t_node *stack);
t_node		*pb(t_node *stack);
t_node		*ra(t_node *stack);
t_node		*rb(t_node *stack);
t_node		*rr(t_node *stack);
t_node		*rra(t_node *stack);
t_node		*rrb(t_node *stack);
t_node		*rrr(t_node *stack);
t_node		*rra_no_count(t_node *stack);
t_node		*rrb_no_count(t_node *stack);
t_node		*ra_no_count(t_node *stack);
t_node		*rb_no_count(t_node *stack);

/*----------------ALGORITHM----------------*/
t_node		*algorithm(t_node *stack);
t_node		*algorithm1(t_node *stack);
t_node		*algorithm2(t_node *stack);
t_node		*sort2(t_node *stack);
t_node		*sort3(t_node *stack);


/*-------------CHECK_FOR_ERRORS------------*/
int			check_for_errors(char *argv[]);
int			check_for_duplicates(t_node *num);

/*-------------------UTILS1----------------*/
int			find_num_of_ints_2D(char *cnums[]);
int			find_num_of_ints(char *cnums);
int			ft_isspace(char	c);
t_stack		*get_last_node(t_stack *stack);
t_stack		*get_before_last_node(t_stack *stack);
int			ft_atoi_ps(const char *str, t_node *stack);

/*-------------------UTILS2----------------*/
void		check_list(t_stack *list);
void    	initialize_variables_and_space(t_node *nums);
int			check_if_sorted(t_stack *stack);
t_stack		*sort_list(t_node *stack);

/*-------------------UTILS3----------------*/
t_node		*get_all_info(t_node *stack);
int			find_largest(t_node *stack);
int			find_smallest(t_node *stack);
t_node		*hardcode_sort(t_node *stack);
int			size_of_stack(t_stack *stack);

/*-------------------UTILS4----------------*/
t_node		*pushing_to_b(t_node *stack);
t_node		*pushing_to_a(t_node *stack);
int			check_index_location(t_node *node, t_stack *stack, int index);
int			check_closest_chunk_num(t_stack *stack, int chunk_num);
int			check_chunk_half(t_node *stack);

/*----------------LIBFT_LISTS--------------*/
t_stack		*ps_lstlast(t_stack *lst);
t_stack		*copy_list(t_stack *list);
t_stack		*ps_lstnew(int content);
void		ps_lstadd_back(t_stack **alst, t_stack *new);
void		ps_dellast(t_stack *lst);
// void		ps_del_before_last(t_stack *lst);

/*--------------------FREE-----------------*/
void    	free_everything(t_node *nums);
void    	free_parsed_nums(t_node *nums);

#  endif