/*
** forks.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 10:57:49 2017 Antoine Morel
** Last update Sat Mar 11 10:57:49 2017 Antoine Morel
*/

#ifndef			FORKS_H_
# define		FORKS_H_

#include		<pthread.h>

typedef	struct		s_fork
{
  pthread_mutex_t	mutex;
  char			is_used;
}			t_fork;

t_fork			**create_forks(int);
void			clean_forks(t_fork **, int);
int			lock_fork(t_fork *);
int			unlock_fork(t_fork *);

#endif			/* !FORKS_H_ */
