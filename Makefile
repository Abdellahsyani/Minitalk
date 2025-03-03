NAME = client
S_NAME = server

CC = cc
C_FLAG = -Wall -Wextra -Werror

SRC = client.c
S_SRC = server.c

B_SRC = bonus_client.c
BS_SRC = bonus_server.c

PF_DIR = ./ft_printf
LIB_PF = $(PF_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
BS_OBJ = $(BS_SRC:.c=.o)

all: $(NAME) $(S_NAME)

$(NAME): $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) -L$(PF_DIR) -lftprintf -o $(NAME)

$(S_NAME): $(S_OBJ)
	$(CC) $(C_FLAG) $(S_OBJ) -L$(PF_DIR) -lftprintf -o $(S_NAME)

bonus: $(B_OBJ) $(BS_OBJ)
	$(CC) $(C_FLAG) $(B_OBJ) -L$(PF_DIR) -lftprintf -o $(NAME)
	$(CC) $(C_FLAG) $(BS_OBJ) -L$(PF_DIR) -lftprintf -o $(S_NAME)

$(LIB_PF):
	make -C $(PF_DIR)

%.o: %.c
	$(CC) $(C_FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(S_OBJ) $(B_OBJ) $(BS_OBJ)
	make -C $(PF_DIR) clean

fclean: clean
	rm -f $(NAME) $(S_NAME)
	make -C $(PF_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus
