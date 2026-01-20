/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:42:36 by muayna            #+#    #+#             */
/*   Updated: 2025/12/30 22:24:09 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <minishell_lb.h>

#define COLOR_WHITE "\033[1;37m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_PURPLE "\033[1;35m"
#define RL_START "\001"
#define RL_END "\002"

char *get_user_name(t_envp_list **list)
{
    char *user_name;

    user_name = find_value_on_envp(list, "USER");
    if(user_name == NULL)
        return "user";
    user_name = sort_term_strjoin(RL_START COLOR_GREEN RL_END, user_name);
    if(user_name == NULL)
        return "user";
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
    location = sort_term_strjoin(RL_START COLOR_PURPLE RL_END, buf);
    if(location == NULL)
        return "directory";
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
    prompt = sort_term_strjoin(prompt, RL_START "\033[1;37m:" RL_END);
	location = get_location();
    prompt = sort_term_strjoin(prompt, location);
    prompt = sort_term_strjoin(prompt, RL_START "\033[1;37m$ " RL_END);
    (void)envp;
    return prompt;
}
