/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:08 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/09 13:25:34 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

typedef struct a_list
{
	void			*content;
	struct a_list	*next;
}	t_list_libft;

t_list_libft	*ft_lstnew(void *content);
void			ft_lstadd_front(t_list_libft **lst, t_list_libft *new);
int				t_lstsize(t_list_libft *lst);
t_list_libft	*ft_lstlast_libft(t_list_libft *lst);
void			ft_lstadd_back(t_list_libft **lst, t_list_libft *new);
void			ft_lstdelone(t_list_libft *lst, void (*del)(void*));
void			ft_lstclear(t_list_libft **lst, void (*del)(void*));
void			ft_lstiter(t_list_libft *lst, void (*f)(void *));
t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *),
					void (*del)(void *));

/* GWET NEXT LINE */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char			*get_next_line(int fd);
int				len_to_new_line(t_list *list);
void			copy_str(t_list *list, char *str);
void			append(t_list **list, char *buf);
void			create_list(t_list **list, int fd);
void			clean_list(t_list **list);
char			*get_line(t_list *list);
t_list			*ft_lstlast(t_list *lst);
void			dealloc(t_list **list, t_list *clean_node, char *buf);
int				found_newline(t_list *list);

/* FT PRINTF */

int				ft_printf(const char *format, ...);
int				print_format(char c, va_list ap);
int				ft_putnbr(int n);
int				ft_puthex(unsigned long long n, int uppercase);
int				ft_putptr(void *ptr);
int				ft_putstr(char *str);
int				ft_putunsigned(unsigned int n);

#endif