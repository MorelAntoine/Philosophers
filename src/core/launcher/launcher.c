/*
** launcher.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:50:14 2017 Antoine Morel
** Last update Tue Mar 14 17:12:29 2017 Antoine Morel
*/

#include	<pthread.h>
#include	<string.h>
#include	<unistd.h>
#include	"journey.h"
#include	"launcher.h"

static int	clean_threads(pthread_t *pthread,
			      size_t end, char kill)
{
  size_t	index;

  index = 0;
  while (index < end)
    {
      if (kill == 1)
	pthread_cancel(pthread[index]);
      pthread_join(pthread[index], NULL);
      index++;
    }
  return (kill);
}

void		set_philo(t_philo *philo, size_t id, size_t limit)
{
  philo->id = id;
  if (id + 1 == limit)
    philo->ngb_id = 0;
  else
    philo->ngb_id = id + 1;
}

int		launcher(t_core *core)
{
  pthread_t	pthread[core->params->philosophers];
  t_philo	philo;
  size_t	index;

  index = 0;
  while (index < core->params->philosophers)
    {
      set_philo(&philo, index, core->params->philosophers);
      core->philo = &philo;
      memset(&pthread[index], 0, sizeof(pthread_t));
      if (pthread_create(&pthread[index], NULL, journey, core) != 0)
	return (clean_threads(pthread, index, KILL));
      usleep(1953);
      index++;
    }
  return (clean_threads(pthread, index, WAIT));
}
