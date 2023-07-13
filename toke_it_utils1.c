/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toke_it_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:11:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/13 15:11:36 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	xsqbp(t_tokenz *m, char *str)
{
	m->i++;
	m->j++;
	m->count++;
	while (m->i < find_quotes_pair(str, '\''))
		xsfill_it(m, str);
	if (str[m->i] == '\'')
		m->array[m->j] = '0';
	else
		lerreurat(3);
}

void	dquotes_tokenz(t_tokenz *m, char *str)
{
	int	tmp;

	tmp = 0;
	m->array[m->j] = '3';
	if (quote_bfr_pipe(str, m->i, '"'))
		dqbp(m, str);
	else if (!quote_bfr_pipe(str, m->i, '"'))
		xdqbp(m, str);
}

void	squotes_tokenz(t_tokenz *m, char *str)
{
	int	tmp;

	tmp = 0;
	m->array[m->j] = '0';
	if (quote_bfr_pipe(str, m->i, '\''))
		sqbp(m, str);
	else if (!quote_bfr_pipe(str, m->i, '\''))
		xsqbp(m, str);
}
