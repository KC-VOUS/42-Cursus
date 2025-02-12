#include "../lexer.h"

int	export(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tokens[i])
	{
		j = 0;
		while (data->tokens[i][j] && data->tokens[i][j] != '=')
			j++;
		if (data->tokens[i][j] == '=')
		{
			data->envcpy = malloc(sizeof(char *) * (count_tab(data->envcpy) + 2));
			if (!data->envcpy)
				return (1);
			data->envcpy[count_tab(data->envcpy) + 1] = NULL;
			data->envcpy[count_tab(data->envcpy)] = ft_strdup(data->tokens[i]);
			if (!data->envcpy[count_tab(data->envcpy)])
				return (1);
		}
		i++;
	}
	return (0);
}

int	unset(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tokens[i])
	{
		j = 0;
		while (data->envcpy[j] && strncmp(data->envcpy[j], data->tokens[i], strlen(data->tokens[i])) != 0)
			j++;
		if (data->envcpy[j])
		{
			free(data->envcpy[j]);
			while (data->envcpy[j])
			{
				data->envcpy[j] = data->envcpy[j + 1];
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envcpy[i])
	{
		printf("%s\n", data->envcpy[i]);
		i++;
	}
	return (0);
}


int	cd(t_data *data)
{
	int	i;

	i = 0;
	while (data->tokens[i])
		i++;
	if (i == 1)
	{
		chdir(data->envcpy[0] + 5);
		return (0);
	}
	if (chdir(data->tokens[1]) == -1)
	{
		printf("cd: %s: No such file or directory\n", data->tokens[1]);
		return (1);
	}
	return (0);
}



int	pwd(t_data *data)
{
	char	*pwd;

	while (data->envcpy)
	{
		if (strncmp(data->envcpy[0], "PWD=", 4) == 0)
		{
			pwd = ft_strdup(data->envcpy[0] + 4);
			printf("%s\n", pwd);
			free(pwd);
			return (0);
		}
		data->envcpy++;
	}
	return (1);
}

int	echo(t_data *data)
{
	int	i;

	i = 1;
	while (data->tokens[i])
	{
		printf("%s", data->tokens[i]);
		i++;
		if (data->tokens[i])
			printf(" ");
	}
	printf("\n");
	return (0);
}

int	builtin(t_data *data)
{
	if (strncmp(data->tokens[0], "export", 7) == 0)
		return (export(data));
	if (strncmp(data->tokens[0], "unset", 6) == 0)
		return (unset(data));
	if (strncmp(data->tokens[0], "env", 4) == 0)
		return (env(data));
	if (strncmp(data->tokens[0], "cd", 3) == 0)
		return (cd(data));
	if (strncmp(data->tokens[0], "pwd", 4) == 0)
		return (pwd(data));
	if (strncmp(data->tokens[0], "echo", 5) == 0)
		return (echo(data));
	return (1);
}
