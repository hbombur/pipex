NAME = pipex

FLAGS	= -Wall -Wextra -Werror

HEADER = pipex.h

SRC =	ft_perror.c \
		ft_split.c \
		functions.c  \
		processes.c \
		pipex.c   \
		
OBJ = $(patsubst %.c, %.o, $(SRC))

.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
	@echo "\033[32m\033[40m\033[1m[Pipex Compiled]"

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@
	
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
