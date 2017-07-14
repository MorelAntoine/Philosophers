/*
** forks.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 10:58:52 2017 Antoine Morel
** Last update Tue Mar 14 17:13:47 2017 Antoine Morel
*/

#include	<stdlib.h>
#include	<pthread.h>
#include	"forks.h"

static t_fork	*create_fork(void)
{
  t_fork	*fork;

  fork = malloc(sizeof(t_fork));
  if (fork == NULL)
    return (NULL);
  if (pthread_mutex_init(&(fork->mutex), NULL) != 0)
    {
      free(fork);
      return (NULL);
    }
  fork->is_used = 0;
  return (fork);
}

t_fork		**create_forks(int nb)
{
  t_fork	**forks;
  int		index;

  forks = malloc(sizeof(t_fork *) * (nb));
  if (forks == NULL)
    return (NULL);
  index = 0;
  while (index < nb)
    {
      forks[index] = create_fork();
      if (forks[index] == NULL)
	{
	  free(forks);
	  return (NULL);
	}
      index++;
    }
  return (forks);
}

static void	clean_fork(t_fork *fork)
{
  pthread_mutex_destroy(&(fork->mutex));
  free(fork);
}

void		clean_forks(t_fork **forks, int nb)
{
  int		index;

  if (forks == NULL)
    return ;
  index = 0;
  while (index < nb)
    clean_fork(forks[index++]);
  free(forks);
  forks = NULL;
}
