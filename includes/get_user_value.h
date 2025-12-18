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

#ifndef GET_USER_VALUE_H
# define GET_USER_VALUE_H

#define COLOR_WHITE "\033[1;37m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_PURPLE "\033[1;35m"

#include <libft.h>
#include <gb.h>
#include <create_envp_list.h>
#include <get_next_line.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_user_name(t_envp_list **list);
char *get_location(void);
char *get_pc_name(t_envp_list **list);
char *rl_header(t_envp_list **list, char **envp);

#endif