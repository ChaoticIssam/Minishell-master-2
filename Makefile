NAME = Minishell
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
src = main.c\
		utils.c\
		parssing.c\
		ft_split.c\
		toke_it.c\
		toke_it_utils.c\
		toke_it_utils1.c\
		parssing_utils.c\
		parssing_utils1.c\
		quote_parss_utils.c\
		quote_parss_utils1.c\
		env_parss.c\
		error.c\
		
OBJECTS = ${src:.c=.o}

all	:	$(NAME)

$(NAME):	$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lreadline -o $(NAME)
		
clean :
	$(RM) $(OBJECTS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY: all clean fclean re
