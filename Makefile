NAME		=	push_swap

NAME_B		=	checker

LIBFT		=	./libft/libft.a

SRCS		=	./srcs/ab_action.c		./srcs/checker_utils.c\
				./srcs/find_opt_val.c	./srcs/markup.c\
				./srcs/calc_ops.c		./srcs/push.c\
				./srcs/rotate.c			./srcs/sort.c\
				./srcs/stack_ops.c		./srcs/swap.c\
				./srcs/utils.c			./srcs/fill_stack.c\

SRCS_PS		=	./srcs/push_swap.c

SRCS_B 		= 	./get_next_line/get_next_line.c\
				./get_next_line/get_next_line_utils.c\
				./srcs/checker.c

HEADER		=	./includes/push_swap.h

OBJS		=	$(patsubst %.c, %.o, $(SRCS) $(SRCS_PS))

OBJS_B		=	$(patsubst %.c, %.o, $(SRCS) $(SRCS_B))

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

bonus		:	$(NAME_B)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_PS) $(LIBFT) -o $(NAME)

$(NAME_B)	:	$(OBJS_B) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_B) $(LIBFT) -o $(NAME_B)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJS_B)

fclean		:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(NAME_B)

re			:	fclean all