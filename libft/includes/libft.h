/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:41:31 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/29 14:13:30 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define TRUE				1
# define FALSE				0
# define MAXV(a, b)			((a) > (b) ? (a) : (b))
# define MINV(a, b)			((a) < (b) ? (a) : (b))
# include "get_next_line.h"
# include "ft_printf.h"
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strjoind(char *s1, char *s2, int dela, int delb);
int					ft_wcscbytes(int binsize);
void				ft_putstr_until(const char *format, char *c);
int					ft_putstr_unless(const char *format, char *c);
char				*ft_llitob(long long int n);
char				*ft_ullitoa(unsigned long long int n);
char				*ft_ullitoa_base(unsigned long long int v, char *base);
int					ft_binsize(long long int i);
char				*ft_llitoa(long long int n);
size_t				ft_wcslen(const int *wcs);
char				*ft_wcstombs(const int *wcs, long int len);
void				ft_wctomb(char *s, int wc, int l);
void				ft_putxchar(char c, int l);
char				*ft_strndup(const char *s1, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				ft_putendl(char const *c);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
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
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char*s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_isascii(int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));
void				ft_print_bits(unsigned char c);
t_list				*ft_lstnewnext(t_list *lst, void const *content,\
								size_t content_size);
int					ft_strcnt(char *s, char c);
char				**ft_split(char const *s);
char				**ft_tabdup(char **buf);
char				**ft_tabdup_plusone(char **buft, char *buf);
int					ft_tablen(char **buf);
void				ft_free_tab(char ***argv);
void				ft_print_tab(char **tab);
int					ft_strcnts(char const *str, char const *s);

#endif
