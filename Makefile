# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 11:32:23 by lseabra-          #+#    #+#              #
#    Updated: 2025/08/31 16:53:57 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                 COLOR CODES                                  #
#==============================================================================#

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET   = \033[0m

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# Names
NAME                = fdf
PROJECT_NAME        = FDF

# Paths
INC_PATH = includes
SRCS_PATH           = srcs
# SRCS_BONUS_PATH     = srcs_bonus
BUILD_PATH          = build

# Source files
SRCS = $(addprefix $(SRCS_PATH)/, \
		cleanup.c \
		init_map_utils.c \
		init_map.c \
		init_win.c \
		main.c \
		print_map.c \
		validate.c \
)

# Object files
OBJS       = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

# LIBFT
LIBFT_PATH = libft
LIBFT_LINK = ft
LIBFT_NAME = $(LIBFT_PATH)/lib$(LIBFT_LINK).a

# MINILIBX
MLX_PATH = minilibx-linux
MLX_LINK = mlx
MLX_NAME = $(MLX_PATH)/lib$(MLX_LINK).a

# Compiler and flags
CC = cc
CFLAGS =	-Wall -Wextra -Werror -g \
			-I$(INC_PATH) -I$(LIBFT_PATH)/$(INC_PATH) -I$(MLX_PATH)
LDFLAGS =	-L$(LIBFT_PATH) -l$(LIBFT_LINK) \
			-L$(MLX_PATH) -l$(MLX_LINK) \
			-L/usr/lib  -lXext -lX11 -lm -lz

# Utility commands
TC      = touch
RM      = rm -f
RM_DIR  = rm -rf
AR      = ar rcs
MKDIR_P = mkdir -p
MAKE    = make --no-print-directory

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):  $(OBJS) $(LIBFT_NAME) $(MLX_NAME)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)[$(PROJECT_NAME)] Executable compiled: $(NAME)$(RESET)"

$(BUILD_PATH)/%.o: $(SRCS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< $(LDFLAGS) -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "$(GREEN)[$(PROJECT_NAME)] Build directory created$(RESET)"

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_PATH) bonus


$(MLX_NAME):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(RM_DIR) $(BUILD_PATH)
	@echo "$(GREEN)[$(PROJECT_NAME)] Clean: build files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)[$(PROJECT_NAME)] Full clean: executable '$(NAME)' removed.$(RESET)"

re: fclean all