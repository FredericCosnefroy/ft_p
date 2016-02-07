/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 19:13:13 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/04/05 13:19:58 by fcosnefr         ###   ########.fr       */
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
#include <errno.h>

typedef struct	s_server
{
	int			cs;
	char		*sroot;
	char		*spwd;
}				t_server;

typedef struct	s_msg
{
	int			error;
	char		*msg;
}				t_msg;

static const t_msg	g_error[] =
{
	{2, "No such file or directory\n"},
	{13, "Permission denied\n"},
	{22, "Invalid argument\n"},
	{400, "Command not found\n"},
	{401, "put usage\n"},
	{402, "File already exists\n"},
	{403, "No such file or directory\n"},
	{404, "Get usage\n"},
	{405, "pwd usage\n"},
	{406, "Connection closed\n"},
	{-1, NULL},
	{0, NULL}
};

void	usage(char *str)
{
	printf("Usage : %s <port>\n", str);
	exit(-1);
}

char	*get_msg(int error)
{
	int		i;

	i = 0;
	if (error == -1)
		error = errno;
	while (g_error[i].msg)
	{
		if (g_error[i].error == error)
			return (g_error[i].msg);
		i++;
	}
	return ("\n");
}

void	get_pwds(t_server *server, int init)
{
	if (init)
	{
		server->sroot = malloc(MAXPATHLEN);
		server->sroot = getcwd(server->sroot, MAXPATHLEN);
		server->spwd = ft_strdup(server->sroot);
	}
	else
	{
		free(server->spwd);
		server->spwd = malloc(MAXPATHLEN);
		server->spwd = getcwd(server->spwd, MAXPATHLEN);
	}
	ft_putstr_fd(server->spwd, server->cs);
	ft_putchar_fd('\n', server->cs);
}

int		exec_cmd(char **cmd, int cs)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		dup2(cs, STDERR_FILENO);
		dup2(cs, STDOUT_FILENO);
		execv("/bin/ls", cmd);
		ft_putstr_fd("ft_p : Command not found\n", 2);
		exit(-1);
	}
	wait4(pid, &status, 0, 0);
	return (status);
}

void	print_server_status(int error, int client, char **request)
{
	char	*msg;
	char	*cmd;
	
	if (error == 406)
	{
		ft_putstr_fd(STR_FORMAT("", STR_BOLD, STR_GREEN, "[CLIENT SUCESSFULLY DISCONNECTED]"), client);
		ft_putchar_fd('\n', client);
	}
	else if (error)
	{
		msg = get_msg(error);
		cmd = request[0];
		if (error != 400 && error != 401 && error != 404 && error != 405 && request[1])
			cmd = request[1];
		ft_putstr_fd(STR_FORMAT("", STR_BOLD, STR_RED, "[ERROR] "), client);
		if (*msg != '\n')
		{
			ft_putstr_fd(cmd, client);
			ft_putstr_fd(" : ", client);
		}
		ft_putstr_fd(msg, client);
		errno = 0;
	}
	else
	{
		ft_putstr_fd(STR_FORMAT("", STR_BOLD, STR_GREEN, "[SUCCESS]"), client);
		ft_putchar_fd('\n', client);
	}
	ft_putchar_fd(EOF, client);
	ft_putchar_fd('\n', client);
}

int		exec_get(t_server *server, char **request)
{
	char	*line;
	int		fd;

	if (!request[1] || request[2])
		return (404);
	if ((fd = open(request[1], O_RDONLY)) < 0)
		return (2);
	get_next_line(server->cs, &line);
	if (*line == EOF)
	{
		free(line);
		return (402);
	}
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr_fd(line, server->cs);
		ft_putchar_fd('\n', server->cs);
		free(line);
	}
	close(fd);
	return (0);
}

int		exec_cd(t_server *server, char **request)
{
	char	*new_pwd;
	char	*prev;
	int		ret;
	int		len;

	ret = -1;
	prev = server->spwd;
	len = ft_strlen(server->sroot);
	if (!request[1])
		ret = chdir(server->sroot);
	if (!request[2])
		ret = chdir(request[1]);
	new_pwd = malloc(MAXPATHLEN);
	new_pwd = getcwd(new_pwd, MAXPATHLEN);
	if (!ft_strnequ(server->sroot, new_pwd, len))
	{
		chdir(prev);
		ret = 403;
	}
	free(new_pwd);
	return (ret);
}

int		exec_put(t_server *server, char **request)
{
	char	*line;
	int		fd;

	if (!request[1] || request[2])
		return (401);
	if ((fd = open(request[1], O_WRONLY | O_EXCL | O_APPEND | O_CREAT, 0644)) < 0)
		return (-1);
	while (get_next_line(server->cs, &line) > 0 && *line != EOF)
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
	}
	close(fd);
	return (0);
}

int 	exec_exit(t_server *server, char **request)
{
	(void)server;
	if (request[1])
		return (22);
	return (406);
}

int		exec_request(t_server *server, char **request)
{
	if (ft_strequ(request[0], "ls"))
		return (exec_cmd(request, server->cs));
	if (ft_strequ(request[0], "pwd"))
	{
		if (!request[1])
		{
			ft_putstr_fd(server->spwd, server->cs);
			ft_putchar_fd('\n', server->cs);
			return (0);
		}
		else
			return (405);
	}
	if (ft_strequ(request[0], "cd"))
		return (exec_cd(server, request));
	if (ft_strequ(request[0], "get"))
		return (exec_get(server, request));
	if (ft_strequ(request[0], "put"))
		return (exec_put(server, request));
	if (ft_strequ(request[0], "exit"))
		return (exec_exit(server, request));
	if (ft_strequ(request[0], "lcd"))
		return (0);
	if (ft_strequ(request[0], "lpwd"))
		return (0);
	if (ft_strequ(request[0], "lls"))
		return (0);
	return (400);
}

void	read_client(t_server *server)
{
	char	**request;
	char	*line;
	int		error;

	while  (get_next_line(server->cs, &line) > 0)
	{
		if (*line)
		{
			request = ft_strsplit(line, ' ');
			error = exec_request(server, request);
			ft_putchar_fd(EOF, server->cs);
			ft_putchar_fd('\n', server->cs);
			print_server_status(error, server->cs, request);
			get_pwds(server, 0);
		}
		free(line);
		if (error == 406)
			break;
	}
}

void	accept_new_client(int sock)
{
	t_server				server;
	struct sockaddr_in		csin;
	unsigned int			cslen;
	int						pid;

	server.cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	pid = fork();
	if (pid > 0)
	{
		close(server.cs);
		accept_new_client(sock);
	}
	if (pid == 0)
	{
		get_pwds(&server, 1);
		read_client(&server);
		close(server.cs);
		exit(0);
	}
}

int		create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		printf("Bind Error.\n");
		exit(0);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int argc, char **argv)
{
	int						port;
	int						sock;

	if (argc != 2)
		usage(argv[0]);
	port = atoi(argv[1]);
	sock = create_server(port);
	accept_new_client(sock);
	close(sock);
	return (0);
}
