#include "../lexer.h"

void	remove_node(t_token **head, t_token *node)
{
	if (!node)
		return;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (*head == node)
		*head = node->next;
	free(node->token);
	free(node);
}

t_token	*merge_args(t_token *head)
{
	t_token	*curr;
	t_token	*next;
	t_token	*to_remove;
	char	*merged;

	curr = head;
	while (curr)
	{
		if (curr->type < PIPE && curr->type > ESPACE)
		{
			next = curr->next;
			while (next && next->type < PIPE && next->type > ESPACE)
			{
				merged = malloc(strlen(curr->token) + strlen(next->token) + 1);
				if (!merged)
					return (NULL);
				strcpy(merged, curr->token);
				strcat(merged, next->token);
				free(curr->token);
				curr->token = merged;
				to_remove = next;
				next = next->next;
				remove_node(&head, to_remove);
			}
		}
		curr = curr->next;
	}
	return (head);
}

t_token	*remove_spaces(t_token *head)
{
	t_token *curr;
	t_token *next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		if (curr->type == ESPACE)
			remove_node(&head, curr);
		curr = next;
	}
	return (head);
}
