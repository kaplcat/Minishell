#include "minishell.h"


char *cmnd_generator(const char *text, int state)
{
  static int list_index;
  static size_t len;
  char *name;
  char *custom_cmnds[12];

    custom_cmnds[0] = "echo";
    custom_cmnds[1] = "emacs";
    custom_cmnds[2] = "cd";
    custom_cmnds[3] = "exit";
    custom_cmnds[4] = "setenv";
    custom_cmnds[5] = "unsetenv";
    custom_cmnds[6] = "env";
    custom_cmnds[7] = "pwd";
    custom_cmnds[8] = "ls";
    custom_cmnds[9] = "cat";
    custom_cmnds[10] = NULL;
  if (!state)
    {
      list_index = 0;
      len = ft_strlen(text);
    }
  while ((name = custom_cmnds[list_index++]))
      if (ft_strncmp(name, text, len) == 0)
	    return (ft_strdup(name));
  return NULL;
}

char **cmnd_completion(const char *text, int start, int end)
{
  rl_attempted_completion_over = 1;
  start = 0;
  end = 0;
  return (rl_completion_matches(text, cmnd_generator));
}
