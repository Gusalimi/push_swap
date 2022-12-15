/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:29 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 17:52:10 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_number *a)
{
	if (a == NULL)
		return (0);
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_max(t_number *a)
{
	int	max;

	max = a->index;
	a = a->next;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

void	sort(t_number **a, t_number **b)
{
	int	max;

	max = get_max(*a);
	sort2(max, a, b, -1);
	while (ft_lstsize(*b) > 0)
		pa(a, b);
}

void	sort2(int max, t_number **a, t_number **b, int i)
{
	int	j;
	int	size;

	while ((max >> ++i) > 0)
	{
		j = 0;
		size = ft_lstsize(*a);
		while (j++ < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, 1);
		}
		j = 0;
		size = ft_lstsize(*b);
		while (j++ < size)
		{
			if ((((*b)->index >> i) & 1) == 1)
				pa(a, b);
			else
				rb(b, 1);
		}
	}
}
