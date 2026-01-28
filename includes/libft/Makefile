# ===========================
#        LIBFT MAKEFILE
# ===========================

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
RMDIR = rm -rf

# ---------- Paths ----------
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj

# ---------- Sources ----------
SRC_LIBFT = $(wildcard $(SRC_DIR)/libft/*.c)
SRC_GNL   = $(wildcard $(SRC_DIR)/gnl/*.c)
SRC_PRINTF= $(wildcard $(SRC_DIR)/ft_printf/*.c)

SRC = $(SRC_LIBFT) $(SRC_GNL) $(SRC_PRINTF)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ---------- Rules ----------
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "✅ Libft compilée avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
