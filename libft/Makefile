# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 15:44:47 by qujacob           #+#    #+#              #
#    Updated: 2022/01/24 13:22:45 by qujacob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes/

SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_putchar.c ft_putstr.c ft_putnbr.c \
		ft_itoa_base.c ft_nbdigits.c ft_putnbru.c ft_nbdigitsu.c \
		ft_nbdigits_hexa.c ft_ltoa_base.c ft_utoa.c ft_ltoa.c ft_atol.c \
		ft_strcmp.c ft_putstrnl.c get_next_line.c get_next_line_utils.c \
		ft_strstr.c ft_min.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR), $(OBJS))

CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(INCDIR)
RM = rm -rf
MKDIR = mkdir -p

all : $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@mv $(NAME) ../

clean:
	@$(RM) $(OBJDIR)

fclean:	clean
	@$(RM) ../$(NAME)

re : fclean all

.PHONY: all clean fclean re
