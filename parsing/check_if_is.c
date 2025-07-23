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

int quote_is_close(char c)
{
	if(c == "QUOTE_OPEN")
		return FALSE;
	else if(c == "QUOTE_CLOSE")
		return TRUE;
}
// here i just check if the quote was close or not.
// However, if they are close they are empty.
