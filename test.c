#include <stdlib.h>
#include <stdio.h>

typedef struct s_cmd
{
	char	**args;
	char	*infile;
	char	*outfile;
	int		append;
	struct s_cmd *next;
} t_cmd;

t_cmd	*cmd_new(char **args, char *infile, char *outfile, int append)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if(!new_cmd)
		return(NULL);
	new_cmd->args = args;
	new_cmd->infile = infile;
	new_cmd->outfile = outfile;
	new_cmd->append = append;
	new_cmd->next = NULL;
	return(new_cmd);
}

void	cmd_add_back(t_cmd **list, t_cmd *new_cmd)
{
	t_cmd *tmp;

	if(*list == NULL)
	{
		*list = new_cmd;
		return;
	}
	tmp = *list;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_cmd;
}

void	print_cmd_list(t_cmd *list)
{
	int	i;

	if(list == NULL)
		printf("NULL");
	while(list)
	{
		i = 0;
		while(list->args && list->args[i])
		{
			printf("args : %s\n", list->args[i]);
			i++;
		}
		if (list->infile)
			printf("Redirection entrée  : %s\n", list->infile);
		if (list->outfile)
		{
			if (list->append)
				printf("Redirection sortie (append) : %s\n", list->outfile);
			else
				printf("Redirection sortie : %s\n", list->outfile);
		}
		printf("\n");
		list = list->next;
	}
}

int	main()
{
	t_cmd *cmd_list = NULL;

	char *args1[] = {"ls", "-l", NULL};
	t_cmd *cmd1 = cmd_new(args1, NULL, NULL, 0);
	cmd_add_back(&cmd_list, cmd1);

	char *args2[] = {"echo", "coucou", NULL};
	t_cmd *cmd2 = cmd_new(args2, NULL, "out.txt", 0);
	cmd_add_back(&cmd_list, cmd2);

	char *args3[] = {"cat", NULL};
	t_cmd *cmd3 = cmd_new(args3, "in.txt", "out.txt", 1);
	cmd_add_back(&cmd_list, cmd3);
	
	print_cmd_list(cmd_list);
	return (0);
}