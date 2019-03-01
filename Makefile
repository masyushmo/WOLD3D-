#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 10:48:19 by mmasyush          #+#    #+#              #
#    Updated: 2019/02/18 10:48:21 by mmasyush         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC = main.c \
		read.c \
		sdl.c \
		engine.c \
		game_init.c \
		paint.c \
		paint_calc.c \
		keys.c \
		moves.c \
		textures.c \


CC = gcc

INC = includes/wolf3d.h

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./includes/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FT = ./libft/

FT_LIB  = $(addprefix $(FT),libft.a)

LINKS = -L$(FT) -l ft

INCLUDES =	-I$(FT) -I$(INC_DIR) \
			-I./SDL/SDL2.framework/Headers \
			-I./SDL/SDL2_image.framework/Headers \
			-I./SDL/SDL2_ttf.framework/Headers \
			-I./SDL/SDL2_mixer.framework/Headers \
			-F./SDL

SDL =	-F./SDL \
		-rpath ./SDL \
		-framework AppKit -framework OpenGL \
		-framework SDL2 -framework SDL2_image \
		-framework SDL2_mixer -framework SDL2_ttf \

all: obj_dir $(FT_LIB) $(NAME)
	@echo "\033[22;32mCOMPILATED! \033[22;35m^_^"
obj_dir:
	@mkdir -p $(OBJ_DIR)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SDL) $(OBJ) $(LINKS) -o $(NAME) -g -fsanitize=address
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INC)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
$(FT_LIB):
	@make -C $(FT)

clean: clean
	@rm -rf $(OBJ_DIR)
	@make -C $(FT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT) fclean

re: fclean all