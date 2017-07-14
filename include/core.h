/*
** core.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 10:52:01 2017 Antoine Morel
** Last update Sat Mar 11 10:52:01 2017 Antoine Morel
*/

#ifndef				PSU_2016_PHILO_CORE_H_
# define			PSU_2016_PHILO_CORE_H_

#include			"forks.h"
#include			"leaderboard.h"
#include			"parameters.h"
#include			"philosopher.h"

typedef struct			s_core
{
  t_params 			*params;
  t_fork			**forks;
  e_state			*leaderboard;
  t_philo			*philo;
  pthread_mutex_t		turn;
  char				running;
}				t_core;

t_core				*create_core(t_params *params,
					     t_fork **forks, e_state *leaderboard);

void				clean_core(t_core *core);

#endif				/* !PSU_2016_PHILO_CORE_H_ */
