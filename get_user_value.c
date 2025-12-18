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

#include <get_user_value.h>

char *get_user_name(t_envp_list **list)
{
    char *user_name;

    user_name = find_value_on_envp(list, "USER");
    if(user_name == NULL)
        return NULL;
    user_name = ft_strjoin(COLOR_GREEN, user_name);
    return (user_name);
}

static char *get_session_name(void)
{
    char *pc_name;
    int pipefd[2];
    pid_t pid;
    char **cmd;

    cmd = ft_split("hostname", ' ');
    pc_name = NULL;
    pipe(pipefd);
    pid = fork();
    if(pid == 0)
    {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
        execve("/bin/hostname", cmd, NULL);
        exit(1);
    }
    else
    {
        free(cmd);
        close(pipefd[1]);
        pc_name = get_next_line(pipefd[0]);
        close(pipefd[0]);
    }
    return pc_name;
}

char *get_pc_name(t_envp_list **list)
{
    char *pc_name;

    pc_name = find_value_on_envp(list, "HOSTNAME");
    if(pc_name == NULL)
    {
        pc_name = get_session_name();
        if(pc_name == NULL)
            NULL;
        return pc_name;
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
    location = ft_strjoin(COLOR_PURPLE, buf);
    return (location);
}

char *rl_header(t_envp_list **list, char **envp)
{
    char *prompt;
    char *temp;

    prompt = get_user_name(list);
    temp = prompt;
    prompt = ft_strjoin(prompt, "@");
    free(temp);
    temp = prompt;
    prompt = ft_strjoin(prompt, get_pc_name(list));
    free(temp);
    temp = prompt;
    prompt = cut_wrong_chracter(prompt);
    free(temp);
    temp = prompt;
    prompt = ft_strjoin(prompt, "\033[1;37m:");
    temp = prompt;
    prompt = ft_strjoin(prompt, get_location());
    free(temp);
    temp = prompt;
    prompt = ft_strjoin(prompt, "\033[1;37m$ ");
    free(temp);
    (void)envp;
    return prompt;
}
