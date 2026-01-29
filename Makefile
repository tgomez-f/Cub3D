# ==============================
#            cub3d
# ==============================

NAME        = cub3d

# ---- Dossiers ----
SRC_DIR     = src
PARS_DIR    = parsing
INC_DIR     = includes
LIBFT_DIR   = $(INC_DIR)/libft
MLX_DIR     = minilibx-linux
OBJ_DIR     = obj

# ---- Sources ----
SRCS        =  $(SRC_DIR)/main.c \
               $(SRC_DIR)/utils.c \
               $(SRC_DIR)/init_all.c \
               $(SRC_DIR)/mlx_hooks.c \
               $(PARS_DIR)/parsing.c \
			   $(PARS_DIR)/colors.c \
               $(PARS_DIR)/alloc_file.c \
               $(PARS_DIR)/valid_file.c \
               $(PARS_DIR)/valid_assets.c \
			   $(PARS_DIR)/valid_map.c \
			   $(PARS_DIR)/map_closed.c

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# ---- Compilation ----
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g \
              -I$(INC_DIR) \
              -I$(LIBFT_DIR)/includes \
              -I$(MLX_DIR)

# ---- Librairies ----
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

LDFLAGS     = $(LIBFT) \
              -L$(MLX_DIR) -lmlx \
              -lXext -lX11 -lm -lz

# ---- Couleurs ----
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
RESET       = \033[0m

# ---- Règles ----
all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo "$(GREEN)[OK]$(RESET) Compilation terminée : $(YELLOW)$(NAME)$(RESET)"

# Compilation générique .c -> .o (src ET parsing)
$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3d.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[CC]$(RESET) $<"

# ---- Libft ----
$(LIBFT):
	@make -C $(LIBFT_DIR)

# ---- MLX ----
$(MLX):
	@make -C $(MLX_DIR)

# ---- Nettoyage ----
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)[CLEAN]$(RESET) objets supprimés"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)[FCLEAN]$(RESET) binaire supprimé"

re: fclean all

.PHONY: all clean fclean re
