/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:38:18 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:48 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	for_quotes(t_commande *s, int i, char *str, char *list)
{
	s->j = i;
	s->commande[s->x] = quotes_quotes(str, list, i);
	if (quote_bfr_pipe(str, i, list[i]))
		i = quote_bfr_pipe(str, i, list[i]);
	else if (!quote_bfr_pipe(str, i, list[i]))
		i = s->j;
	if (list[i] == '3')
		i = sec_q_rex(list, i);
	else if (list[i] == '0')
		i = sec_q_rex(list, i);
	s->start = i + 1;
	s->x++;
}

void	get_end(t_commande *s, int i, char *list)
{
	s->end = i - 1;
	if (i + 1 <= ft_strlen(list) && !list[i + 1])
		s->end = i;
	s->lock1 = 0;
	s->lock = 1;
	if (i + 1 <= ft_strlen(list) && list[i + 1] == '6')
	{
		s->end = i;
		if (list[i] == '2')
			s->end = i - 1;
		s->lock = 0;
	}
}

void	get_start(t_commande *s, int i, char *list)
{
	s->start = i;
	s->lock = 0;
	s->lock1 = 1;
	s->tmp = list[i];
}

void	last_world_ig(t_commande *s, int i)
{
	s->start = i;
}

void	get_commande(t_commande *s, char *str)
{
	s->commande[s->x] = ft_substr(str, s->start, s->end - s->start + 1);
	s->x++;
}

void	skip_sp(t_commande *s, char *list, int i)
{
	while (list[i] == '2')
		i++;
	i--;
	s->start = i;
	s->lock1 = 0;
}
