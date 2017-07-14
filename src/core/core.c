/*
** core.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:55:33 2017 Antoine Morel
** Last update Sat Mar 11 11:55:33 2017 Antoine Morel
*/

#include	"core.h"

t_core		*create_core(t_params * params,
			     t_fork **forks, e_state *leaderboard)
{
  t_core	*core;

  core = malloc(sizeof(t_core));
  if (core == NULL)
    return (NULL);
  if (pthread_mutex_init(&(core->turn), NULL) != 0)
    {
      free(core);
      return (NULL);
    }
  core->params = params;
  core->forks = forks;
  core->leaderboard = leaderboard;
  core->philo = NULL;
  core->running = 1;
  return (core);
}

void		clean_core(t_core *core)
{
  clean_forks(core->forks, core->params->philosophers);
  clean_leaderboard(core->leaderboard);
  pthread_mutex_destroy(&(core->turn));
  free(core);
  core = NULL;
}
