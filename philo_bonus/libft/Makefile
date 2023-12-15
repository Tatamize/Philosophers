# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kito <kito@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/01 17:08:43 by kito          #+#    #+#                  #
#    Updated: 2020/12/01 17:09:12 by kito          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	ft_atoi.c		\
				ft_bzero.c		\
				ft_calloc.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\


BONUS_SRC	=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\

CFLAGS		=	-Wall -Wextra -Werror

REGUL_OBJ	=	$(SRC:%.c=%.o)
BONUS_OBJ	=	$(BONUS_SRC:%.c=%.o)

HEADER_FILE	=	libft.h

ifdef WITH_BONUS
OBJ			=	$(REGUL_OBJ) $(BONUS_OBJ)
else
OBJ			=	$(REGUL_OBJ)
endif

all: $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 all

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c libft.h
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(REGUL_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
