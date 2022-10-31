/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:20:26 by ooutabac          #+#    #+#             */
/*   Updated: 2022/10/31 10:59:45 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->num = content;
	return (new);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ps_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*t;

	if (*alst)
	{
		t = ps_lstlast(*alst);
		t->next = new;
	}
	else
		*alst = new;
}

void	ps_dellast(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		before_last = tmp;
		ft_printf("tmp->num = %i\n", tmp->num);
		tmp = tmp->next;
		ft_printf("tmp->num = %i\n", tmp->num);
	}
	free(tmp);
	before_last->next = NULL;
}

void	ps_del_before_last(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		before_last = tmp;
		ft_printf("tmp->num = %i\n", tmp->num);
		tmp = tmp->next;
		ft_printf("tmp->num = %i\n", tmp->num);
	}
	// free(tmp);
	before_last = NULL;
}