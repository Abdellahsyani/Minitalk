NAME = client
S_NAME = server

CC = cc
C_FLAG = -Wall -Wextra -Werror

SRC = mandatory/client.c
S_SRC = mandatory/server.c
B_SRC = bonus/client_bonus.c bonus/exit_failure.c
BS_SRC = bonus/server_bonus.c bonus/exit_failure.c

PF_DIR = ./ft_printf
LIB_PF = $(PF_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
BS_OBJ = $(BS_SRC:.c=.o)

all: $(NAME) $(S_NAME)

$(LIB_PF):
	make -C $(PF_DIR)

$(NAME): $(OBJ) $(LIB_PF)
	$(CC) $(C_FLAG) $(OBJ) -L$(PF_DIR) -lftprintf -o $(NAME)

$(S_NAME): $(S_OBJ) $(LIB_PF)
	$(CC) $(C_FLAG) $(S_OBJ) -L$(PF_DIR) -lftprintf -o $(S_NAME)

bonus: .client_bonus .server_bonus

.client_bonus: $(B_OBJ) $(LIB_PF)
	$(CC) $(C_FLAG) $(B_OBJ) -L$(PF_DIR) -lftprintf -o $(NAME)
	touch .client_bonus

.server_bonus: $(BS_OBJ) $(LIB_PF)
	$(CC) $(C_FLAG) $(BS_OBJ) -L$(PF_DIR) -lftprintf -o $(S_NAME)
	touch .server_bonus

%.o: %.c
	$(CC) $(C_FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(S_OBJ) $(B_OBJ) $(BS_OBJ)
	rm -f .client_bonus .server_bonus
	make -C $(PF_DIR) clean

fclean: clean
	rm -f $(NAME) $(S_NAME)
	make -C $(PF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
