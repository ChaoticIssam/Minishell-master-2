/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toke_it_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:11:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/14 09:59:16 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dqbp(t_tokenz *m, char *str)
{
	int	tmp;

	tmp = 0;
	tmp = quote_bfr_pipe(str, m->i, '"');
	m->i++;
	m->j++;
	while (m->i < tmp)
	{
		m->array[m->j] = '1';
		if (str[m->i] == '"' || str[m->i] == '\'')
			m->array[m->j] = '3';
		m->i++;
		m->j++;
	}
	if (str[m->i] == '"')
		m->array[m->j] = '3';
	else
		m->array[m->j] = '1';
}

void	sqbp(t_tokenz *m, char *str)
{
	int	tmp;

	tmp = 0;
	tmp = quote_bfr_pipe(str, m->i, '\'');
	m->i++;
	m->j++;
	while (m->i < tmp)
	{
		m->array[m->j] = '1';
		if (str[m->i] == '\'' || str[m->i] == '"')
			m->array[m->j] = '0';
		m->i++;
		m->j++;
	}
	if (str[m->i] == '\'')
		m->array[m->j] = '0';
	else
		m->array[m->j] = '1';
}

void	xdfill_it(t_tokenz *m, char *str)
{
	if (str[m->i] == '"')
	{
		m->array[m->j] = '3';
		m->count++;
		m->j++;
		m->i++;
	}
	else if (str[m->i] == '|' && m->count % 2 == 0)
	{
		m->array[m->j] = '6';
		m->i++;
		m->j++;
	}
	else
	{
		m->array[m->j] = '1';
		m->j++;
		m->i++;
	}
}

void	xsfill_it(t_tokenz *m, char *str)
{
	if (str[m->i] == '\'')
	{
		m->array[m->j] = '0';
		m->count++;
		m->j++;
		m->i++;
	}
	else if (str[m->i] == '|' && m->count % 2 == 0)
	{
		m->array[m->j] = '6';
		m->i++;
		m->j++;
	}
	else
	{
		m->array[m->j] = '1';
		m->j++;
		m->i++;
	}
}

void	xdqbp(t_tokenz *m, char *str)
{
	m->i++;
	m->j++;
	m->count++;
	while (m->i < find_quotes_pair(str, '"'))
		xdfill_it(m, str);
	if (str[m->i] == '"')
		m->array[m->j] = '3';
	else
	{
		printf("2\n");		
		lerreurat(3);
	}
}
