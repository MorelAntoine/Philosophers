/*
** extern.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Tue Mar 14 16:56:22 2017 Antoine Morel
** Last update Tue Mar 14 16:56:22 2017 Antoine Morel
*/

#ifndef		__LIBRICEFEREE_EXTERN__
# define	__LIBRICEFEREE_EXTERN__

#include	<pthread.h>

int		RCFStartup(int ac, char **av);
void		RCFCleanup();
int		lphilo_eat();
int		lphilo_sleep();
int		lphilo_think();
int		lphilo_take_chopstick(const pthread_mutex_t *mutex_id);
int		lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif		/* !__LIBRICEFEREE_EXTERN__ */
