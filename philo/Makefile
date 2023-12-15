NAME		= philo

CFLAGS		= -Wall -Wextra -Werror

DIR_MAIN	=	./
DIR_LIBFT	= 	./libft

SRC_MAIN	=	philo_util_common.c				\
				philo_util_error.c				\
				philo_util_unlock.c				\
				philo_setdata.c					\
				philo_routine_eat.c				\
				philo_routine_sleep.c			\
				philo_routine_think.c			\
				philo_make_threads_routine.c	\
				philo.c

OBJ_MAIN	=	$(SRC_MAIN:%.c=%.o)
LIBFT_A		=	$(DIR_LIBFT)/libft.a

HEADER		=	$(DIR_MAIN)philo.h	\

all:	$(NAME)

libft:	$(LIBFT_A)

$(LIBFT_A):
	cd $(DIR_LIBFT); make ; cd ../

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) -o $@ $<

$(NAME): $(SRC_MAIN) $(HEADER) $(LIBFT_A)
	gcc $(CFLAGS) $(SRC_MAIN) $(LIBFT_A) -o $(NAME)

clean:
	rm -f $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME)

libftclean:
	cd $(DIR_LIBFT); make fclean; cd ../

re: fclean all