NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = philo.c\
OBJS_DIR = objs
OBJ = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# Couleurs
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Comptage des fichiers
TOTAL_FILES := $(words $(SRCS))
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

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(call progress_bar)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(GREEN)Compilation terminée avec succès !$(RESET)"

$(NAME): $(OBJ) libft.h Makefile
	$(call complete_progress)
	@echo "$(GREEN)Création de la bibliothèque $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Bibliothèque $(NAME) créée !$(RESET)"

clean:
	@echo "$(YELLOW)Suppression des fichiers objets...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Fichiers objets supprimés !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Suppression de $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@rm -f .bonus
	@echo "$(GREEN)$(NAME) supprimé !$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus