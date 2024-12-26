/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:20:49 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/26 19:06:58 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <string.h>
// #include <unistd.h>

// //pthread_mutex_t mutex;
// long test;

// void	*routine(void *n)
// {
// 	//pthread_mutex_lock(&mutex);
// 	for (int j = 0; j < 10000000000; j++)
// 	{
// 		test++;
// 	}
// 	//pthread_mutex_unlock(&mutex);
// 	return (NULL);
// }

// int main(int argc, char **argv)
// {
// 	int n = atoi(argv[1]);

// 	pthread_t *philos;

// 	philos = malloc(sizeof(pthread_t) * n);
// 	int i = 0;
// 	//pthread_mutex_init(&mutex, NULL);
// 	while (i < n)
// 	{
// 		if (pthread_create(&philos[i], NULL, &routine, NULL))
// 			perror("Error creating the thread!");
// 		printf("Creating thread %d\n", i);
// 		usleep(1000);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (pthread_join(philos[i], NULL))
// 			perror("Failed to join the thread!");
// 		printf("Joining thread %d\n", i);
// 		i++;
// 	}
// 	//pthread_mutex_destroy(&mutex);
// 	printf("The value os test is: %ld\n", test);

// 	return (0);
// }

#include "philosophers.h"

void	*routine(void)
{
	printf("Testing thread with linked list !\n");
	return (NULL);
}



int main(void)
{
	t_philo *philo;
	t_philo *temp;
	t_philo *head;

	philo = malloc(sizeof(t_philo) * 5);
	if (!philo)
		return (1);
	int i = 0;
	head = philo;
	while (i < 5)
	{
		philo[i].id = i;
		philo[i].next = &philo[(i + 1) % 5];
		philo[i].prev = &philo[(i + 4) % 5];
		i++;
	}

	temp = head;
	while (true)
	{
		pthread_create(&temp->philo, NULL, (void *)&routine, NULL);
		printf("Thread created!\n");
		temp = temp->next;
		if (temp == head)
			break;
	}

	temp = head;
	while (true)
	{
		pthread_join(temp->philo, NULL);
		temp = temp->next;
		if (temp == head)
			break;
	}
	return (0);
}