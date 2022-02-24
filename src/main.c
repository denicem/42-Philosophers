/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:16:14 by dmontema          #+#    #+#             */
/*   Updated: 2022/02/21 22:49:04 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		init_data(argv);
		for (int i = 0; i < data()->count_philos; i++)
			pthread_join(data()->philos[i]->p_id, NULL);
	}
	else
		printf("ERROR: Wrong number of arguments!\n");
	return (0);
}
