// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/25 17:20:45 by vbcvali           #+#    #+#             */
// /*   Updated: 2024/11/27 08:24:53 by vbcvali          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main()
// {
// 	pid_t pid1 = fork();

// 	if (pid1 < 0)
// 	{
// 		// Fork failed
// 		perror("fork");
// 		return 1;
// 	}
// 	else if (pid1 == 0) {
// 		// First child process
// 		printf("First child process. PID: %d, Parent PID: %d\n", getpid(), getppid());

// 		pid_t pid2 = fork();

// 		if (pid2 < 0)
// 		{
// 			// Fork failed
// 			perror("fork");
// 			return 1;
// 		}
// 		else if (pid2 == 0) {
// 			// Grandchild process
// 			printf("Grandchild process. PID: %d, Parent PID: %d\n", getpid(), getppid());
// 		}
// 		else
// 		{
// 			// First child process
// 			printf("First child process created a grandchild. Grandchild PID: %d\n", pid2);
// 		}
// 	}
// 	else
// 	{
// 		// Parent process
// 		printf("Parent process. PID: %d, First child PID: %d\n", getpid(), pid1);
// 	}

// 	return 0;
// }

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../incl/libft/libft.h"

void execute_command(char *cmd[], int input_fd, int output_fd) {
	if (input_fd != STDIN_FILENO) {
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != STDOUT_FILENO) {
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	printf("Test working !\n");
	execve(cmd[0], cmd, NULL);
	perror("execve");
	exit(1);
}

int main() {
	int num_commands = 3;
	char *commands[3][3] = {
		{"/bin/ls", "-la", NULL},
		{"/usr/bin/grep", "main", NULL},
		{"/usr/bin/wc", "-l", NULL}
	};

	int pipefd[2];
	int input_fd = STDIN_FILENO;

	for (int i = 0; i < num_commands; i++) {
		if (i < num_commands - 1) {
			if (pipe(pipefd) == -1) {
				perror("pipe");
				return 1;
			}
		} else {
			pipefd[1] = STDOUT_FILENO;
		}

		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}

		if (pid == 0) {
			if (i < num_commands - 1) {
				close(pipefd[0]);
			}
			execute_command(commands[i], input_fd, pipefd[1]);
		} else {
			if (input_fd != STDIN_FILENO) {
				close(input_fd);
			}
			if (i < num_commands - 1) {
				close(pipefd[1]);
				input_fd = pipefd[0];
			}
		}
	}

	for (int i = 0; i < num_commands; i++) {
		wait(NULL);
	}

	return 0;
}
