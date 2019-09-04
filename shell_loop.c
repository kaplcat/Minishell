
#include "minishell.h"

int execute_cmnd(char **cmnd)
{
	int execute_status;
	char *path;

	execute_status = 1;// del
	if (cmnd[0] == NULL) //empty command
		return (1); //continue to execute
	else if (*cmnd[0] == '/' || *cmnd[0] == '.')
		execute_status = absolute_path_launch(cmnd);
	else if (check_builtin(cmnd[0]) == 1)
		execute_status = builtin(cmnd);
	else if ((path = check_extern_command(cmnd)))
		execute_status = external_launch(cmnd, path);
	else
		perror_cmnd("minishell", cmnd[0], CMNDNTFND);
	return (execute_status);
}

void cmnd_loop()
{
	char *line;
	char **args;
	int status;
	int i;

	args = NULL;
	status = 1;
	while (status)
	{
		signals();
//        ft_putstr(SHELL_NAME);
//    if ((get_next_line(STDIN_FILENO, &line)))
		rl_attempted_completion_function = cmnd_completion; //WAT
		while (sigsetjmp(g_sig, 1) != 0)
		  {
		    ft_putchar_fd('\n', STDOUT_FILENO);
		    ;
		  }
		if ((line = readline(SHELL_NAME)))
		{
			if ((strrchr(line, ';')))
			{
				if (!(args = ft_strsplit(line, ';')))
					perror_cmnd("minishell", NULL, MLKERR);
				i = 0;
				while (args[i])
				{
					status = execute_cmnd(split_cmnd(args[i], ' '));
					if (status == 0)
						break ;
					i++;
				}
			}
			else
			{
				args = split_cmnd(line, ' ');
				status = execute_cmnd(args);
				free(args);
			}
			add_history(line);
			free(line);
		}
		else
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return ;
		}
	}
}
