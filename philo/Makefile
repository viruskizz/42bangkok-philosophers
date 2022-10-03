NAME = philo
CC = gcc
# CFLAGS = -Wextra -Wall -Werror

LIBFT_DIR = libft

INCLUDE_DIR	= .
INCLUDES =	-I$(INCLUDE_DIR) -I$(LIBFT_DIR)

SRC_DIR = srcs
SRCS = main.c

BUILD_DIR = build

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	$(RM) -rf $(BUILD_DIR)

fclean: clean
	$(RM) -f $(NAME)

PHONY: all clean fclean re