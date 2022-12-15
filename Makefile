# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 13:21:17 by qujacob           #+#    #+#              #
#    Updated: 2022/01/29 20:44:52 by qujacob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		fdf

SRCDIR = 	./srcs/
OBJDIR =	./objs/
INCDIR =	./includes/

SRCS =		fdf.c parsing.c errors_manager.c draw.c keyhook.c keyhook_2.c \
			isometric.c

INCLUDES = -I$(INCDIR) -Ilibft/$(INCDIR) -Imlx
OBJS =		$(SRCS:.c=.o)
OBJS :=		$(addprefix $(OBJDIR), $(OBJS))

CC = 		gcc
FLAGS =		-Wall -Wextra -Werror -g -g3 $(INCLUDES)
FLAGS_MLX =	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a
RM =		rm -rf
MKDIR =		mkdir -p

all : $(NAME)
	@echo "$(NAME) created !\n"

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "compiling $<..."

$(NAME) : libft mlx $(OBJS)
	@echo "\n=============================================\n"
	@gcc $(FLAGS) $(OBJS) libft.a -o $@ $(FLAGS_MLX)
	@echo "Creating $@..."
	@echo "\n=============================================\n"

bonus : all

$(NAME_B) : libft mlx $(OBJS_B)
	@echo "\n=============================================\n"
	@gcc $(FLAGS) $(OBJS_B) libft.a -o $@
	@echo "Creating $@..."
	@echo "\n=============================================\n"

libft :
	@echo "Creating libft..."
	@make -C libft --quiet --jobs
	@echo "\n=============================================\n"

mlx :
	@echo "Creating mlx..."
	@make -C mlx --quiet --jobs
	@echo "\n=============================================\n"

clean:
	@$(RM) $(OBJDIR)
	@make clean -C libft
	@echo "deleting objects..."

fclean:	clean
	@echo "\n"
	@$(RM) $(NAME)
	@make fclean -C libft
	@make clean -C mlx --quiet --jobs
	@echo "deleting $(NAME)..."
	@echo "deleting libft..."
	@echo "\n=============================================\n"

re : fclean all

.PHONY: all clean fclean re libft mlx bonus
