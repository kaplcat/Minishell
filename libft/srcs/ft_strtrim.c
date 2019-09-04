#include "libft.h"

char	*ft_strtrim(char const *s)
{
  char *copy;
  size_t i;
  size_t end;
  
  i = 0;
  if (s == NULL)
    return (NULL);
  while (s[i] != '\0' && ft_isspace(s[i]) == 1)
    i++;
  end = ft_strlen(s);
   while (ft_isspace(s[end - 1]) == 1 && i < end)
    end--;
   if (i == end)
     return (ft_strnew(1));
  copy = ft_strsub(s, i, end - i);
  return (copy);
}
