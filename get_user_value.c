/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:42:36 by muayna            #+#    #+#             */
/*   Updated: 2026/01/08 13:40:29 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <minishell_lb.h>

#define COLOR_WHITE "\033[1;37m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_PURPLE "\033[1;35m"
#define RL_START "\001"
#define RL_END "\002"

char *find_value_on_file(const char *path, const char *v_name, const char separate_character)
{
    int fd;
    char *line;
    char **splited_line;

    fd = open(path, O_RDONLY, 0777);
    line = sort_term_strdup(" ");
    while(line != NULL)
    {
        line = get_next_line(fd);
        if(line != NULL)
        {
            splited_line = ft_split(line, separate_character);
            if(ft_strcmp(splited_line[0], v_name) == 0)
            {
                free(line);
                line = sort_term_strdup(splited_line[1]);
                clear_arr(&splited_line);
                return line;
            }
            clear_arr(&splited_line);
            free(line);
        }
    }
    return ft_strdup("user");
}

int check_same_value(const char *source, const char *v_name, const char separate_character)
{
    char **splitted_source;
    int i;

    i = 0;
    splitted_source = ft_split(source, separate_character);
    while(splitted_source[i])
    {
        if(ft_strcmp(splitted_source[i], v_name) == 0)
        {
            clear_arr(&splitted_source);
            return 1;
        }
        i++;
    }
    clear_arr(&splitted_source);
    return 0;
}

char *find_value_on_passwd(const char *path, const char *v_name, const char separate_character)
{
    int fd;
    char *line;
    char *tmp;

    fd = open(path, O_RDONLY, 0777);
    line = sort_term_strdup(" ");
    while(line != NULL)
    {
        line = get_next_line(fd);
        if (line != NULL)
        {
            if(check_same_value(line, v_name, separate_character))
            {
                tmp = sort_term_strdup(line);
                free(line);
                return tmp;
            }
            free(line);
        }
    }
    return NULL;
}

char *get_user_name()
{
    char *uid;
    char *passwd_line;
    char *user_name;
    char **splited_passwd_line;
    
    uid = find_value_on_file("/proc/self/status", "Uid:", '\t');
    if(uid == NULL)
        return ("user");
    passwd_line = find_value_on_passwd("/etc/passwd", uid, ':');
    if(passwd_line == NULL)
        return ("user");
    splited_passwd_line = ft_split(passwd_line, ':');
    user_name = sort_term_strdup(splited_passwd_line[0]);
    clear_arr(&splited_passwd_line);
    return (user_name);
}

char *get_pc_name()
{
    int fd;
    static char *pc_name;
    char *tmp;

    if(pc_name == NULL)
    {
        fd = open("/etc/hostname", O_RDONLY, 0777);
        pc_name = get_next_line(fd);
        tmp = pc_name;
        pc_name = cut_wrong_chracter(pc_name);
        free(tmp);
        return pc_name;
    }
    else
        return pc_name;
    return "pc";
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

    (void)list;
    pc_name = get_pc_name();
    prompt = get_user_name();
    prompt = sort_term_strjoin(sort_term_strjoin(RL_START COLOR_GREEN RL_END, prompt), "@");
    prompt = sort_term_strjoin(prompt, pc_name);
    prompt = sort_term_strjoin(prompt, RL_START "\033[1;37m:" RL_END);
	location = get_location();
    prompt = sort_term_strjoin(prompt, location);
    prompt = sort_term_strjoin(prompt, RL_START "\033[0;37m$ " RL_END);
    (void)envp;
    return prompt;
}
