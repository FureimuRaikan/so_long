/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:29:32 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/13 12:54:11 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_FUNCTIONS_H
# define STRINGS_FUNCTIONS_H

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
char	*ft_strdup(const char *s);
char	**ft_array_str_dup(char **array);

size_t	ft_strlcat(char *dst, const char *src, size_t siz);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr_free(char *str, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_reverse(char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	**ft_split(char const *s, char c);
char	**ft_split_quote(char const *str, char c, char quote);

char	*get_next_line(int fd);

#endif