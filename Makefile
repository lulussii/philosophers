NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude
SRC_DIR = src
HEADER_DIR = include
HEADER = $(HEADER_DIR)/philo.h\
		$(HEADER_DIR)/all.h\
		$(HEADER_DIR)/data.h\
		$(HEADER_DIR)/utils.h

SRC = $(SRC_DIR)/main.c\
	$(SRC_DIR)/utils.c\
	$(SRC_DIR)/utils_2.c\
	$(SRC_DIR)/args_handler.c\
	$(SRC_DIR)/cleanup.c\
	$(SRC_DIR)/error.c\
	$(SRC_DIR)/routine.c\
	$(SRC_DIR)/setup.c\
	$(SRC_DIR)/simulation_utils.c\
	$(SRC_DIR)/simulation.c
	
OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs
GREEN = \033[38;5;198m 
YELLOW = \033[38;5;176m
BLUE = \033[38;5;182m
RESET = \033[0m

# Comptage des fichiers
TOTAL_FILES := $(words $(SRC))
CURRENT_FILE = 0

# Fonction de progression
define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(YELLOW)Compilation: [$(BLUE)"
	@for i in `seq 1 $(shell echo $$(($(PERCENT) / 5)))`; do printf "#"; done
	@for i in `seq 1 $(shell echo $$((20 - $(PERCENT) / 5)))`; do printf " "; done
	@printf "$(YELLOW)] %3d%% - %s$(RESET)" $(PERCENT) $<
endef

# Fonction pour afficher 100% à la fin de façon propre
define complete_progress
	@printf "\r$(YELLOW)Compilation: [$(BLUE)####################$(YELLOW)] 100%%                                 $(RESET)\n"
endef

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(call progress_bar)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(GREEN)Compilation terminée avec succès !$(RESET)"

$(NAME): $(OBJ) Makefile
	$(call complete_progress)
	@echo "$(GREEN)Création de l'executable $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)Executable $(NAME) créée !$(RESET)"

clean:
	@echo "$(YELLOW)Suppression des fichiers objets...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Fichiers objets supprimés !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Suppression de $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) supprimé !$(RESET)"

re: fclean all

.PHONY: all clean fclean re