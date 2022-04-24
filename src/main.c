/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/04/25 00:38:57 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 5 || argc == 6)
	{
		init_data(argv);
		i = 0;
		while (i < (data()->count_philos))
		{
			pthread_join(data()->philos[i]->p_id, NULL);
			i++;
		}
	}
	else
		printf("ERROR: Wrong number of arguments!\n");
	return (0);
}
