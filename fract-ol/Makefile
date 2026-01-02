#--------------------------------------#
#- CONFIG -----------------------------#
#--------------------------------------#

BLU				:= \033[0;34m
GRN				:= \033[0;32m
RED				:= \033[0;31m
RST				:= \033[0m
END				:= \e[0m

NAME			:= a.out
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
# MLXFLAGS		:= -Lmlx -lmlx -L/usr/lib -Imlx -lX11 -lXext -lm
MLXOBJFLAGS		:= -I/usr/include -I$(LIBMLX_DIR) -O3
MLXLINKFLAGS	:= -L$(LIBMLX_DIR) -lmlx -L/usr/lib -I$(LIBMLX_DIR) -lXext -lX11 -lm -lz


SRC_DIR			:= src
SRC_CODES		:= $(shell find $(SRC_DIR) -name '*.c')
SRC_OBJS		:= $(SRC_CODES:.c=.o)

TEST_DIR		:= test
TEST_NAMES		:= $(shell find $(TEST_DIR) -mindepth 1 -maxdepth 1 -type d -printf '%f\n')
TEST_CODES		:= $(shell find $(TEST_DIR) -name '*.c')
TEST_INC_DIR	:= test_include		# shared headers for test
TEST_SRC_DIR	:= test_src			# shared srcs for test
TEST_SRC_CODES	:= $(shell find $(TEST_SRC_DIR) -name '*.c')
TEST_SRC_OBJS	:= $(TEST_SRC_CODES:.c=.o)
# objs including all test srcs and shared srcs
TEST_OBJS		:= $(TEST_CODES:.c=.o) $(TEST_SRC_OBJS)

#--------------------------------------#
#- CMD --------------------------------#
#--------------------------------------#

.PHONY: all
all: app

.PHONY: clean
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	find . -name "*.o" -delete

.PHONY: fclean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) fclean
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
#- TEST -------------------------------#
#--------------------------------------#

.PHONY: test
test: $(BIN_DIR) $(TEST_NAMES)

.SECONDEXPANSION:
%_test: \
	$(LIB_OBJS) \
	$(SRC_OBJS) \
	$(TEST_SRC_OBJS) \
	$$(shell find $(TEST_DIR)/$$*_test -type f -name '*.c' | sed 's/\.c/\.o/') | \
	$(BIN_DIR)	# order only prerequisite
	$(CC) $(CFLAGS) $(MLXLINKFLAGS) -I $(TEST_INC_DIR) -o $(BIN_DIR)/$@ $^

#--------------------------------------#
#- COMMONS ----------------------------#
#--------------------------------------#

$(BIN_DIR):
	mkdir $(BIN_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXOBJFLAGS) -c -o $@ $<

# include test headers for test objs
$(TEST_OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(MLXOBJFLAGS) -I $(TEST_INC_DIR) -c -o $@ $<
