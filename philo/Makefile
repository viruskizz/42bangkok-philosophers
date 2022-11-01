NAME = philo
CC = gcc
# CFLAGS = -Wextra -Wall -Werror

LIBS = -lpthread

INCLUDE_DIR	= .
INCLUDES =	-I$(INCLUDE_DIR)

SRC_DIR = srcs
SRCS =	main.c \
		routine.c \
		dinner_create.c \
		dinner_start.c \
		utils/ft_atoi.c \
		utils/time.c \
		utils/debug.c

BUILD_DIR = build

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	$(RM) -rf $(BUILD_DIR)

fclean: clean
	$(RM) -f $(NAME)

PHONY: all clean fclean re