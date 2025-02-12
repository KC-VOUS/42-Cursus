/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:36:26 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 18:01:40 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*cut_dq(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(strlen(str) - 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\'')
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

int	syntax_precheck(t_token	*head)
{
	t_token	*temp;

	temp = head;
	while (temp)
	{
		if ((temp->type == PIPE && !temp->prev) || (temp->type == PIPE && !temp->next) || (temp->type == PIPE && temp->next->type == PIPE) || (temp->type == PIPE && temp->next->type > PIPE))
		{
			printf("syntax error near unexpected token `|'\n");
			return (1);
		}
		else if ((temp->type > PIPE && !temp->next) || (temp->type > PIPE && temp->next->type > PIPE))
		{
			printf("syntax error near unexpected token `newline'\n");
			return (1);
		}
		else
			temp = temp->next;
	}
	return (0);
}


