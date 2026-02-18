/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:31:34 by muayna            #+#    #+#             */
/*   Updated: 2025/12/13 13:31:34 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

void	update_envp_value(t_envp_list **list, char *id_name, char *new_value)
{
	t_envp_list	*temp;

	temp = (*list);
	while (temp != NULL)
	{
		if (!ft_strcmp(temp->id_name, id_name))
		{
			if (temp->value == NULL)
				temp->isvaluempty = 0;
			temp->value = long_term_strdup(new_value);
			if (temp->value == NULL)
				return ;
			break ;
		}
		temp = temp->next;
	}
}

static void	take_value(t_envp_list **list, char **envp)
{
	int			i;
	t_envp_list	*temp;

	temp = (*list);
	i = 0;
	while (envp[i])
	{
		temp->value = long_term_strdup((ft_strchr(envp[i], '=') + 1));
		if (temp->value == NULL)
			return ;
		temp = temp->next;
		i++;
	}
	return ;
}

t_envp_list	*create_envp_list(char **envp)
{
	t_envp_list	*envp_list;

	if (envp == NULL)
		return (NULL);
	envp_list = ft_malloc(sizeof(t_envp_list), 0);
	if (envp_list == NULL)
		return (NULL);
	take_key_name(&envp_list, envp);
	take_value(&envp_list, envp);
	return (envp_list);
}
