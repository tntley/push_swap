/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:23:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/27 10:09:50 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_list_stack
{
	int					value;
	int					index;
	struct s_list_stack	*next;
	struct s_list_stack	*prev;
}				t_list_stack;

typedef struct s_list_bench
{
	float	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}				t_list_bench;

typedef struct	s_list_flag
{
	int	bench;
	int	mode;
}				t_list_flag;

void	define_flag_struct(t_list_flag **flag);

int				check_bench(t_list_bench **metric, char *argv);
void			define_bench(t_list_bench **metric);

void			parsing(char **argv, int argc, int i, t_list_bench *metric);
void			manage_input(char **temp, t_list_stack **a);
void			run_sort(t_list_stack **a, t_list_stack **b, int sortmode,
					t_list_bench *metric);
int				run_isdigit(char *temp);
long			ft_atolong(const char *temp);
int				is_duplicate(t_list_stack *a, int nb);
void			build_stack(t_list_stack **a, int nb);
void			define_indexes(t_list_stack *a);
void			find_index(t_list_stack *a, int stacksize);
int				sizeofstack(t_list_stack *a);
float			compute_disorder(t_list_stack *a);
char			*ft_strjoinspace(const char *s1, const char *s2);
int				define_sort_mode(char *flag);
int				ft_strcmp(const char *s1, const char *s2);

void			actual_sort(t_list_stack **a, t_list_bench *metric,
					int sortmode);
void			error_and_free(t_list_stack **a);
void			freestack(t_list_stack **stack);
int				ft_sqrt(int nb);
void			free_everything(t_list_stack **a, t_list_bench **metric,
					char *joint, char **temp);

void			simplesort(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric);
void			mediumsort(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric);
void			complexsort(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric);
void			adaptivesort(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric);

int				get_min_index(t_list_stack *stack);
void			move_to_top_a(t_list_stack **stack,
					int target_idx, t_list_bench *metric);
void			move_to_top_b(t_list_stack **stack,
					int target_idx, t_list_bench *metric);
void			sort_three(t_list_stack **a, t_list_bench *metric);
void			push_back_to_a(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric, int i);

void			print_metrics(t_list_bench *metric, int sortmode);
void			print_disorder(float disorder);
void			print_mode(int sortmode, float disorder);
void			print_total_ops(t_list_bench *metric);
void			print_ops(t_list_bench *metric);

void			do_ra(t_list_stack **a, t_list_bench *metric);
void			do_rb(t_list_stack **b, t_list_bench *metric);
void			do_rr(t_list_stack **a, t_list_stack **b, t_list_bench *metric);
void			do_sa(t_list_stack **a, t_list_bench *metric);
void			do_sb(t_list_stack **b, t_list_bench *metric);
void			do_ss(t_list_stack **a, t_list_stack **b, t_list_bench *metric);
void			do_pa(t_list_stack **b, t_list_stack **a, t_list_bench *metric);
void			do_pb(t_list_stack **a, t_list_stack **b, t_list_bench *metric);
void			do_rra(t_list_stack **a, t_list_bench *metric);
void			do_rrb(t_list_stack **b, t_list_bench *metric);
void			do_rrr(t_list_stack **a, t_list_stack **b,
					t_list_bench *metric);

void			rotate(t_list_stack **stack);
void			ra(t_list_stack **a);
void			rb(t_list_stack **b);
void			rr(t_list_stack **a, t_list_stack **b);

void			swap(t_list_stack **stack);
void			sa(t_list_stack **a);
void			sb(t_list_stack **b);
void			ss(t_list_stack **a, t_list_stack **b);

void			reverserotate(t_list_stack **stack);
void			rra(t_list_stack **a);
void			rrb(t_list_stack **b);
void			rrr(t_list_stack **a, t_list_stack **b);

void			push(t_list_stack **src, t_list_stack **dest);
void			pa(t_list_stack **b, t_list_stack **a);
void			pb(t_list_stack **a, t_list_stack **b);
t_list_stack	*pop_node(t_list_stack **src);

#endif
