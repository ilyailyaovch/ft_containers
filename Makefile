# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 22:54:17 by ilya              #+#    #+#              #
#    Updated: 2022/10/28 17:18:09 by ilya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

SRC			=	mainTest.cpp \
				vectorTest.cpp

INC			= 

OBJDIR		=	tmp
SRCDIR		=	src
INCDIR		=	containers

INC_PATH	= 	$(addprefix $(INCDIR)/, $(INC))
SRC_PATH 	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ_PATH 	=	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.cpp=.o)))
DEP_PATH 	=	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.cpp=.d)))

CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror
O_FLAG		=	-O3 -std=c++98 -MD

all				: $(NAME)

$(NAME) 		: $(OBJ_PATH)
		$(CC) $(FLAGS) $(O_FLAG) $(OBJ_PATH) -o $(NAME)

$(OBJDIR)/%.o 	: $(SRCDIR)/%.cpp $(INC_PATH) Makefile
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) $(O_FLAG) -o $@ -c $<

clean			:
		@rm -rf $(OBJDIR)
		@echo "Removing obj"

fclean			:	clean
		@rm -f $(NAME)
		@echo "Removing all"

re				:  fclean all

test			:	$(NAME)
		leaks --atExit -- ./ft_containers

.PHONY			: all clean fclean re

-include $(DEP_PATH)