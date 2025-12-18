/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:30:04 by muayna            #+#    #+#             */
/*   Updated: 2025/12/13 13:30:04 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ENVP_LIST_H
# define CREATE_ENVP_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <libft.h>
# include <gb.h>

typedef struct s_envp_list
{
	char				*id_name;
	int					id;
	char				*value;
	struct s_envp_list	*next;

}	t_envp_list;

t_envp_list	*create_envp_list(char **envp);

#endif