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

#include <create_envp_list.h>

static void	take_value(t_envp_list **list, char **envp)
{
	int			i;
	t_envp_list	*temp;

	temp = (*list);
	i = 0;
	while (envp[i])
	{
		temp->value = ft_strdup((ft_strchr(envp[i], '=') + 1));
		temp = temp->next;
		i++;
	}
	return ;
}

static void	take_key_name(t_envp_list **list, char **envp)
{
	int			i;
	int			b;
	t_envp_list	*tmp;

	tmp = (*list);
	i = 0;
	while (envp[i])
	{
		tmp->id_name = ft_malloc(1, 0);
		b = 0;
		while (envp[i][b] != '=')
		{
			tmp->id_name[b] = envp[i][b];
			b++;
			tmp->id_name = realloc(tmp->id_name, (b + 1));
		}
		tmp->id_name[b] = '\0';
		tmp->id = i;
		tmp->next = ft_malloc(sizeof(t_envp_list), 0);
		tmp = tmp->next;
		tmp->next = NULL;
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
	take_key_name(&envp_list, envp);
	take_value(&envp_list, envp);
	return (envp_list);
}
