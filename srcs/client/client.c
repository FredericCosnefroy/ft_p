/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 19:13:13 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/04/04 12:35:52 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../libft/libft.h"
#include <sys/param.h>
#include <fcntl.h>

typedef struct	s_client
{
	int			sock;
	char		*sroot;
	char		*spwd;
	char		*lroot;
	char		*lpwd;
}				t_client;

void	usage(char *str)
{
	printf("Usage : %s <addr> <port>\n", str);
	exit(-1);
}

void	get_pwds(t_client *client, int init)
{
	char *home;

	if (init)
	{
		home = getenv("HOME");
		get_next_line(client->sock, &(client->sroot));
		if (home)
			client->lroot = ft_strdup(home);
		else
		{
			client->lroot = malloc(MAXPATHLEN);
			client->lroot = getcwd(client->lroot, MAXPATHLEN);
			if (ft_strlen(client->lroot) >= 13)
				client->lroot = ft_strdup(client->lroot + 13);
		}
		client->spwd = ft_strdup(client->sroot);
		client->lpwd = malloc(MAXPATHLEN);
		client->lpwd = getcwd(client->lpwd, MAXPATHLEN);
		if (ft_strlen(client->lpwd) >= 13)
			client->lpwd = ft_strdup(client->lpwd + 13);
		return ;
	}
	free(client->spwd);
	free(client->lpwd);
	get_next_line(client->sock, &(client->spwd));
	client->lpwd = malloc(MAXPATHLEN);
	client->lpwd = getcwd(client->lpwd, MAXPATHLEN);
	if (ft_strlen(client->lpwd) >= 13)
		client->lpwd = ft_strdup(client->lpwd + 13);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(!ft_strcmp(addr, "localhost") ? "127.0.0.1" : addr);
	if ((connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		printf("Connect Error.\n");
		exit(0);
	}
	return (sock);
}

int		exec_lcd(t_client *client, char **request)
{
	int		ret;

	ret = -1;
	if (!request[1] || (*request[1] == '~' && !request[1][1]))
		ret = chdir(client->lroot);
	if (!request[2])
		ret = chdir(request[1]);
	get_pwds(client, 0);
	return (ret);
}

int		exec_put(t_client *client, char **request)
{
	char	*line;
	int		fd;

	if (!request[1] || request[2])
		return (-1);
	if ((fd = open(request[1], O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr_fd(line, client->sock);
		ft_putchar_fd('\n', client->sock);
		free(line);
	}
	ft_putchar_fd(EOF, client->sock);
	ft_putchar_fd('\n', client->sock);
	get_pwds(client, 0);
	close(fd);
	return (0);
}

int		exec_get(t_client *client, char **request)
{
	char	*line;
	int		fd;

	if (!request[1] || request[2])
		return (-1);
	if ((fd = open(request[1], O_RDONLY)) >= 0)
	{
		ft_putchar_fd(EOF, client->sock);
		ft_putchar_fd('\n', client->sock);
		get_pwds(client, 0);
		close(fd);
		return (-1);
	}
	else
		ft_putchar_fd('\n', client->sock);
	if ((fd = open(request[1], O_WRONLY | O_CREAT, 0644)) < 0)
		return (-1);
	while (get_next_line(client->sock, &line) > 0 && *line != EOF)
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
	}
	close(fd);
	return (0);
}

void	get_response(t_client *client)
{
	char	*line;

	while (get_next_line(client->sock, &line) > 0 && *line != EOF)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
}

void	exec_lpwd(t_client *client, char **request)
{
	(void)request;
	ft_putstr(client->lpwd);
	ft_putchar('\n');
	get_pwds(client, 0);
}

int		exec_lls(t_client *client, char **request)
{
	int		pid;
	int		status;

	(void)client;
	pid = fork();
	if (pid == 0)
	{
		execv("/bin/ls", request);
		exit(-1);
	}
	wait4(pid, &status, 0, 0);
	get_pwds(client, 0);
	return (status);
}

void	read_server(t_client *client, char **request)
{
	if (ft_strequ(request[0], "get"))
		exec_get(client, request);
	else if (ft_strequ(request[0], "put"))
		exec_put(client, request);
	else if (ft_strequ(request[0], "lcd"))
		exec_lcd(client, request);
	else if (ft_strequ(request[0], "lpwd"))
		exec_lpwd(client, request);
	else if (ft_strequ(request[0], "lls"))
		exec_lls(client, request);
	else
		get_response(client);
	get_response(client);
}

int		print_prompt(const t_client *client)
{
	(void)client;
	int		llen;
	int		slen;
	char	*tmp;

	slen = ft_strlen(client->sroot);
	llen = ft_strlen(client->lroot);
	STR_FORMAT_SET("", STR_BOLD, STR_YELLOW);
	if (ft_strnequ(client->sroot, client->spwd, slen))
	{
		ft_putstr("~");
		tmp = client->spwd + slen;
	}
	else
		tmp = client->spwd;
	ft_putstr(tmp);
	STR_FORMAT_SET("", "", STR_GREY);
	ft_putstr(" | ");
	STR_FORMAT_SET("", STR_BOLD, STR_CYAN);
	if (ft_strnequ(client->lroot, client->lpwd, llen))
	{
		ft_putstr("~");
		tmp = client->lpwd + llen;
	}
	else
		tmp = client->lpwd;
	ft_putstr(tmp);
	STR_FORMAT_SET("", "", STR_GREY);
	ft_putstr(" $ ");
	return (1);
}

t_client	*client_mem(t_client *client)
{
	static t_client *mem_client = NULL;

	if (!mem_client)
		mem_client = client;
	return (mem_client);
}

void 	sig_handler(int sig)
{
	t_client *client;
	(void) sig;

	client = client_mem(NULL);
	ft_putstr_fd("exit", client->sock);
	ft_putchar_fd('\n', client->sock);
	ft_putchar('\n');
	get_response(client);
	get_response(client);

	close(client->sock);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_client				client;
	int						port;
	char					*line;
	char					**request;
	char					closed;

	signal(SIGINT, sig_handler);
	if (argc != 3)
		usage(argv[0]);
	port = atoi(argv[2]);
	client.sock = create_client(argv[1], port);
	get_pwds(&client, 1);
	client_mem(&client);
	closed = 0;
	while (!closed && print_prompt(&client) && (get_next_line(0, &line)) > 0)
	{
		request = ft_strsplit(line, ' ');
		if (*line && request[0] && *request[0])
		{
			if (!ft_strcmp(request[0], "exit") && !request[1])
				closed = 1;
			ft_putstr_fd(line, client.sock);
			ft_putchar_fd('\n', client.sock);
			read_server(&client, request);
			get_pwds(&client, 0);
		}
		free(line);
	}
	close(client.sock);
	return (0);
}
