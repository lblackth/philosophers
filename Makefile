SRCS		=	check.c \
				main.c \
				other.c \
				routine.c \
				ft_atoi.c

OBJ			=	${SRCS:.c=.o}

CC			=	cc

REMOVE		=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -pthread

NAME		=	philo

HEADER		=	philosopher.h

all:		$(HEADER) $(NAME)
$(NAME):	$(OBJ) $(HEADER)
			$(CC) ${OBJ} -o ${NAME} ${CFLAGS}
clean:		
			@$(REMOVE) $(OBJ)
fclean:		clean
			@$(REMOVE) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re