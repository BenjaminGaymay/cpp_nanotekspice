NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp \
	  ./src/Circuit.cpp \
	  ./src/Component.cpp \
	  ./src/Input.cpp \
	  ./src/Output.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/pp
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
