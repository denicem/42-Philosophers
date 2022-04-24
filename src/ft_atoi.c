/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:49:04 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 00:40:34 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philosophers.h"

static size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || (c >= '\b' && c <= '\r'))
		return (1);
	return (0);
}

static int	ft_calcres(const char *str, int sign)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (ft_isdigit(*str) - '0');
		if (sign == -1 && res >= INT_MAX)
			return (INT_MIN);
		else if (res >= INT_MAX)
			return (INT_MAX);
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	if (!ft_strlen(str))
		return (0);
	res = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = ft_calcres(str, sign);
	return (res * sign);
}
