/*
** forks_state.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Thu Mar 09 20:23:40 2017 Antoine Morel
** Last update Thu Mar 09 20:23:40 2017 Antoine Morel
*/

#include	"forks.h"
#include	"extern.h"

int		lock_fork(t_fork *fork)
{
  if (pthread_mutex_trylock(&(fork->mutex)) != 0)
    return (-1);
  lphilo_take_chopstick(&(fork->mutex));
  return (0);
}

int		unlock_fork(t_fork *fork)
{
  if (pthread_mutex_unlock(&(fork->mutex)) != 0)
    return (-1);
  lphilo_release_chopstick(&(fork->mutex));
  return (0);
}
