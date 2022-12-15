/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:50:39 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 18:31:56 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_three(t_number *a, int s)
{
	if (a->index == 0 + s && a->next->index == 2 + s
		&& a->next->next->index == 1 + s)
		ft_printf("ra\nsa\nrra\n");
	else if (a->index == 1 + s && a->next->index == 0 + s
		&& a->next->next->index == 2 + s)
		ft_printf("sa\n");
	else if (a->index == 1 + s && a->next->index == 2 + s
		&& a->next->next->index == 0 + s)
		ft_printf("rra\n");
	else if (a->index == 2 + s && a->next->index == 1 + s
		&& a->next->next->index == 0 + s)
		ft_printf("sa\nrra\n");
	else if (a->index == 2 + s && a->next->index == 0 + s
		&& a->next->next->index == 1 + s)
		ft_printf("ra\n");
}

void	handle_four(t_number **a, t_number **b)
{
	while ((*a)->index != 0)
		ra(a, 1);
	pb(a, b);
	handle_three(*a, 1);
	ft_printf("pa\n");
}

void	handle_five(t_number **a, t_number **b)
{
	while (ft_lstsize(*b) < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a, 1);
	}
	handle_three(*a, 2);
	if ((*b)->index < (*b)->next->index)
		ft_printf("sb\n");
	ft_printf("pa\npa\n");
}

void	bruteforce(t_number **a, t_number **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size < 2)
		error_exit(a, b);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			ft_printf("sa\n");
	}
	else if (size == 3)
		handle_three(*a, 0);
	else if (size == 4)
		handle_four(a, b);
	else if (size == 5)
		handle_five(a, b);
}
