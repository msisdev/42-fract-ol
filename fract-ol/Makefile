#--------------------------------------#
#- CONFIG -----------------------------#
#--------------------------------------#

NAME			:= fractol
APP				:= $(NAME)
APP_DIR			:= app
APP_CODES		:= $(APP_DIR)/main.c
APP_OBJS		:= $(APP_CODES:.c=.o)

BIN_DIR			:= bin
INC_DIR			:= include

LIBFT_DIR		:= libft
LIBFT			:= $(LIBFT_DIR)/libft.a

LIBMLX_DIR		:= libmlx
LIBMLX			:= $(LIBMLX_DIR)/libmlx.a

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CFLAGS			+= -I$(INC_DIR) -I$(LIBFT_DIR)
CFLAGS			+= $(DBG)	# make DBG="-g"
MLXOBJFLAGS		:= -I/usr/include -I$(LIBMLX_DIR) -O3
MLXLINKFLAGS	:= -L$(LIBMLX_DIR) -lmlx -L/usr/lib -I$(LIBMLX_DIR) -lXext -lX11 -lm -lz

SRC_DIR			:= src
SRC_CODES		:= \
	$(SRC_DIR)/color/color_bw.c \
	$(SRC_DIR)/color/color_space.c \
	$(SRC_DIR)/color/color.c \
	$(SRC_DIR)/ctx/ctx_display.c \
	$(SRC_DIR)/ctx/ctx_get.c \
	$(SRC_DIR)/ctx/ctx_hook.c \
	$(SRC_DIR)/ctx/ctx_state.c \
	$(SRC_DIR)/ctx/ctx.c \
	$(SRC_DIR)/draw/draw_fract.c \
	$(SRC_DIR)/draw/draw.c \
	$(SRC_DIR)/input/input_parse.c \
	$(SRC_DIR)/input/input.c \
	$(SRC_DIR)/fractal.c \
	$(SRC_DIR)/graphic.c \
	$(SRC_DIR)/handle.c
SRC_OBJS		:= $(SRC_CODES:.c=.o)

#--------------------------------------#
#- CMD --------------------------------#
#--------------------------------------#

.PHONY: all
all: app

.PHONY: clean
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	find . -name "*.o" -delete

.PHONY: fclean
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(APP)
	rm -f $(BIN_DIR)/*

.PHONY: re
re: fclean all

#--------------------------------------#
#- APP --------------------------------#
#--------------------------------------#

.PHONY: app
app: $(NAME)

$(NAME): $(SRC_OBJS) $(APP_OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(MLXLINKFLAGS) -o $@ $^

#--------------------------------------#
#- LIBFT ------------------------------#
#--------------------------------------#

$(LIBFT):
	make -C $(LIBFT_DIR)
	
#--------------------------------------#
#- LIBMLX -----------------------------#
#--------------------------------------#

$(LIBMLX):
	make -C $(LIBMLX_DIR)

#--------------------------------------#
#- SRC --------------------------------#
#--------------------------------------#

.PHONY: src
src: $(SRC_OBJS)

#--------------------------------------#
#- COMMONS ----------------------------#
#--------------------------------------#

$(BIN_DIR):
	mkdir $(BIN_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXOBJFLAGS) -c -o $@ $<
