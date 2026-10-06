# Colors
RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
BLUE   = \033[34m

DEP_DIR := dep/
OBJ_DIR := obj/
SRCS := PhoneBook.cpp Contact.cpp main.cpp
OBJS := $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS := $(patsubst %.cpp, $(DEP_DIR)%.d, $(SRCS)) 

NAME := phonebook
CC := c++
CFLAGS_SRC := -Wall -Wextra -Werror -std=c++98
CFLAGS_OBJ = $(CFLAGS_SRC) -MMD -MP -MF $(DEP_DIR)$*.d

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n"
	@printf "$(GREEN)==$(BOLD)$(BLUE)Executable$(GREEN)==$(RESET)\n"
	$(CC) $(CFLAGS_SRC) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS_OBJ) -c $< -o $@

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@printf "$(GREEN)======================================$(RESET)\n"
	@printf "$(BOLD)$(BLUE)       CLEANING          $(RESET)\n"
	@printf "$(GREEN)======================================$(RESET)\n"
	rm -rf $(DEP_DIR)
	rm -rf $(OBJ_DIR)
	@printf "\n"

fclean:
	@printf "$(GREEN)======================================$(RESET)\n"
	@printf "$(BOLD)$(BLUE)       FCLEANING          $(RESET)\n"
	@printf "$(GREEN)======================================$(RESET)\n"
	rm -rf $(NAME)
	@printf "\n"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
