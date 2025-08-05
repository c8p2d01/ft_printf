# Output Name:
NAME:=		libftprintf.a

# Folders
BUILD:=		./build
SOURCE:=	./src

# Other variables:
COMPILER:=	cc
COMPFLAGS:= -Werror -Werror -Wextra -g -c

# Source Files:
SRCFILES =	ft_printf.c \
			flag_handling.c \
			flag_reading.c \
			handlers_1.c \
			handlers_2.c \
			mem_utils.c \
			padding.c \
			print_based_utils.c \
			print_utils.c \
			storage.c \
			string_utils.c

# Process Variables
CC:=		$(COMPILER)
CFLAGS:=	$(COMPFLAGS)
SRCS:=		$(addprefix $(SOURCE)/,$(SRCFILES))
OBJS:=		$(SRCS:$(SOURCE)/%.c=$(BUILD)/%.o)
NAME:=		./$(NAME)
OS:=		$(shell uname -s)

.PHONY: all clean fclean re

all:
	make -j $(nproc) $(NAME)

$(OBJS): $(BUILD)%.o : $(SOURCE)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

clean:
	$(RM) -r $(BUILD)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

bonus: all
