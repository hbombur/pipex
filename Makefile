NAME = pipex

SRC =	pipex.c ft_split.c ft_perror.c \
		functions.c processes.c


OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = pipex.h

FLAGS	= -Wall -Wextra -Werror -I


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(HEADER)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@
	
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re