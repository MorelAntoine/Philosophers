/*
** philosopher.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:41:49 2017 Antoine Morel
** Last update Tue Mar 14 17:09:43 2017 Antoine Morel
*/

#ifndef			PSU_2016_PHILO_PHILOSOPHER_H_
# define		PSU_2016_PHILO_PHILOSOPHER_H_

#include		<stdlib.h>

typedef struct		s_philosopher
{
  size_t		id;
  size_t		ngb_id;
}			t_philo;

#endif			/* !PSU_2016_PHILO_PHILOSOPHER_H_ */
