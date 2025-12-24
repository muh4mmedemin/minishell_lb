/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enpv_list_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:48:11 by muayna            #+#    #+#             */
/*   Updated: 2025/12/20 16:48:11 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

static int size_of_envp_list(t_envp_list *envp_list)
{
	int	i;

	i = 0;
	if(envp_list == NULL)
		return 0;
	while(envp_list->next != NULL)
	{
		envp_list = envp_list->next;
		i++;
	}
	return i;
}

char **envp_list_to_char_arr(t_envp_list *envp_list)
{
	char **str;
	int size_envp_list;
	int i;
	char *tmp;

	i = 0;
	size_envp_list = size_of_envp_list(envp_list);
	str = ft_malloc((size_envp_list + 1) * sizeof(char*), 0);
	str[size_envp_list] = NULL;
	while(envp_list->next != NULL)
	{
		str[i] = ft_malloc(ft_strlen(envp_list->id_name) + ft_strlen(envp_list->value) + 2, 0);
		tmp = ft_strjoin(envp_list->id_name, "=");
		str[i] = ft_strjoin(tmp, envp_list->value);
		free(tmp);
		envp_list = envp_list->next;
		i++;
	}
	return str;
}

void print_envp_linked_list(t_envp_list *envp_list)
{
	if(envp_list == NULL)
		return ;
	while (envp_list->next != NULL)
	{
		printf("%s=%s", envp_list->id_name, envp_list->value);
		envp_list = envp_list->next;		
	}
	return ;
}
