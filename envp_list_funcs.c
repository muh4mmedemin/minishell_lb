/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:02:42 by muayna            #+#    #+#             */
/*   Updated: 2026/01/07 15:12:25 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

t_envp_list *find_node_address(t_envp_list **source_list, char *id_name)
{
	t_envp_list *tmp;

	tmp = (*source_list);
	if(source_list == NULL || id_name == NULL)
		return NULL;
	while(tmp != NULL)
	{
		if(ft_strcmp(tmp->id_name, id_name) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
