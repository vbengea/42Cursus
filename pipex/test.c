/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:20:45 by vbcvali           #+#    #+#             */
/*   Updated: 2024/11/25 17:21:05 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid1 = fork();

	if (pid1 < 0) {
		// Fork failed
		perror("fork");
		return 1;
	} else if (pid1 == 0) {
		// First child process
		printf("First child process. PID: %d, Parent PID: %d\n", getpid(), getppid());

		pid_t pid2 = fork();

		if (pid2 < 0) {
			// Fork failed
			perror("fork");
			return 1;
		} else if (pid2 == 0) {
			// Grandchild process
			printf("Grandchild process. PID: %d, Parent PID: %d\n", getpid(), getppid());
		} else {
			// First child process
			printf("First child process created a grandchild. Grandchild PID: %d\n", pid2);
		}
	} else {
		// Parent process
		printf("Parent process. PID: %d, First child PID: %d\n", getpid(), pid1);
	}

	return 0;
}