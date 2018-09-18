NAME		=	test.out

CC			=	gcc

SRCS		=	checker.c display.c error.c parsing_tools.c stack_tools.c \
			get_input.c get_instructions.c execute_instructions.c

LIBS		=	libft.a

LDIR		=	./libft

LIB			=	$(addprefix $(LDIR)/, $(LIBS))

IDIR		=	./includes

SDIR		=	./srcs

ODIR		=	./objs

HEADERS		=	checker.h

INCS		=	$(addprefix $(IDIR)/, $(HEADERS))

LFT			=	$(addprefix -I,$(LDIR)/$(IDIR))

INC			=	$(addprefix -I,$(IDIR))

SRC			=	$(addprefix $(SDIR)/, $(SRCS))

OBJ			=	$(addprefix $(ODIR)/, $(OBJS))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	$(DEBUG) -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJ) lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LFT) $(INC)
	@/bin/rm -f .cmp

$(ODIR)/%.o	:	$(SDIR)/%.c $(INCS)
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
