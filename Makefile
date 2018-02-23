NAME	= program

CC	= g++

RM	= rm -f

SRCS	=	./src/main.cpp			\
		./src/Gates.cpp			\
		./src/Components/Component.cpp	\
		./src/Components/Factory.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./includes/Components/ -I ./includes/
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
