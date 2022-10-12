# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 22:54:17 by ilya              #+#    #+#              #
#    Updated: 2022/10/12 13:41:32 by ilya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

SRC			=	try.cpp \
				main.cpp


INC			= 

OBJDIR		=	tmp
SRCDIR		=	src
INCDIR		=	inc

INC_PATH	= 	$(addprefix $(INCDIR)/, $(INC))
SRC_PATH 	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ_PATH 	=	$(addprefix $(OBJDIR)/, $(notdir $(SRC_PATH:.cpp=.o)))

CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror
O_FLAG		=	-O3 -std=c++98 #-MD

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

