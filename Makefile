NAME =	client
S_NAME = server

CC = cc
C_FLAG = -Wall -Wextra -Werror

SRC = client.c
S_SRC = server.c
PF_DIR = ./ft_printf
LIB_PF = $(PF_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

all: $(NAME) $(S_NAME)

$(LIB_PF):
	make -C $(PF_DIR)
$(NAME): $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) -L$(PF_DIR) -lftprintf -o $(NAME)
$(S_NAME): $(S_OBJ)
	$(CC) $(C_FLAG) $(S_OBJ) -L$(PF_DIR) -lftprintf -o $(S_NAME)

%.o: %.c
	$(CC) $(C_FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(S_OBJ)
	 make -C $(PF_DIR) clean
fclean: clean
	rm -f $(NAME) $(S_NAME)
	 make -C $(PF_DIR) fclean

re: fclean all

