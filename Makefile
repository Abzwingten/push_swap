NAME_PS 	:= 	push_swap
NAME_CK 	:= 	checker

SRCS_SH		:=	srcs/stack.c \
				srcs/operation_ps.c \
				srcs/operation_r.c \
				srcs/utils.c \
				srcs/utils2.c

SRCS_PS		:=	$(SRCS_SH)	\
				srcs/push_swap.c \
				srcs/solve.c

SRCS_CK		:=	$(SRCS_SH) \
				srcs/checker.c

CC_FLAG		:=	-Wall -Werror -Wextra
LIBFT_FLAG	:=	-L./libft -lft
INCL_FLAG	:=	-I./include -I./libft/includes

CC			:=	gcc $(CC_FLAG)

OBJS_PS		:=	$(SRCS_PS:.c=.o)
OBJS_CK		:=	$(SRCS_CK:.c=.o)

.PHONY: libft all clean fclean re

all:	libft $(NAME_CK) $(NAME_PS)

libft:
	$(MAKE) -C libft

%.o:		%.c
	$(CC) $(INCL_FLAG) -o $@ -c $<

$(NAME_PS): $(OBJS_PS)
	$(CC) $(OBJS_PS) -o $@ $(LIBFT_FLAG)

$(NAME_CK):	$(OBJS_CK)
	$(CC) $(OBJS_CK) -o $@ $(LIBFT_FLAG) 

clean:
	rm -f $(OBJS_SH) $(OBJS_PS) $(OBJS_CK)
	make -C libft clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)
	make -C libft fclean

re: fclean all
