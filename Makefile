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
OBJ 	= 	${SRCS:.c=.o}

all 	: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(mlxFLG) -o $(NAME)

clean 	: 
		rm -f ${OBJ}

fclean 	: clean
		rm -f $(NAME) $(NAME_B)

bonus	: $(NAME_B)

$(NAME_B) : 
			$(CC) $(CFLAGS) $(SRCS_B) $(mlxFLG) -o $(NAME_B)

re 		: fclean all
