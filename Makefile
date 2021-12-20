SRCS         =	main.c \
				game.c \
				files_management.c \
				mlx_hook.c \
				moove_player.c \
				next_level.c \
				moove_box.c \
				editor.c \

OBJS         = ${SRCS:.c=.o}

NAME         = ronflex_sokoban

AR             = ar rcs

GCC            = gcc

RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror

MLX_PATH    =     ./mlx/

FRAMLIBS    =     -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:         $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):     $(OBJS)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${MLX_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(MLX_PATH) clean
			

fclean:     clean
			${RM} ${NAME}
			@$(MAKE) -C fclean

re:            fclean all

.PHONY:     all clean fclean re