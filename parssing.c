/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:58:57 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/13 15:27:40 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**return_commande(char *list, char *str, int bool)
{
	char		**commande;
	static int	i;
	int			j;
	int			x;
	int			lock;
	int			lock1;
	int			tmp;
	int			start;
	int			end;
	int			ptr_num;

	x = 0;
	lock = 0;
	lock1 = 1;
	tmp = 0;
	start = 0;
	j = 0;
	end = 0;
	if (bool == 1)
		i = 0;
	ptr_num = count_ptr(list, bool);
	printf("---->%d\n", ptr_num);
	printf("i ->%d\n", i);
	commande = calloc(sizeof(char *), ptr_num + 2);
	expand_erreur(list);
	if (list[i] == '6')
		i++;
	while (list[i] == '2')
		i++;
	while (i + 1 <= ft_strlen(list) && list[i] && list[i] < 52)
	{
		if (list[i] == '3' || list[i] == '0')
		{
			j = i;
			commande[x] = quotes_quotes(str, list, i);
			if (quote_bfr_pipe(str, i, list[i]))
				i = quote_bfr_pipe(str, i, list[i]);
			else if (!quote_bfr_pipe(str, i, list[i]))
				i = j;
			if (list[i] == '3')
				i = sec_q_rex(list, i);
			else if (list[i] == '0')
				i = sec_q_rex(list, i);
			start = i + 1;
			x++;
		}
		if (((list[i] != tmp) || list[i + 1] == '6' || !list[i + 1]))
		{
			end = i - 1;
			if (i + 1 <= ft_strlen(list) && !list[i + 1])
				end = i;
			lock1 = 0;
			lock = 1;
			if (i + 1 <= ft_strlen(list) && list[i + 1] == '6')
			{
				end = i;
				if (list[i] == '2')
					end = i - 1;
				lock = 0;
			}
		}
		if ((list[i] == '1') && list[i] != '3' && lock && list[i + 1])
		{
			start = i;
			lock = 0;
			lock1 = 1;
			tmp = list[i];
		}
		if (i != 0 && i + 1 < ft_strlen(list) && list[i] == '1' && list[i
			- 1] == '2' && !list[i + 1])
		{
			commande[x] = &str[i];
			x++;
		}
		if (!lock1 && list[i] != '3' && str[start] != '"' && str[start] != '\''
			&& end >= start)
		{
			commande[x] = ft_substr(str, start, end - start + 1);
			x++;
		}
		if (list[i] == '2' && list[i + 1] == '2')
		{
			while (list[i] == '2')
				i++;
			i--;
			start = i;
			lock1 = 0;
		}
		i++;
	}
	return (commande);
}

char	**return_file(char *list, char *str, int bool)
{
	char		**files;
	static int	i;
	int			x;
	int			start;
	int			end;

	files = malloc(sizeof(char *) * 100);
	x = 0;
	start = 0;
	end = 0;
	if (bool == 1)
		i = 0;
	if (list[i] == '6')
		i++;
	while (list[i] == '2')
		i++;
	while (list[i] && list[i] != '6')
	{
		if (ft_isredi(list[i]) == 1)
		{
			start = i;
			if (i > 0)
				start = i + 1;
			while (list[i] != '2' && list[i])
				i++;
			if (i > start)
				end = i;
			printf("end ->%d and start ->%d\n", end, start);
			files[x] = ft_substr(str, start, end - start + 1);
			x++;
		}
		i++;
	}
	return (files);
}

char	*quotes_quotes(char *str, char *tknz, int start)
{
	int		i;
	int		j;
	int		last;
	char	*ptr;
	int		numoq;

	i = 0;
	last = 0;
	numoq = 0;
	ptr = malloc(sizeof(char) * 100);
	if (tknz[start] == '3')
	{
		i = frst_q_rex(tknz, start);
		last = sec_q_rex(tknz, sec_q(tknz)) + 1;
		numoq = num_of_q(tknz, start);
	}
	else if (tknz[start] == '0')
	{
		i = frst_q_rex(tknz, start);
		last = sec_q_rex(tknz, sec_s_q(tknz)) + 1;
		numoq = num_of_s_q(tknz, start);
	}
	j = 0;
	while (i < last && numoq % 2 == 0)
	{
		if (tknz[i] == '0' || tknz[i] == '3')
			i++;
		if (tknz[i] == '1')
		{
			ptr[j] = str[i];
			i++;
			j++;
		}
		if (!tknz[i] || tknz[i] == '2' || tknz[i] == '6')
		{
			ptr[j] = '\0';
			return (ptr);
		}
	}
	if ((tknz[i] == '6' && i > sec_q_rex(tknz, sec_q(tknz))))
	{
		ptr[j] = '\0';
		return (ptr);
	}
	if (i == sec_q_rex(tknz, sec_q(tknz) + 2) && sec_q_rex(tknz, sec_q(tknz))
		+ 1 > 0)
	{
		ptr[j] = '\0';
		return (ptr);
	}
	return (0);
}

char	*fill_var(t_env *s, t_commandes *m, int i, int j)
{
	char	*var;
	int		x;

	var = malloc(sizeof(char) * s->env_len + 1);
	x = 0;
	j++;
	while (m->commande[i][j] && m->commande[i][j] != ' ')
	{
		var[x] = m->commande[i][j];
		j++;
		x++;
	}
	var[x] = '\0';
	return (var);
}
