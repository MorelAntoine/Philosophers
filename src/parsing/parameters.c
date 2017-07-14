/*
** parameters.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
** 
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
** 
** Started on  Sat Mar 11 10:39:00 2017 Antoine Morel
** Last update Sat Mar 11 10:39:00 2017 Antoine Morel
*/

#include	<string.h>
#include	"parameters.h"

static int	is_natural_pos(char *s)
{
  int		index;

  index = 0;
  while (s[index])
    {
      if (!(s[index] >= '0' && s[index] <= '9'))
	return (0);
      index++;
    }
  return (1);
}

static int	parse_args(t_params *args, char *arg, char *val)
{
  if (!is_natural_pos(val))
    return (-1);
  if (strcmp("-e", arg) == 0)
    args->max_eats = atoi(val);
  else if (strcmp("-p", arg) == 0)
    args->philosophers = atoi(val);
  else
    return (-1);
  return (0);
}

t_params	*parse(int ac, char **av)
{
  t_params	*args;

  if (ac != 5)
    return (NULL);
  if (strcmp(av[1], av[3]) == 0)
    return (NULL);
  args = malloc(sizeof(t_params));
  if (args == NULL)
    return (NULL);
  if (parse_args(args, av[1], av[2]) == -1)
    {
      free(args);
      return (NULL);
    }
  if (parse_args(args, av[3], av[4]) == -1)
    {
      free(args);
      return (NULL);
    }
  return (args);
}

void		clean_params(t_params *params)
{
  free(params);
  params = NULL;
}
