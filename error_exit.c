/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:48:22 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/13 16:36:41 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoi_error_exit(t_number *a, char **tab)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_split(tab);
	ft_lstclear(&a);
	exit(1);
}

void	error_exit(t_number **a, t_number **b)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(a);
	ft_lstclear(b);
	exit(1);
}
