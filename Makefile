INCLUDES = -I ./includes

SRCS_C = ./srcs/checker/*
SRCS_P = ./srcs/push_swap/*.c ./srcs/push_swap/recursive_way/*.c
SRCS_OPER = ./srcs/operations/*.c

UTILS = ./utils/*

LIBFT = libft/libft.a
LIB_C = lib_checker.a
LIB_P = lib_push_swap.a
LIB_OPER = lib_operations.a

OBJ = ./obj

EXEC_C = checker
EXEC_P = push_swap

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

all: $(LIB_OPER) $(EXEC_C) $(EXEC_P)

$(LIB_OPER):
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(LIB_OPER)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS_OPER) $(UTILS) $(INCLUDES) -c -g
	@echo "$(GREEN)Compiling $(GREEN_EXTRA)$(LIB_OPER)$(RESET)"
	@ar rc $(LIB_OPER) *.o
	@ranlib $(LIB_OPER)
	@if [ ! -d "./obj" ]; then mkdir -p $(OBJ); fi
	@echo "$(GREEN)Moving objects files for $(GREEN_EXTRA)$(LIB_OPER)$(GREEN) to $(OBJ)$(RESET)"
	@mv *.o $(OBJ)
	@make -C libft
	@echo "$(BLUE_EXTRA)$(LIB_OPER)$(BLUE): Complete$(RESET)"

$(EXEC_C):
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(LIB_C)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS_C) $(INCLUDES) -c -g
	@echo "$(GREEN)Compiling $(GREEN_EXTRA)$(LIB_C)$(RESET)"
	@ar rc $(LIB_C) *.o
	@ranlib $(LIB_C)
	@if [ ! -d "./obj" ]; then mkdir -p $(OBJ); fi
	@echo "$(GREEN)Moving objects files for $(GREEN_EXTRA)$(LIB_C)$(GREEN) to $(OBJ)$(RESET)"
	@mv *.o $(OBJ)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC_C)$(RESET)"
	@gcc -Wall -Wextra -Werror $(LIB_C) $(LIB_OPER) $(LIBFT) $(INCLUDES) -o $(EXEC_C)
	@echo "$(BLUE_EXTRA)$(EXEC_C)$(BLUE): Complete$(RESET)"


$(EXEC_P):
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(LIB_P)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS_P) $(INCLUDES) -c -g
	@echo "$(GREEN)Compiling $(GREEN_EXTRA)$(LIB_P)$(RESET)"
	@ar rc $(LIB_P) *.o
	@ranlib $(LIB_P)
	@if [ ! -d "./obj" ]; then mkdir -p $(OBJ); fi
	@echo "$(GREEN)Moving objects files for $(GREEN_EXTRA)$(LIB_P)$(GREEN) to $(OBJ)$(RESET)"
	@mv *.o $(OBJ)
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC_P)$(RESET)"
	@gcc -Wall -Wextra -Werror $(LIB_P) $(LIB_OPER) $(LIBFT) $(INCLUDES) -g -o $(EXEC_P)
	@echo "$(BLUE_EXTRA)$(EXEC_P)$(BLUE): Complete$(RESET)"

clean:
	@if [ -d "./obj" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(LIB_OPER)$(RESET)"; \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(LIB_C)$(RESET)"; \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(LIB_P)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(LIB_OPER)" ]; then \
	echo "$(RED)Deleting $(RED_EXTRA)$(LIB_OPER)$(RESET)"; \
	/bin/rm -f $(LIB_OPER); \
	fi

	@if [ -a "$(LIB_C)" ]; then \
	echo "$(RED)Deleting $(RED_EXTRA)$(LIB_C)$(RESET)"; \
	/bin/rm -f $(LIB_C); \
	fi

	@if [ -a "$(LIB_P)" ]; then \
	echo "$(RED)Deleting $(RED_EXTRA)$(LIB_P)$(RESET)"; \
	/bin/rm -f $(LIB_P); \
	fi

	@if [ -a "$(EXEC_C)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC_C)$(RESET)"; \
	/bin/rm -f $(EXEC_C); \
	fi

	@if [ -a "$(EXEC_P)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC_P)$(RESET)"; \
	/bin/rm -f $(EXEC_P); \
	fi

	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
