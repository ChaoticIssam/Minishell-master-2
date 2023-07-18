/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:58:49 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/18 17:09:05 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int					token;
	struct s_node		*next;
}						t_node;

typedef struct s_tokenz
{
	int					i;
	int					j;
	int					count;
	char				*array;
}						t_tokenz;

typedef struct s_commande
{
	char				**commande;
	int					j;
	int					x;
	int					start;
	int					end;
	int					ptr_num;
	int					lock;
	int					lock1;
	int					tmp;
}						t_commande;

typedef struct s_commandes
{
	char				**commande;
	// char				*infile;
	// char				*outfile;
	// char				*herdock;
	// char				*
	char				**files;
	struct s_commandes	*next;
}						t_commandes;

typedef struct s_env
{
	char				*var;
	char				*path;
	int					env_len;
	struct s_env		*next;
}						t_env;

int						ft_strncmp(char *s1, char *s2);
int						ft_strlen(char *str);
// t_node					*create_node(int arg);
// t_node				*create_ll(char *str);
char					*toknz_list(char *str);
int						count_ptr(char *list, int bool);
int						ft_isredi(char c);
int						ft_isspecial(char c);
int						count_redi(char *list);
int						count_pipe(char *list);
t_commandes				*ft_lstnew(void *content);
t_commandes				*ft_lstlast(t_commandes *lst);
void					ft_lstadd_back(t_commandes **lst, t_commandes *new);
char					**return_commande(char *list, char *str, int bool);
char					*ft_substr(char *s, int start, int len);
char					**ft_split(char *str, char c);
int						ft_isspecial(char c);
// int						get_index(int *list);
// char					*in_quotes(char *tokenz, char *str, int i);
int						find_quotes_pair(char *str, char c);
// int						*return_string(t_node *list, char *str);
char					*ft_strjoin(char *s1, char *s2);
void					ft_putstr(char *str);
// int						count_token(char *list);
int						quote_bfr_pipe(char *str, int i, char q);
void					dquotes_tokenz(t_tokenz *m, char *str);
void					squotes_tokenz(t_tokenz *m, char *str);
void					xsqbp(t_tokenz *m, char *str);
void					dqbp(t_tokenz *m, char *str);
void					sqbp(t_tokenz *m, char *str);
void					xdfill_it(t_tokenz *m, char *str);
void					xsfill_it(t_tokenz *m, char *str);
void					xdqbp(t_tokenz *m, char *str);
// void					fill_strct(char **commande);
int						sec_q(char *tknz);
int						sec_q_rex(char *tknz, int end);
int						frst_q(char *tknz);
int						frst_q_rex(char *tknz, int start);
char					*quotes_quotes(char *str, char *tknz, int start);
int						env_len(t_commandes *m);
char					*fill_var(t_env *s, t_commandes *m, int i, int j);
char					*get_path(char **env, int i);
char					*fill_path(char **env, t_env *s);
char					*var_gett(char **env, int i);
int						num_of_q(char *list, int start);
char					**return_file(char *list, char *str, int bool);

void					for_quotes(t_commande *s, int i, char *str, char *list);
void					get_end(t_commande *s, int i, char *list);
void					get_start(t_commande *s, int i, char *list);
void					last_world_ig(t_commande *s, int i);
void					get_commande(t_commande *s, char *str);
void					skip_sp(t_commande *s, char *list, int i);

int						num_of_s_q(char *list, int start);
int						quotes_error(char *list);
int						sec_s_q(char *tknz);
int						expand_erreur(char *list);
int						lerreurat(int error);
int						check_pipe(char *list);

#endif
