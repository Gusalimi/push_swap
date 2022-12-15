/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:28:44 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/13 15:02:50 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_number **a, int p)
{
	t_number	*tmp;

	if (ft_lstsize(*a) > 1)
	{
		tmp = *a;
		*a = ft_lstlast(*a);
		(*a)->next = tmp;
		tmp = *a;
		while (tmp->next != *a)
			tmp = tmp->next;
		tmp->next = NULL;
		if (p)
			ft_printf("rra\n");
	}
}

void	rrb(t_number **b, int p)
{
	t_number	*tmp;

	if (ft_lstsize(*b) > 1)
	{
		tmp = *b;
		*b = ft_lstlast(*b);
		(*b)->next = tmp;
		tmp = *b;
		while (tmp->next != *b)
			tmp = tmp->next;
		tmp->next = NULL;
		if (p)
			ft_printf("rrb\n");
	}
}

void	rrr(t_number **a, t_number **b)
{
	ft_printf("rrr\n");
	rra(a, 0);
	rrb(b, 0);
}
