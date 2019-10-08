/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:11:15 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/21 15:11:17 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
**	PUT block
*/

int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putstr_until(const char *str, char c);

/*
**	STR block
*/

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	ft_strdel(char **as);
char	*ft_itoa_base(int num, int base);
char	*ft_itoa_ubase(size_t num, int base);
char	*ft_ltoa_base(long long int n, int base);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_leak(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_nchjoinstr(char *str, char c, int n);
char	*ft_chjoinstr(char c, char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strshift(char **str, size_t n);
char	*ft_strjoinch(char **str, char c);
char	*ft_strncat(char *s1, const char *s2, size_t n);

/*
**	MEMORY block
*/

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*
**  OTHER
*/

int		ft_abs(int c);
char	*ft_copyuntil(char *str, int c);
int		ft_isdigit(int c);

#	endif
