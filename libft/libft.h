/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:26:57 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/21 17:59:01 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

# define STR_FORMAT(F1, F2, F3, STR)	"\e["F1";"F2";"F3"m"STR"\e[0m"
# define STR_FORMAT_SET(F1, F2, F3)		ft_putstr("\e["F1";"F2";"F3"m")
# define STR_FORMAT_DEFAULT				ft_putstr("\e[0m")
# define STR_DEFAULT					"0"
# define STR_BOLD						"1"
# define STR_UNDERLINE					"4"
# define STR_BLACK						"30"
# define STR_RED						"31"
# define STR_GREEN						"32"
# define STR_YELLOW						"33"
# define STR_BLUE						"34"
# define STR_MAGENTA					"35"
# define STR_CYAN						"36"
# define STR_GREY						"37"

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long int			ft_atoli(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2, int f1, int f2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_llitoa(long long int n);
char				*ft_ullitoa(unsigned long long int n);
char				*ft_uitoa(unsigned int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	int				content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	int				content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*list_add(t_list **list, void const *content,
					size_t content_size);
t_list				*list_mod_i(t_list **list, void *content,
					size_t content_size, int in);
t_list				*list_remove(t_list **list);
t_list				*list_remove_i(t_list	**list, int n);
t_list				*list_remove_first(t_list **list);
t_list				*list_get_i(t_list *list, int index);
t_list				*ft_listdup(t_list *list);
t_list				*path_to_list(char *str, char separator);
int					list_count(t_list *list);
char				*list_to_string(t_list *list, char *separator);
char				**list_to_array(t_list *list);

t_dlist				*ft_dlstnew(const void *content, unsigned int content_size);
void				dlist_add_first(t_dlist **lst, const void *content,
		unsigned int content_size);
void				ft_listdel(t_list **list, const int free_content);
void				ft_arraydel(char ***array);

int					get_next_line(int const fd, char **line);

#endif
