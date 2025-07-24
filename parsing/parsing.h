#include "minishell.h"
#define QUOTE_OPEN "
#define QUOTE_CLOSE ""

//check if is..
int is_space(char c);
int is_only_one_pipe(char c);
int quote_is_close(char c);
int is_parentheses_is_close(char c);

//utils
void	free_split(char **tab);


