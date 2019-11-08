/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:24:00 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/04 12:32:24 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//static void	ft_floop(char const *s, char c, int i, int *n)
//{
//	while (s[i])
//	{
//		if (s[i] != c)
//		{
//			while (s[i] && s[i] != c)
//				i++;
//			(*(n))++;
//		}
//		i++;
//	}
//}
//
//static int	ft_free(char **ar, int n)
//{
//	while (n >= 0)
//	{
//		ft_strdel(&(ar[n]));
//		n--;
//	}
//	free(ar);
//	return (-1);
//}
//
//static void	ft_null(size_t *len, size_t *lens, int *i)
//{
//	*len = 0;
//	*lens = 0;
//	*i = 0;
//}
//
//static int	ft_sloop(char const *s, char c, int n, char **ar)
//{
//	size_t	len;
//	size_t	lens;
//	int		i;
//
//	ft_null(&len, &lens, &i);
//	while (s[i] != '\0')
//	{
//		if (s[i] && s[i] != c)
//		{
//			len = ft_strchlen((s + i), c);
//			i += len;
//			if (!(ar[n] = (char *)ft_memalloc(len + 1)))
//				return (ft_free(ar, n));
//			ar[n][len] = '\0';
//			lens = len;
//			while (len--)
//				ar[n][len] = s[i - lens + len];
//			len = 0;
//			n++;
//		}
//		if (s[i])
//			i++;
//	}
//	return (0);
//}
//
//char		**ft_strsplit(char const *s, char c)
//{
//	int		n;
//	int		i;
//	char	**ar;
//
//	if (!s)
//		return (0);
//	n = 0;
//	i = 0;
//	ft_floop(s, c, i, &n);
//	if (!(ar = (char **)ft_memalloc(sizeof(char *) * (n + 1))))
//		return (0);
//	ar[n] = 0;
//	n = 0;
//	if (ft_sloop(s, c, n, ar) == -1)
//		ar = 0;
//	return (ar);
//}

static char			*fill_word(char **s, char c)
{
	char *word;
	char *head_word;
	char *tail_word;

	head_word = *s;
	while (**s && **s != c)
		(*s)++;
	tail_word = *s;
	*s = head_word;
	word = (char *) malloc(tail_word - head_word + 1);
	if (!word)
		return (NULL);
	head_word = word;
	while (*s < tail_word)
	{
		*word = **s;
		word++;
		(*s)++;
	}
	*word = '\0';
	return (head_word);
}

static size_t		word_count(char const *s, char c)
{
	size_t		counter;
	counter = 0;
	if (*s && (*s != c))
		counter++;
	while (*s && *(s + 1))
	{
		if ((*s == c) && (*(s + 1) != c))
			counter++;
		s++;
	}
	return (counter);
}

static	void		free_ar(char **tab, size_t count)
{
	size_t		i;
	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char			**main_split(char c, char **tab, char **fast_str,
									size_t *al_words)
{
	char	**head_tab;
	head_tab = tab;
	if (**fast_str && (**fast_str != c))
	{
		if (!(*tab = fill_word(fast_str, c)))
			return (NULL);
		al_words++;
		tab++;
	}
	while (**fast_str && *(*fast_str + 1))
		if (((*(*fast_str)++ == c) && (**fast_str != c)))
		{
			if (!(*tab++ = fill_word(fast_str, c)))
				return (NULL);
			al_words++;
		}
	*tab = NULL;
	return (head_tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**fast_str;
	size_t	w_c;
	w_c = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (word_count(s, c) + 1))))
		return (NULL);
	if (!(fast_str = (char**)malloc(sizeof(char*))))
	{
		free(tab);
		return (NULL);
	}
	*fast_str = (char*)s;
	tab = main_split(c, tab, fast_str, &w_c);
	if (!tab)
		free_ar(tab, w_c);
	free(fast_str);
	return (tab);
}
