/*
** journey.c for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
**
** Made by Antoine Morel
** Login   <antoine.morel@epitech.net>
**
** Started on  Sat Mar 11 12:37:55 2017 Antoine Morel
** Last update Fri Mar 17 11:56:53 2017 antoine
*/

#include		<unistd.h>
#include		"core.h"
#include		"extern.h"
#include		"launcher.h"

void			do_job(e_state job, t_core *core,
			       size_t id, size_t ngb_id)
{
  if (job == EAT)
    {
      lock_fork(core->forks[id]);
      core->forks[id]->is_used = 1;
      lock_fork(core->forks[ngb_id]);
      core->forks[ngb_id]->is_used = 1;
      lphilo_eat();
    }
  else if (job == THINK)
    {
      lock_fork(core->forks[id]);
      core->forks[id]->is_used = 1;
      lphilo_think();
    }
  else if (job == REST)
    {
      unlock_fork(core->forks[id]);
      core->forks[id]->is_used = 0;
      unlock_fork(core->forks[ngb_id]);
      core->forks[ngb_id]->is_used = 0;
      lphilo_sleep();
    }
  if (job != NOTHING)
    core->leaderboard[id] = job;
}

e_state			get_job(t_core *core,
				size_t id, size_t ngb_id)
{
  size_t		prev;

  if (id == 0)
    prev = core->params->philosophers - 1;
  else
    prev = id - 1;
  if (core->forks[id]->is_used == 1 && core->leaderboard[id] == REST)
    return (NOTHING);
  if (core->leaderboard[id] == THINK && core->leaderboard[ngb_id] == REST)
    return (EAT);
  if (core->leaderboard[id] == EAT)
    return (REST);
  if (core->leaderboard[id] == REST && core->leaderboard[prev] == THINK
      && core->leaderboard[ngb_id] == REST)
    return (EAT);
  if (core->leaderboard[id] == REST && core->leaderboard[prev] == THINK)
    return (NOTHING);
  if (core->leaderboard[id] == REST && core->leaderboard[ngb_id] == REST)
    return (THINK);
  return (NOTHING);
}

e_state			init_journey(size_t *id, size_t *ngb_id,
				     size_t *eat_count, t_core *core)
{
  (*id) = core->philo->id;
  (*ngb_id) = core->philo->ngb_id;
  (*eat_count) = 0;
  usleep(1953 * (core->params->philosophers - core->philo->id + 1));
  return (REST);
}

void			final_job(e_state job, size_t *eat_count,
				  t_core *core, size_t *ids)
{
  if (job == EAT)
    (*eat_count)++;
  if ((*eat_count) == core->params->max_eats)
    do_job(REST, core, ids[0], ids[1]);
}

void			*journey(void *data)
{
  t_core		*core;
  size_t		ids[2];
  size_t		eat_count;
  e_state		job;

  core = (t_core *)data;
  job = init_journey(&ids[0], &ids[1], &eat_count, core);
  while (eat_count < core->params->max_eats)
    {
      if (core->running == 0
	  && eat_count == core->params->max_eats - 1 && job == EAT)
	{
	  do_job(REST, core, ids[0], ids[1]);
	  break;
	}
      pthread_mutex_lock(&(core->turn));
      job = get_job(core, ids[0], ids[1]);
      do_job(job, core, ids[0], ids[1]);
      pthread_mutex_unlock(&(core->turn));
      final_job(job, &eat_count, core, ids);
      if (job == REST)
	usleep(200);
    }
  core->running = 0;
  pthread_exit(NULL);
}
