################################################################################
#                          Makefile configuration                              #
################################################################################

NAME		= cub3D
NAME_BONUS	= cub3D_bonus
CFLAG		= -Wall -Wextra -Werror -g3 #-fsanitize=address,leak,undefined
CC			= cc

################################################################################
#                                 Include                                      #
################################################################################

INCDIR 	 		= include
INC	   	 		= ${INCDIR}/cub3d.h
# INCBONUS 		= ${INCDIR}/cub3d_bonus.h
INCLUDES 		= -I ${INCDIR} -I./${LIBFT_PATH}include -I./${MINILBX_PATH}
# INCLUDES_BONUS 	= -I ${INCDIR} -I./${LIBFT_PATH}include -I./${MINILBX_PATH}

################################################################################
#                                 Libft                                        #
################################################################################

LIBFT_FILE	= libft/libft.a
LIBFT_PATH	= libft/
LFLAG 		= -L./${LIBFT_PATH} -lft

################################################################################
#                              MiniLibx                                        #
################################################################################

MINILBX_FILE	= mlx-linux/libmlx_Linux.a
MINILBX_PATH	= mlx-linux/
MLXFLAG 		= -L./${MINILBX_PATH} -lmlx -lXext -lX11 -lm

################################################################################
#                                 Sources                                      #
################################################################################

SRCDIR 		= srcs

SRC			=	${SRCDIR}/mandatory/main.c \
				${SRCDIR}/mandatory/error_msg.c \
				${SRCDIR}/mandatory/diagnostics.c \
				${SRCDIR}/mandatory/init_functions.c \
				${SRCDIR}/mandatory/free_functions.c \
				${SRCDIR}/mandatory/parsing/parsing.c \
				${SRCDIR}/mandatory/parsing/extract_data.c \
				${SRCDIR}/mandatory/parsing/get_map.c \
				${SRCDIR}/mandatory/parsing/get_rgb.c \
				${SRCDIR}/mandatory/parsing/get_texture.c \
				${SRCDIR}/mandatory/parsing/parse_map.c \
				${SRCDIR}/mandatory/parsing/parsing_utils.c \
				${SRCDIR}/mandatory/parsing/check_borders.c \
				${SRCDIR}/mandatory/raycasting/raycaster.c \
				${SRCDIR}/mandatory/raycasting/getter.c \
				${SRCDIR}/mandatory/raycasting/raycaster_utils.c \
				${SRCDIR}/mandatory/raycasting/rendering_utils.c \
				${SRCDIR}/mandatory/raycasting/rendering.c \
				${SRCDIR}/mandatory/execution/start_game.c \
				${SRCDIR}/mandatory/execution/keypress.c \
				${SRCDIR}/mandatory/execution/move.c \
				${SRCDIR}/mandatory/execution/free_assets.c \

# BONUSDIR	= 	${SRCDIR}/bonus

# BONUS_SRC 	=	${BONUSDIR}/main_bonus.c \

# SRCS_BONUS 	= 	${BONUS_SRC}

################################################################################
#                                   Objects                                    #
################################################################################

OBJDIR 		= objs

OBJ    		= ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}

# OBJS 		= ${BONUS_SRC:${BONUSDIR}/%.c=${OBJDIR}/%.o}

# OBJS_BONUS 	= ${OBJS}

################################################################################
#                                   Colors                                     #
################################################################################

BLACK 	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE 	= \033[0;34m
PURPLE 	= \033[0;35m
CYAN 	= \033[0;36m
RESET 	= \033[0m

################################################################################
#                                    Rules                                     #
################################################################################

all: ${LIBFT_FILE} ${MINILBX_FILE} ${NAME}

${NAME} : ${OBJ} 
	@${CC} ${CFLAG} ${INCLUDES} ${OBJ} ${LFLAG} ${MLXFLAG} -o ${NAME}
	@echo "${YELLOW}✰✰✰ Alright, you can use ${NAME} ✰✰✰ :D${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INC}
	@mkdir -p ${dir $@}
	@${CC} ${CFLAG} ${INCLUDES} -c $< -o $@
	@echo "${GREEN}***  CUB3D: compilation success  ***${RESET}"

# bonus: ${LIBFT_FILE} ${MINILBX_FILE} ${NAME_BONUS}

# ${NAME_BONUS} : ${OBJS_BONUS}
# 	@${CC} ${CFLAG} ${INCLUDES_BONUS} ${OBJS_BONUS} ${LFLAG} ${MLXFLAG} -o ${NAME_BONUS}
# 	@echo "${YELLOW}✰✰✰ Bonus has been compiled ✰✰✰ :D${RESET}"

# ${OBJDIR}/%.o: ${BONUSDIR}/%.c ${INCBONUS}
# 	@mkdir -p ${dir $@}
# 	@${CC} ${CFLAG} ${INCLUDES_BONUS} -c $< -o $@
# 	@echo "${GREEN}***  Bonus compilation success  ***${RESET}"

${LIBFT_FILE} :
	@make -sC libft

${MINILBX_FILE} :
	@make -sC mlx-linux

clean: 
	@rm -rf ${OBJDIR}
	@echo "${PURPLE}► Cleaning done: ${OBJDIR} directory has been removed ◄${RESET}"
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}
	@echo "${BLUE}► Fclean done: ${NAME} and ${NAME_BONUS} has been removed ◄${RESET}"
	@make fclean -C ${LIBFT_PATH}

re: fclean all
	@echo "${CYAN}↻↻↻ Makefile has been re'd ↺↺↺ \o/${RESET}"

.PHONY: all clean fclean re bonus
