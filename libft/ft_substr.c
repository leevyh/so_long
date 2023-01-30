/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:03:39 by lkoletzk          #+#    #+#             */
/*   Updated: 2022/11/22 12:27:27 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	else if (len + start >= ft_strlen(s))
		result = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}

/*#include <stdio.h>
int	main()
{
	char	s_substr[] = "tripouille";
	char	*result_substr = ft_substr(s_substr, 0, 42000);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	result_substr = ft_substr(s_substr, 1, 1);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	result_substr = ft_substr(s_substr, 100, 1);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	char	s_substr2[] = "1";
	result_substr = ft_substr(s_substr2, 42, 42000000);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	char	s_substr3[] = "0123456789";
	result_substr = ft_substr(s_substr3, 9, 10);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	char	s_substr4[] = "42";
	result_substr = ft_substr(s_substr4, 0, 0);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	char	s_substr6[] = "BONJOUR LES HARICOTS !";
	result_substr = ft_substr(s_substr6, 8 , 14);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");

	char	s_substr5[] = "test";
	result_substr = ft_substr(s_substr5, 1, 2);
	printf("%s\n", result_substr);
	free(result_substr);
	printf("\n");
}*/
