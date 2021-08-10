NAME=fractol

CC=Clang
CFLAGS = -Wall -Werror -Wextra 
CFLAGS += -fsanitize=address -g3
MLX= -L minilibx_opengl_20191021/.
#AR = ar rcs
RM = rm -rf
MFLAGS = -framework OpenGL -framework AppKit
FILES = hooks \
	  init_struct \
	  fractol \
	  process_start \
	  warnings \
	  tools \


SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(MAKE) -C Libft/
	$(MAKE) -C ft_printf/
	$(MAKE) -C ../mlx_src/minilibx_opengl_20191021/
	mv Libft/libft.a .
	mv ft_printf/libprintf.a .
	mv ../mlx_src/minilibx_opengl_20191021/libmlx.a .
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -lmlx -lprintf $(MFLAGS) -o $(NAME)


all: $(NAME)

clean:
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C Libft/ clean
	$(MAKE) -C ft_printf/ clean
	$(MAKE) -C ft_printf/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.a
	$(RM) libprintf.a

#PHONY members, inevitably, are used as RULES.
.PHONY: bonus all clean fclean
