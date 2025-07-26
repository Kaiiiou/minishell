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

}