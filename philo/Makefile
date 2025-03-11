NAME = philo
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRCS = eat.c \
	errors.c \
	handle_cases.c \
	main.c \
	parsing.c \
	philo.c \
	philo_forks.c \
	referee.c \
	sleep.c \
	think.c \
	values.c \
	misc.c
OBJS = $(SRCS:.c=.o)
INCLUDES = philo.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<
clean :
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
