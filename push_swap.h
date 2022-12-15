/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:27:40 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 17:52:39 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "structs.h"

/* ======== PUSH SWAP COMMANDS ======== */
void		pa(t_number **a, t_number **b);
void		pb(t_number **a, t_number **b);
void		ra(t_number **a, int p);
void		rb(t_number **b, int p);
void		rr(t_number **a, t_number **b);
void		rra(t_number **a, int p);
void		rrb(t_number **b, int p);
void		rrr(t_number **a, t_number **b);

/* ======== get_elems.c ======== */
int			get_num_elems(int ac, char ***av);
t_number	*get_elems(int num, char **av);
void		get_elems2(int num, char **av, t_number **head);

/* ======== bruteforce.c ======== */
void		bruteforce(t_number **a, t_number **b);

/* ======== error_exit.c ======== */
void		error_exit(t_number **a, t_number **b);
void		atoi_error_exit(t_number *a, char **tab);

/* ======== sort.c ======== */
void		sort(t_number **a, t_number **b);
void		sort2(int max, t_number **a, t_number **b, int i);
int			is_sorted(t_number *a);

#endif