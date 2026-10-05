# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

NAME := megaphone
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

DEP_DIR := dep/
OBJ_DIR := obj/
SRCS := megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@printf "\n"
	@printf "$(GREEN)==$(BOLD)$(BLUE)Executable$(GREEN)==$(RESET)\n"
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@printf "$(GREEN)======================================$(RESET)\n"
	@printf "$(BOLD)$(BLUE)       CLEANING          $(RESET)\n"
	@printf "$(GREEN)======================================$(RESET)\n"
	@printf "\n"

fclean:
	@printf "$(GREEN)======================================$(RESET)\n"
	@printf "$(BOLD)$(BLUE)       FCLEANING          $(RESET)\n"
	@printf "$(GREEN)======================================$(RESET)\n"
	rm -rf $(NAME)
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re
