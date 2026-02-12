NAME = serializer
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CC = c++
OBJ_DIR = objs

SRCS = main.cpp\
		Serializer.cpp		

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
		@printf "Compiled ✅✅✅\n"

clean	:
	rm -rf $(OBJ_DIR)
	@printf "Clean 🧹\n"

fclean	: clean
	rm -f $(NAME)
	@printf "Big Clean 🧼\n"

re	: fclean all

.PHONY	: all clean fclean re% 