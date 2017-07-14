/*
** leaderboard.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:12:42 2017 Antoine Morel
** Last update Tue Mar 14 17:09:15 2017 Antoine Morel
*/

#ifndef				PSU_2016_PHILO_LEADERBOARD_H_
# define			PSU_2016_PHILO_LEADERBOARD_H_

#include			<stdlib.h>

typedef enum			e_state
{
  NOTHING,
  EAT,
  REST,
  THINK
}				e_state;

e_state				*create_leaderboard(size_t);
void				clean_leaderboard(e_state *leaderboard);

#endif				/* !PSU_2016_PHILO_LEADERBOARD_H_ */
