/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_value.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:44:55 by muayna            #+#    #+#             */
/*   Updated: 2025/12/17 15:44:55 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LB
# define MINISHELL_LB

#include <libft.h>
#include <gb.h>
#include <get_next_line.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct s_envp_list
{
	char				*id_name;
	int					id;
	char				*value;
	struct s_envp_list	*next;
}	t_envp_list;

char **envp_list_to_char_arr(t_envp_list *envp_list);
t_envp_list	*create_envp_list(char **envp);
char *find_value_on_envp(t_envp_list **list, char *value_id_name);
void update_envp_value(t_envp_list **list, char *id_name, char *new_value);
char  *cut_wrong_chracter(const char *s1);
void	clear_arr(char ***input);

char *get_user_name(t_envp_list **list);
char *get_location(void);
char *get_pc_name(t_envp_list **list);
char *rl_header(t_envp_list **list, char **envp);

#endif