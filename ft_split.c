#include "push_swap.h"

int count_word(char *str, char delimiter)
{
  int count = 0;
  while (*str != '\0')
  {
    while (*str != '\0' && *str == delimiter)
      str++;
    while (*str != '\0' && *str != delimiter)
    {
      str++;
      if (*str == '\0' || *str == delimiter)
        count++;

    }
  }
  return (count);
}

int len_word(char *str, char delimiter)
{
  int len = 0;
  while  (*str != '\0' && *str != delimiter)
  {
    len++;
    str++;
  }
  return (len);
}

char** ft_split(char* str, char delimiter)
{
  char **arr;
  int len = 0;
  int k = 0;
  int i;
  arr = (char **)malloc(sizeof(char*) * (count_word(str, delimiter) + 1));
  if (!arr)
    return (NULL);
  while(*str != '\0')
  {
    while (*str != '\0' && *str == delimiter)
      str++;
    if (*str != '\0')
    {
      i = 0;
      len = len_word(str, delimiter);
      arr[k] = (char *)malloc(sizeof(char) * (len + 1));
      if (!arr[k])
        return (NULL);
      while (*str != '\0' && *str != delimiter)
      {
        arr[k][i] = *str;
        i++;
        str++;
      }
      arr[k][i] = '\0';
      k++;
    }
  }
  arr[k] = NULL;
  return (arr);
}