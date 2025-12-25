/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:42:36 by muayna            #+#    #+#             */
/*   Updated: 2025/12/17 15:42:36 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

#define COLOR_WHITE "\033[1;37m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_PURPLE "\033[1;35m"

char *get_user_name(t_envp_list **list)
{
    char *user_name;

    user_name = find_value_on_envp(list, "USER");
    if(user_name == NULL)
        return NULL;
    user_name = sort_term_strjoin(COLOR_GREEN, user_name);
    return (user_name);
}

char *get_pc_name(t_envp_list **list)
{
    char *pc_name;

    pc_name = find_value_on_envp(list, "NAME");
    if(pc_name == NULL)
    {
        return "pc";
    }
    else
        return pc_name;
    return NULL;
}

char *get_location(void)
{
    char *location;
    char buf[1024];

    getcwd(buf, 1024);
    location = sort_term_strjoin(COLOR_PURPLE, buf);
    return (location);
}

char *rl_header(t_envp_list **list, char **envp)
{
    char *prompt;
	char *location;
    char *pc_name;

    pc_name = get_pc_name(list);
    prompt = get_user_name(list);
    prompt = sort_term_strjoin(prompt, "@");
    prompt = sort_term_strjoin(prompt, pc_name);
    prompt = sort_term_strjoin(prompt, "\033[1;37m:");
	location = get_location();
    prompt = sort_term_strjoin(prompt, location);
    prompt = sort_term_strjoin(prompt, "\033[1;37m$ ");
    (void)envp;
    return prompt;
}
