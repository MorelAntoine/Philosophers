##
## Makefile for PSU_2016_philo in /home/morel_j/Documents/epitech/annee_2/semestre_2/unix_concurrency/PSU_2016_philo
##
## Made by Antoine Morel
## Login   <antoine.morel@epitech.net>
##
## Started on  Tue Mar 14 17:10:07 2017 Antoine Morel
## Last update Tue Mar 14 17:10:07 2017 Antoine Morel


NAME		=		philo

SRC		=		src/main.c				\
				src/parsing/parameters.c		\
				src/core/forks/forks.c			\
				src/core/forks/forks_state.c		\
				src/core/leaderboard/leaderboard.c	\
				src/core/launcher/launcher.c		\
				src/core/core.c				\
				src/core/journey/journey.c

OBJ		=		$(SRC:.c=.o)

CC		=		gcc -g

CFLAGS		=		-W -Wall -Wextra -I ./include

LDFLAGS		=		-lriceferee -lpthread

RM		=		rm -rf

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				$(CC) $(OBJ) -L./include  $(LDFLAGS) -o $(NAME)
clean		:
				$(RM) $(OBJ)

fclean		:		clean
				$(RM) $(NAME)

re		:		fclean all
