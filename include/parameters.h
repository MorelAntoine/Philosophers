/*
** parameters.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 10:37:04 2017 Antoine Morel
** Last update Tue Mar 14 17:09:30 2017 Antoine Morel
*/

#ifndef			PSU_2016_PHILO_PARAMETERS_H
# define		PSU_2016_PHILO_PARAMETERS_H

#include		<stdlib.h>

typedef struct		s_parameters
{
  size_t		philosophers;
  size_t		max_eats;
}			t_params;

t_params		*parse(int ac, char **av);
void			clean_params(t_params *params);

#endif			/* !PSU_2016_PHILO_PARAMETERS_H_ */
