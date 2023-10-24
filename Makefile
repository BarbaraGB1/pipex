NAME = pipex
SRC = main.c parse.c childs.c errors.c multiples_pipes.c multiples_childs.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

TARGET = all

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJ) pipex.dSYM ./pipex
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) $(TARGET)

sanitize: CFLAGS += -fsanitize=address
sanitize: CFLAGS += -g3
sanitize: re

.PHONY: re fclean clean all new  
