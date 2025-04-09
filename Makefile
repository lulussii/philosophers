NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude
SRC_DIR = src
HEADER_DIR = include
HEADER = $(HEADER_DIR)/philo.h
SRC = $(SRC_DIR)/philo.c\
	$(SRC_DIR)/utils.c\
	$(SRC_DIR)/parsing.c\
	$(SRC_DIR)/errors.c\
	$(SRC_DIR)/inits.c\

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs
GREEN = \033[38;5;183m
YELLOW = \033[38;5;117m
BLUE = \033[38;5;205m
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
	@echo "$(GREEN)Création de la bibliothèque $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)Bibliothèque $(NAME) créée !$(RESET)"

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