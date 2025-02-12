/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:30:24 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 18:45:55 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	type(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (DFAG);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (DFAD);
	else if (str[i] == '>')
		return (FAD);
	else if (str[i] == '<')
		return (FAG);
	else if (str[i] == '\'')
		return (EXP_ARG);
	else if (str[i] == ' ')
		return (ESPACE);
	else
		return (ARG);
}

void	free_lst(t_token *head)
{
	t_token	*temp;

	while (head)
	{
		temp = head->next;
		free(head->token);
		free(head);
		head = temp;
	}
}

t_token	*create_node(char *token, int type, t_token *list, char **env)
{
	t_token	*node;

	node = malloc(sizeof(t_token)); //
	if (!node)
		return (NULL);
	node->token = ft_strdup(token);
	if (!node->token)
	{
		free(node);
		free_lst(list);
		return (NULL);
	}
	node->type = type;
	if (node->type == EXP_ARG)
		node->token = cut_dq(node->token);
	else
		node->token = expande_moi(token, env);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	add_end(t_token **head, t_token *new_node)
{
	t_token	*temp;

	if (!head || !new_node)
		return (1);
	if (!*head)
	{
		*head = new_node;
		return (0);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (0);
}

int	lexer(t_data *data)
{
	int		i;
	int		t;
	t_token	*list;
	t_token	*new_node;

	i = 0;
	list = NULL;
	new_node = NULL;
	data->tokens = ft_split(data->brut_input, ' ');
	data->count = count(data->brut_input, ' ');
	while (data->tokens[i] && i < data->count)
	{
		t = type(data->tokens[i]);
		new_node = create_node(data->tokens[i], t, list, data->envcpy);
		add_end(&list, new_node);
		i++;
	}
	list = merge_args(list);
	while (list)
	{
		printf("token = %s\n", list->token);
		list = list->next;
	}
	if (syntax_precheck(list))
	{
		free_lst(list);
		return (1);
	}
	free_lst(list);
	return (0);
}

