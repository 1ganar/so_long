# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 23:51:05 by mberrouk          #+#    #+#              #
#    Updated: 2023/04/17 02:45:30 by mberrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c analysis/map_checks.c analysis/process_error.c analysis/solution_checks.c \
			graphics/initial.c graphics/key_hook.c graphics/process_img.c \
			utils/2d_utils.c utils/str_utils.c \

SRCS_B 	=	main.c analysis/map_checks.c analysis/process_error.c analysis/solution_checks.c \
			graphics/initial_bonus.c graphics/key_hook.c graphics/animations_bonus.c graphics/process_img.c\
			utils/2d_utils.c utils/str_utils.c utils/itoa.c\

CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror
mlxFLG	=	-lmlx -framework OpenGL -framework AppKit
NAME 	= 	so_long
NAME_B	= 	so_long_bonus

all 	: $(NAME)

$(NAME) : $(SRCS)
		@$(CC) $(CFLAGS) $(SRCS) $(mlxFLG) -o $(NAME)

clean 	: 
		@rm -f $(NAME)

fclean 	: clean
		@rm -f $(NAME) $(NAME_B)

bonus	: $(NAME_B)

$(NAME_B) : $(SRCS_B)
			@$(CC) $(CFLAGS) $(SRCS_B) $(mlxFLG) -o $(NAME_B)

re 		: fclean all
