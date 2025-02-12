/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:38:11 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 18:43:56 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_type
{
	ESPACE = 0,
	ARG,
	EXP_ARG,
	PIPE,	// |
	FAG,	// <
	FAD,	// >
	DFAG,	// <<
	DFAD,	// >>
}					t_type;

typedef struct s_token
{
	int				type;
	char			*token;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	t_token			*token;
	int				count;
	char			**envcpy;
	char			**tokens;
	char			*brut_input;
}					t_data;

char				*joiner(char *s1);
char				*cut_dq(char *str);
int					lexer(t_data *data);
char				**cpenv(char **env);
int					builtin(t_data *data);
int					count_tab(char **env);
int					count(char *s, char c);
void				free_lst(t_token *head);
char				**malloc_free(char **tab);
char				*ft_strdup(const char *s);
t_token				*merge_args(t_token *head);
char				**ft_split(char *s, char c);
int					syntax_precheck(t_token	*head);
char				*expande_moi(char *s, char **env);
char				*create_word(char *start, int len);
char				*is_double_quote(char **s, char quote);
int					quote_handle(char *s, char quote, int i);
int					dq_len(char **s, char *start, char quote);

#endif
