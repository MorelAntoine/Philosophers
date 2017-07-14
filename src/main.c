/*
** main.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Thu Mar 09 15:38:18 2017 Antoine Morel
** Last update Thu Mar 09 21:08:24 2017 Antoine Morel
*/

#include	"core.h"
#include	"extern.h"
#include	"launcher.h"

static int	philosopher(t_params *params)
{
  t_fork	**forks;
  e_state	*leaderboard;
  t_core	*core;
  int		exit_status;

  forks = create_forks(params->philosophers);
  if (forks == NULL)
    return (1);
  leaderboard = create_leaderboard(params->philosophers);
  if (leaderboard == NULL)
    {
      clean_forks(forks, params->philosophers);
      return (1);
    }
  core = create_core(params, forks, leaderboard);
  if (core == NULL)
    {
      clean_forks(forks, params->philosophers);
      clean_leaderboard(leaderboard);
      return (1);
    }
  exit_status = launcher(core);
  clean_core(core);
  return (exit_status);
}

int		main(int argc, char **argv)
{
  t_params	*params;
  int		exit_status;

  RCFStartup(argc, argv);
  params = parse(argc, argv);
  if (params == NULL)
    {
      RCFCleanup();
      return (1);
    }
  if (params->philosophers < 2)
    {
      clean_params(params);
      RCFCleanup();
      return (1);
    }
  exit_status = philosopher(params);
  clean_params(params);
  RCFCleanup();
  return (exit_status);
}
