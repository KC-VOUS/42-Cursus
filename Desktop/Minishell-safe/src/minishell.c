/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:35:27 by sdakhlao          #+#    #+#             */
/*   Updated: 2025/02/11 17:55:20 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*prompt(void)
{
	return (readline("\033[38;5;13mminishell $> \033[38;5;42m"));
}

char	**malloc_free(char	**tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

void	free_envcpy(char **envcpy)
{
	int	i;

	i = 0;
	while (envcpy[i])
	{
		free(envcpy[i]);
		i++;
	}
	free(envcpy);
}

void	ft_exit(t_data *data)
{
	malloc_free(data->tokens);
	free(data->brut_input);
	free_envcpy(data->envcpy);
	free(data);
	exit(EXIT_SUCCESS);
}

void	programm(t_data *data)
{
	data->brut_input = prompt();
	while (1)
	{
		if (!data->brut_input || strncmp(data->brut_input, "exit", 4) == 0)
		{
			free(data->brut_input);
			free_envcpy(data->envcpy);
			free(data);
			exit(EXIT_SUCCESS);
		}
		if (data->brut_input)
			add_history(data->brut_input);
		if (lexer(data))
			ft_exit(data);
		// builtin(data);
		free(data->brut_input);
		if (data->tokens)
			malloc_free(data->tokens);
		data->brut_input = prompt();
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->envcpy = cpenv(envp);
	programm(data);
	free_envcpy(data->envcpy);
	(void)ac;
	(void)av;
}
