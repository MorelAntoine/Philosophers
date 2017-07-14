/*
** launcher.h for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:50:29 2017 Antoine Morel
** Last update Sat Mar 11 11:56:01 2017 Antoine Morel
*/

#ifndef		PSU_2016_PHILO_LAUNCHER_H_
# define	PSU_2016_PHILO_LAUNCHER_H_

#include	"core.h"

#ifndef		LAUNCHER_KILL
# define	KILL 1
#endif		/* !LAUNCHER_KILL */

#ifndef		LAUNCHER_WAIT
# define	WAIT 0
#endif		/* !LAUNCHER_WAIT */

int		launcher(t_core *core);

#endif		/* !PSU_2016_PHILO_LAUNCHER_H_ */
