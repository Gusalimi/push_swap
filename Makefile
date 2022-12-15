NAME	= push_swap
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIB		= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

.c.o:
	@printf "\033[1;32mCompiling:\033[0m %s\n" $<
	@$(CC) -c $< $(CFLAGS) -o $(<:.c=.o) -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@printf "\033[1;32mCompiling:\033[0m %s\n" $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	@$(MAKE) -C libft

debug: $(OBJS) $(LIB)
	@printf "\033[1;32mCompiling with fsanitize:\033[0m %s\n" $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -fsanitize=address -o $(NAME)

clean:
	@printf "\033[1;31mCleaning object files\033[0m\n"
	@$(RM) $(OBJS)
	@$(MAKE) clean -C libft

fclean: clean
	@printf "\033[1;31mCleaning binary files\033[0m\n"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft

re:	fclean all

.PHONY: all debug clean fclean
