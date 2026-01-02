#--------------------------------------#
#- CONFIG -----------------------------#
#--------------------------------------#

BIN_DIR			:= bin
INC_DIR			:= .

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
CFLAGS			+= -I $(INC_DIR)
CFLAGS			+= $(DBG)	# make DBG="-g"

NAME			:= libft.a
LIB				:= $(NAME)
LIB_DIR			:= .
LIB_CODES		:= ft_42.c
LIB_OBJS		:= $(LIB_CODES:.c=.o)
LIB_MARK_NAME	:= mark_lib

#--------------------------------------#
#- CMD --------------------------------#
#--------------------------------------#

.PHONY: all
all: lib

.PHONY: clean
clean:
	find . -name "*.o" -delete

.PHONY: fclean
fclean: clean
	rm -f $(LIB) $(BIN_DIR)/*

.PHONY: re
re: fclean all

#--------------------------------------#
#- LIB --------------------------------#
#--------------------------------------#

.PHONY: lib
lib: $(NAME)

$(NAME): $(LIB_MARK_NAME)

$(LIB_MARK_NAME): $(LIB_OBJS)
	ar crs $(NAME) $^

#--------------------------------------#
#- COMMONS ----------------------------#
#--------------------------------------#

$(BIN_DIR):
	@mkdir $(BIN_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
