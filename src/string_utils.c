/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 19:07:57 by cdahlhof          #+#    #+#             */
/*   Updated: 2025-08-05 19:07:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char c, char *s)
{
	if (!s)
		return (NULL);
	while (s && *s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (s && c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if ((char)c == '\0')
		return (((char *)s) + i);
	if (j == -1)
		return (NULL);
	return (((char *)s) + j);
}
