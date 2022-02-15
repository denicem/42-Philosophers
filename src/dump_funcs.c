//////////////////////// DUMP

// t_philo	*new_philo(int th_id)
// {
// 	t_philo *new;

// 	new = (t_philo *) malloc(sizeof(t_philo *));
// 	if (!new)
// 		return (NULL);
// 	new->id = th_id;
// 	// pthread_create(&(new->philo), NULL, &print_create, NULL);
// 	// pthread_mutex_init(&(new->fork), NULL);
// 	new->next = new;
// 	return (new);
// }

// int	insert_philo(t_philo **head, t_philo *new)
// {
// 	t_philo	*tmp;
// 	int h_id;

// 	if (!new)
// 		return (0);
// 	if (!(*head))
// 	{
// 		*head = new;
// 		(*head)->next = *head;
// 		return (1);
// 	}
// 	tmp = *head;
// 	h_id = tmp->id;
// 	while (tmp->next->id != (*head)->id)
// 		tmp = tmp->next;
// 	new->next = *head;
// 	tmp->next = new;
// 	return (1);
// }

// void	print_philos(t_philo *head)
// {
// 	t_philo	*tmp;

// 	if (!head)
// 		return ;
// 	tmp = head;
// 	printf("Philosopher: %d\n", tmp->id);
// 	tmp = tmp->next;
// 	while (tmp->id != head->id)
// 	{
// 	// printf("OK\n");
// 		printf("Philosopher: %d\n", tmp->id);
// 		tmp = tmp->next;
// 	}
// }

// DUMP header
// t_philo	*new_philo(int th_id);
// int		insert_philo(t_philo **head, t_philo *new);
// void	print_philos(t_philo *head);