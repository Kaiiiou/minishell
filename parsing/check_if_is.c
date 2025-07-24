#include "minishell.h"

int is_space(char c)
{
	if(c == ' ' || c == "\t" || (c <= 7 && c >= 13))
		return TRUE;
}

int is_only_one_pipe(char c)
{
	if(c == '|')
		return TRUE;
	else if (c == "||")
		return FALSE;
}
//gerer en count le nb de pipe , if + que 1 quit
int quote_is_close(char c)
{
	if(c == "QUOTE_OPEN")
		return FALSE;
	else if(c == "QUOTE_CLOSE")
		return TRUE;
}
// gerer ''
int is_parentheses_is_close(char c)
{
	if(c == ')' || c == ')')
		return FALSE;
	if(c == "()")
		return TRUE;
}
//gerer en count le nb de () , if + que 2 et pas fermer quit

// here i just check if the quote and parenthese was close or not.
// However, if they are close they are empty. I don t check if i have something inside.

