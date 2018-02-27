##
## EPITECH PROJECT, 2018
## cpp_nanotekspice
## File description:
## 
##

NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	=	./src/main.cpp			\
		./src/Gates.cpp			\
		./src/Parser.cpp		\
		./src/ManageStrings.cpp		\
		./src/ManageComponents.cpp	\
		./src/Components/Component.cpp	\
		./src/Components/Factory.cpp	\
		./src/Commands.cpp

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
