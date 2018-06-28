#include <ft_script.h>

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	int	pid;
	int	pipes[2];

	ft_bzero(&pipes, sizeof(pipes));
	if (pipe(pipes) == -1)
	{
		ft_putstr_fd("Error while piping.\n", 2);
		return (2);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error while forking.\n", 2);
		return (1);
	}

	if (pid != 0)	// Parent
	{
		parent(pipes[1]);
	}
	else			// Child1
	{
		child(pipes[0], envp);
	}

	return (0);
}
