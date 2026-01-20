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

char	*find_id_name_on_envp(t_envp_list **list, char *value_id_name)
{
	t_envp_list *temp;

    temp = (*list);
	if(temp == NULL || value_id_name == NULL)
        return NULL;
    while(temp != NULL)
    {
        if(!ft_strcmp(temp->id_name, value_id_name))
            return temp->id_name; 
        temp = temp->next;
    }
    return NULL;
}

char	*find_value_on_envp(t_envp_list **list, char *value_id_name)
{
    t_envp_list *temp;

    temp = (*list);
	if(temp == NULL || value_id_name == NULL)
        return NULL;
    while(temp != NULL)
    {
        if(!ft_strcmp(temp->id_name, value_id_name))
            return temp->value; 
        temp = temp->next;
    }
    return NULL;
}

int size_of_envp_list(t_envp_list *envp_list)
{
	int	i;

	i = 0;
	if(envp_list == NULL)
		return 0;
	while(envp_list != NULL)
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
	str = malloc((size_envp_list + 1) * sizeof(char*));
	if(str == NULL)
		return NULL;
	str[size_envp_list] = NULL;
	while(envp_list != NULL)
	{
		tmp = sort_term_strjoin(envp_list->id_name, "=");
		str[i] = ft_strjoin(tmp, envp_list->value);
		if(str[i] == NULL)
			return NULL;
		envp_list = envp_list->next;
		i++;
	}
	return str;
}

void print_envp_linked_list(t_envp_list *envp_list)
{
	if(envp_list == NULL)
		return ;
	while (envp_list != NULL)
	{
		if(envp_list->isvaluempty == 0)
			printf("%s=%s\n", envp_list->id_name, envp_list->value);
		envp_list = envp_list->next;		
	}
	return ;
}
