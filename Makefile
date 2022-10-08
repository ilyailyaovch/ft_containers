# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 22:54:17 by ilya              #+#    #+#              #
#    Updated: 2022/10/08 23:31:12 by ilya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

SRC			=	main.cpp \

INC			= 

OBJDIR		=	obj
SRCDIR		=	src
INCDIR		=	inc

INC_PATH	= 	$(addprefix $(INCDIR)/, $(INC))
SRC_PATH 	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ_PATH 	=	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.cpp=.o)))

CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror
O_FLAG		=	-O3

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
