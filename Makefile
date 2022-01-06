.PHONY: libft all clean fclean re

NAME_PS 	= 	push_swap
NAME_CK 	= 	checker

SRCS		=	srcs/stack.c \
				srcs/operation_ps.c \
				srcs/operation_r.c \
				srcs/utils.c \
				srcs/utils2.c \

SRCS_PS		=	srcs/push_swap.c \
				srcs/solve.c \

SRCS_CK		=	srcs/checker.c \
		
CC_FLAG		=	-Wall -Werror -Wextra
LIBFT_FLAG	=	-Llibft -lft -Ilibft/includes
INCL_FLAG	:=	-Iinclude

CC			:=	gcc $(CC_FLAG)

OBJS		:=	$(SRCS:.c=.o)
OBJS_PS		:=	$(SRCS_PS:.c=.o)
OBJS_CK		:=	$(SRCS_CK:.c=.o)

all:		$(NAME_PS) $(NAME_CK)

libft:
	$(MAKE) -C libft

%.o:		%.c
	$(CC) $(INCL_FLAG) $(LIBFT_FLAG)  -o $@ -c $< 

$(NAME_PS):	libft $(OBJS) $(OBJS_PS)
	$(CC) -o $@ $(OBJS) $(OBJS_PS) $(LIBFT_FLAG) $(INCL_FLAG)

$(NAME_CK):	libft $(OBJS) $(OBJS_CK)
	$(CC) -o $@ $(OBJS) $(OBJS_CK) $(LIBFT_FLAG) $(INCL_FLAG)

clean:
	rm -f $(OBJS) $(OBJS_PS) $(OBJS_CK)
	make -C libft clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)
	make -C libft fclean

re: fclean all
