NAME		=	test.out

CC			=	gcc

SRCS		=	checker.c get_args.c

LIBS		=	libft.a

LDIR		=	./libft

LIB			=	$(addprefix $(LDIR)/, $(LIBS))

IDIR		=	./includes

SDIR		=	./srcs

ODIR		=	./objs

LFT			=	$(addprefix -I,$(LDIR)/$(IDIR))

INC			=	$(addprefix -I,$(IDIR))

SRC			=	$(addprefix $(SDIR)/, $(SRCS))

OBJ			=	$(addprefix $(ODIR)/, $(OBJS))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	$(DEBUG) -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LFT) $(INC)
	@/bin/rm -f .cmp

$(ODIR)/%.o	:	$(SDIR)/%.c
			@$(CMP)
			@$(MKODIR)
			$(CC) $(CFLAGS) -c $< -o $@ $(LFT) $(INC)

lib			:
	@$(MAKE) DEBUG=$(DEBUG) -C $(LDIR)

clean		:
	@$(MAKE) clean -C $(LDIR)
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(ODIR)

fclean		:	clean
	@$(MAKE) fclean -C $(LDIR)
	@/bin/rm -f $(NAME)

re			:	fclean all

MKODIR 		=	if [ ! -d $(ODIR) ]; then \
			/bin/mkdir -p $(ODIR); fi

CMP 		=	if [ ! -e .cmp ]; then \
				touch .cmp; fi

.PHONY		: all, clean, fclean, re
