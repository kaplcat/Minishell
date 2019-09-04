#include "minishell.h"

int		find_bin(char *cmnd_name, char *path)
{
	DIR				*dir;
	struct dirent	*dir_ptr;

	if ((dir = opendir(path)))
	{
		while ((dir_ptr = readdir(dir)))
			if (ft_strcmp(dir_ptr->d_name, cmnd_name) == 0)
			{
				closedir(dir);
				return (1);
			}
		closedir(dir);
	}
	return (0);
}

char	*path(char *name, char *path)
{
	char	*full;
	char	*tmp;

	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strjoin(path, name));
	else
	{
		tmp = ft_strjoin(path, "/");
		full = ft_strjoin(tmp, name);
		ft_memdel((void **)&tmp);
	}
	return (full);
}


char		*check_extern_command(char **cmnd)
{
	char	*env_path;
	char	**paths;
	int		i;
	int paths_quant;

	i = 0;
	paths_quant = 0;
//    env_path = getenv_cmnd("PATH");
	if (!(env_path = getenv_cmnd("PATH")))//ok
		return (NULL);
	paths = ft_strsplit(env_path, ':'); // invalid read->count words
	while (paths[paths_quant])
		paths_quant++;
	while (i < paths_quant) //seg
	{
		if ((find_bin(cmnd[0], paths[i])))
			return (paths[i]);
		i++;
	}
	return (NULL);
}

int external_launch(char **cmnd, char *paths)
{
	char *filepath;

	if (!access(cmnd[0], R_OK)) // check //X_OK??
	{
		perror_cmnd("minishell", cmnd[0], 0);
		return (1);
	}
	filepath = path(cmnd[0], paths);
	return (launch(filepath, cmnd));
}