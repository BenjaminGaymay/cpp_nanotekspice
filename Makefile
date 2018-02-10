NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp \
	  ./src/Components/Circuit.cpp \
	  ./src/Components/Component.cpp \
	  ./src/Components/Input.cpp \
	  ./src/Components/Output.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/Components/
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
