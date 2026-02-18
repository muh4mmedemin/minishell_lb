/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envp_list_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:27:07 by muayna            #+#    #+#             */
/*   Updated: 2026/02/18 15:28:26 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

static int	special_strlen(char *str, char until_char)
{
	int	i;

	if (str == NULL || until_char == '\0')
		return (0);
	i = 0;
	while (str[i] && str[i] != until_char)
		i++;
	return (i);
}

static void take_key_name_for_norm(t_envp_list **list, int b)
{
	(*list)->isvaluempty = 0;
	(*list)->id_name[b] = '\0';
	(*list)->next = NULL;
}

void	take_key_name(t_envp_list **list, char **envp)
{
	int			i;
	int			b;
	t_envp_list	*tmp;

	tmp = (*list);
	i = 0;
	while (envp[i])
	{
		tmp->id_name = ft_malloc(special_strlen(envp[i], '=') + 1, 0);
		b = 0;
		while (envp[i][b] != '=' && envp[i][b])
		{
			tmp->id_name[b] = envp[i][b];
			b++;
		}
		take_key_name_for_norm(&tmp, b);
		if (envp[i + 1])
			tmp->next = ft_malloc(sizeof(t_envp_list), 0);
		if (envp[i + 1] && tmp->next == NULL)
			return ;
		tmp = tmp->next;
		i++;
	}
	return ;
}