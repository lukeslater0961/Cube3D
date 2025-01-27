PROJECT = cub3D
NAME = cub3D
PROJECT_EMOJI = 🧊
CC = $(SILENT)cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = obj
LIBS_DIR = $(SRCS_DIR)/utils/libs

LIBS = $(LIBS_DIR)/libft/libft.a \
	   $(LIBS_DIR)/MacroLibX/libmlx.so -lSDL2\

SRCS_FILES = main.c								\
			 parsing/parsing.c					\
			 parsing/check_format.c				\
			 parsing/check_content.c			\
			 parsing/flood_fill.c				\
			 parsing/utils.c					\
			 parsing/check_map.c				\
			 utils/print/print_errors.c 		\
			 graphic/graphic.c				\
			 graphic/window_mngmnt.c			\
			 graphic/player_mngmnt.c			\
			 graphic/render.c					\
			 graphic/raycasting.c				\
			 graphic/utils.c					\
			 utils/utils.c						\
			 utils/ft_double_split.c			\
			 parsing/parsing_utils.c			\

SRCS = 	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(subst $(SRCS_DIR)/,$(OBJS_DIR)/, $(subst .c,.o, $(SRCS)))

DELET_LINE = $(SILENT) echo -n "\033[2K";
RM = $(SILENT) rm -rf

SILENT = @
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_PURPULE = \033[38;5;197m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
NO_COLOR=\033[m

bold := $(shell tput bold)
notbold := $(shell tput sgr0)

PRINT = $(SILENT) printf "\r%b"

MSG_CLEANING = "$(COLOUR_RED)$(bold)🧹cleaning $(notbold)$(COLOUR_YELLOW)$(PROJECT)$(NO_COLOR)";
MSG_CLEANED = "$(COLOUR_RED)$(bold)[🗑️ ]$(PROJECT) $(notbold)$(COLOUR_YELLOW)cleaned $(NO_COLOR)\n";
MSG_TOTALY_CLEANED = "$(COLOUR_RED)$(bold)[🗑️ ]$(PROJECT) $(notbold)$(COLOUR_YELLOW)is totaly cleaned $(NO_COLOR)\n";
MSG_COMPILING = "$(COLOUR_YELLOW)$(bold)[💧 Compiling 💧]$(notbold)$(COLOUR_YELLOW) $(^)$(NO_COLOR)";
MSG_READY = "$(PROJECT_EMOJI) $(COLOUR_BLUE)$(bold)$(PROJECT) $(COLOUR_GREEN)$(bold)ready$(NO_COLOR)\n";

BANNER = $(PRINT) "$(COLOUR_PURPULE)  ___  __  __  ____  ____  ___  ____            \n"
BANNER1 = printf "$(COLOUR_PURPULE) / __)(  )(  )(  _ \( ___)(__ )(  _ \ \n"
BANNER2 = printf "$(COLOUR_PURPULE)( (__  )(__)(  ) _ < )__)  (_ \ )(_) )\n"
BANNER3 = printf "$(COLOUR_PURPULE) \___)(______)(____/(____)(___/(____/ \n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(HEADER)
	@make -s -j -C $(LIBS_DIR)/libft
	$(CC) $^ -o $@ $(LIBS) -lm
	$(DELET_LINE)
	$(PRINT) $(MSG_READY)

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(DELET_LINE)
	$(PRINT) $(MSG_COMPILING)
	$(CC) -c $< -o $@

$(OBJS_DIR):
	$(SILENT)mkdir -p $@

clean:
	@make clean -s -j -C $(LIBS_DIR)/libft
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

fclean: clean
	@make fclean -s -j -C $(LIBS_DIR)/libft
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	$(DELET_LINE)
	$(PRINT) $(MSG_TOTALY_CLEANED)

re: fclean all 

.PHONY: all clean fclean re
