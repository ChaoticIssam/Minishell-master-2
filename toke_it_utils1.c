/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toke_it_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:11:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/17 23:25:49 by deimos           ###   ########.fr       */
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
	{
		printf("3\n");	
		lerreurat(3);
	}
}

void	dquotes_tokenz(t_tokenz *m, char *str)
{
	m->array[m->j] = '3';
	if (quote_bfr_pipe(str, m->i, '"'))
		dqbp(m, str);
	else if (!quote_bfr_pipe(str, m->i, '"'))
		xdqbp(m, str);
}

void	squotes_tokenz(t_tokenz *m, char *str)
{
	m->array[m->j] = '0';
	if (quote_bfr_pipe(str, m->i, '\''))
		sqbp(m, str);
	else if (!quote_bfr_pipe(str, m->i, '\''))
		xsqbp(m, str);
}
