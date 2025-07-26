#include "minishell.h"

int	cmd_count(t_parsing *parsing)
{
	int	count;

	count = 0;
	if(!parsing)
		return (0);
	while(parsing)
	{
		count++;
		parsing = parsing->next;
	}
	return (count);
}

void	exec_parsing_link(t_exec *exec, t_parsing *parsing)
{
	exec->parsing = parsing;
	exec->cmd_count = cmd_count(parsing);
	exec->exit = 0;
	exec->infile = -1;
	exec->outfile = -1;
	exec->pids = NULL;
	exec->pipes = NULL;
}

int	alloc_pids(t_exec *exec)
{
	if (!exec || exec->cmd_count <= 0)
		return (0);
	exec->pids = malloc (sizeof(pid_t) * (exec->cmd_count));
	if(!exec->pids)
		return (0);
	return (1);
}

int	alloc_pipes(t_exec *exec)
{
	int	i;

	i = 0;
	if (!exec || exec->cmd_count <= 1)
		return (0);
	exec->pipes = malloc (sizeof(int *) * (exec->cmd_count - 1));
	if(!exec->pipes)
			return (0);
	while(i < exec->cmd_count - 1)
	{
		exec->pipes[i] = malloc (sizeof(int) * 2);
		if(!exec->pipes[i])
			return (0);
		i++;
	}
	return (1);
}