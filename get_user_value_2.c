/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_value_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:37:37 by muayna            #+#    #+#             */
/*   Updated: 2026/02/18 15:39:03 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_lb.h>

#define COLOR_WHITE "\033[1;37m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_PURPLE "\033[1;35m"
#define RL_START "\001"
#define RL_END "\002"

char	*get_pc_name(void)
{
	int			fd;
	static char	*pc_name;
	char		*tmp;

	if (pc_name == NULL)
	{
		fd = open("/etc/hostname", O_RDONLY, 0777);
		pc_name = get_next_line(fd);
		close(fd);
		tmp = pc_name;
		pc_name = cut_wrong_chracter(pc_name);
		free(tmp);
		return (pc_name);
	}
	else
		return (pc_name);
	return ("pc");
}

char	*get_location(void)
{
	char	*location;
	char	buf[1024];

	getcwd(buf, 1024);
	location = sort_term_strjoin(RL_START COLOR_PURPLE RL_END, buf);
	if (location == NULL)
		return ("directory");
	return (location);
}
