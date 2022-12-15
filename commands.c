/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:25:02 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 17:40:39 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_number **a, int p)
{
	t_number	*tmp;

	if (ft_lstsize(*a) > 1)
	{
		tmp = (*a)->next;
		ft_lstlast(*a)->next = *a;
		(*a)->next = NULL;
		*a = tmp;
		if (p)
			ft_printf("ra\n");
	}
}

void	rb(t_number **b, int p)
{
	t_number	*tmp;

	if (ft_lstsize(*b) > 1)
	{
		tmp = (*b)->next;
		ft_lstlast(*b)->next = *b;
		(*b)->next = NULL;
		*b = tmp;
		if (p)
			ft_printf("rb\n");
	}
}

void	rr(t_number **a, t_number **b)
{
	if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		ft_printf("rr\n");
		ra(a, 0);
		rb(b, 0);
	}
}

void	pa(t_number **a, t_number **b)
{
	t_number	*tmp;

	if (ft_lstsize(*b) > 0)
	{
		(void)a;
		tmp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = tmp;
		ft_printf("pa\n");
	}
	if (ft_lstsize(*b) == 0)
		free(*b);
}

void	pb(t_number **a, t_number **b)
{
	t_number	*tmp;

	if (!a)
		return ;
	if (ft_lstsize(*a) > 0)
	{
		tmp = (*a)->next;
		(void)b;
		ft_lstadd_front(b, *a);
		*a = tmp;
		ft_printf("pb\n");
	}
	if (ft_lstsize(*a) == 0)
		free(*a);
}
