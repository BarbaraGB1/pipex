NAME = pipex
SRC = pipex.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean clean all 

