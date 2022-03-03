NAME = pipex

SRC =	pipex.c


OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = pipex.h

FLAGS	= -Wall -Wextra -Werror -I

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re