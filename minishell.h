#ifndef MINISHELL_H
#define MINISHELL_H
#define TRUE 1
#define FALSE 0

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_parsing
{
	t_env				*env;
	// char				**heredoc;
	char				**rd_in;
	char				**rd_out;
	int					*out_flags;
	int					*rd_order;
	char				**cmd;
	struct s_parsing	*next;

}					t_parsing;

typedef struct s_exec
{
	t_parsing		*parsing;
//t_token		*tokens;
	int				cmd_count;
	int				exit;
	int				infile;
	int				outfile;
	int				*pids;
	int				**pipes;
}					t_exec;


#endif
