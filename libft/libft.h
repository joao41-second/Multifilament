/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:36:29 by jperpect          #+#    #+#             */
/*   Updated: 2024/05/01 13:10:59 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// # include <aio.h>
// # include <bsd/string.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
// # include <strings.h>
# include <unistd.h>

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

void				*ft_memmove(void *dest, const void *src, size_t n);
/**
* @brief move de bitts of the memori to destany.
* @param dest variavel that get bitts.
* @param src  variavel with bitts to move.
* @return void variabel dest.
*/
void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

int					ft_atoi(const char *nptr);
/**
* @brief convert char in int.
* @param nptr nuber in variabel char. 
* @return nuber in variabel int. 
*/

void				*ft_calloc(size_t nmemb, size_t size);
/**
* @brief create a variable with memory reserved.
* @param nemeb number de menbers os de valiabel. 
* @param size number de bittes fo menber.
* @return variabel zered .
*/

char				*ft_strdup(const char *s);
/**
* @brief copy a sting to new string.
* @param s setring to copy.
* @return string compyed. 
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
/**
* @brief copy  string  as of start.
* @param s setring inicals.
* @param start carecter the substring satarted
* @param len max_len the substring.
* @return substring inicialeze in.
*/

char				*ft_strjoin(char const *s1, char const *s2);
/**
* @brief concatenation of two strings. 
* @param s1 first string.
* @param s2 second string.
* @return reutnr a concatenation of s1 and s2.
*/

char				*ft_strtrim(char const *s1, char const *set);
/**
* @brief remuve *set caraters up to meet it difrent to set caracter.
* @param s1 string complit;
* @param set caracters to remuve;
* @return a string without os cararteres de set 
*/

char				**ft_split(char const *s, char c);
/**
* @brief separite a string in words baseated in caractre c.
* @param s string to division. 
* @param c caractre to marcard divison.
* @return list separated in word
*/

char				*ft_itoa(int n);
/**
* @brief tranform int to char. 
* @param n number in int.
* @return char wtid memory aloceted. 
*/

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
* @brief excute a funcion f in all elements of s.
* @param s strimg where aplicate a funcion .
* @param f funcion that get unsigned int and char.
*/

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
* @brief excute a funcion f in all elements of s.
* @param s strimg where aplicate a funcion .
* @param f funcion that get unsigned int and char*.
*/

void				ft_putchar_fd(char c, int fd);
/**
* @brief display a char c in terminal
* @param c char display.
* @param fd filed
*/

void				ft_putstr_fd(char *s, int fd);
/**
* @brief display a string s in terminal
* @param s char display.
* @param fd filed
*/

void				ft_putendl_fd(char *s, int fd);
/**
* @brief display a string s in terminal next new line
* @param s char display.
* @param fd filed
*/
void				ft_putnbr_fd(int n, int fd);
/**
* @brief display a int n in terminal
* @param n int displayed.
* @param fd filed.
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif

/**
     * @brief Subtracts one number from another.
     * @param a The first number.
     * @param b The second number.
     * @return The result of subtracting b from a.
     */