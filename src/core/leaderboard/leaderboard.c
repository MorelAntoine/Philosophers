/*
** leaderboard.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 11:12:29 2017 Antoine Morel
** Last update Tue Mar 14 17:12:24 2017 Antoine Morel
*/

#include	"leaderboard.h"

e_state		*create_leaderboard(size_t size)
{
  e_state	*leaderboard;
  size_t	index;

  leaderboard = malloc(sizeof(e_state) * size);
  if (leaderboard == NULL)
    return (NULL);
  index = 0;
  while (index < size)
    {
      leaderboard[index] = REST;
      index++;
    }
  return (leaderboard);
}

void		clean_leaderboard(e_state *leaderboard)
{
  free(leaderboard);
  leaderboard = NULL;
}
