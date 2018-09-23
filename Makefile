CHECKER		=	checker

PUSH_SWAP	=	push_swap

CC			=	gcc

SRC_CHK		=	checker.c get_instructions.c get_flags.c debug.c \
			execute_instructions.c check_if_sorted.c display.c

SRC_CMN		=	params_to_stack.c get_input.c swap.c \
			push.c rotate.c reverse_rotate.c mem_tools.c error.c \
			instruction_tools.c

SRC_PS		=	push_swap.c get_median.c sort_stack.c

CHK			=	$(addprefix checker/, $(SRC_CHK))

CMN			=	$(addprefix common/, $(SRC_CMN))

PS			=	$(addprefix push_swap/, $(SRC_PS))

LIBS		=	libft.a

LDIR		=	./libft

LIB			=	$(addprefix $(LDIR)/, $(LIBS))

IDIR		=	./includes

SDIR		=	./srcs

ODIR		=	./objs

PS_INC		=	$(addprefix $(IDIR)/, push_swap.h)

CMN_INC		=	$(addprefix $(IDIR)/, common.h)

CHK_INC		=	$(addprefix $(IDIR)/, checker.h)

HEADERS		=	$(CHK_INC) $(CMN_INC) $(PS_INC)

INCS		=	$(addprefix $(IDIR)/, $(HEADERS))

LFT			=	$(addprefix -I,$(LDIR)/$(IDIR))

INC			=	$(addprefix -I,$(IDIR)) $(LFT)

CHK_SRCS	=	$(CHK)

PS_SRCS		=	$(PS)

CMN_SRCS	=	$(CMN)

CHK_SRC		=	$(addprefix $(SDIR)/, $(CHK_SRCS))

PS_SRC		=	$(addprefix $(SDIR)/, $(PS_SRCS))

CMN_SRC		=	$(addprefix $(SDIR)/, $(CMN_SRCS))

CHK_OBJS	=	$(CHK_SRCS:.c=.o)

PS_OBJS		=	$(PS_SRCS:.c=.o)

CMN_OBJS	=	$(CMN_SRCS:.c=.o)

CHK_OBJ		=	$(addprefix $(ODIR)/, $(CHK_OBJS))

PS_OBJ		=	$(addprefix $(ODIR)/, $(PS_OBJS))

CMN_OBJ		=	$(addprefix $(ODIR)/, $(CMN_OBJS))

OBJ			=	$(CHK_OBJ) $(PS_OBJ) $(CMN_OBJ)

CFLAGS		=	$(DEBUG) -Wall -Wextra -Werror

all			:	lib $(CHECKER) $(PUSH_SWAP)

$(CHECKER)	:	$(CMN_OBJ) $(CMN_INC) $(CHK_OBJ) $(CHK_INC)
			$(CC) $(CFLAGS) -o $(CHECKER) $(CMN_OBJ) $(CHK_OBJ) $(LIB) $(INC)
			@/bin/rm -f .cmp

$(PUSH_SWAP):	$(CMN_OBJ) $(CMN_INC) $(PS_OBJ) $(PS_INC)
			$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(CMN_OBJ) $(PS_OBJ) $(LIB) $(INC)
			@/bin/rm -f .cmp

$(ODIR)/%.o	:	$(SDIR)/%.c $(HEADERS)
			@$(CMP)
			@$(MKODIR)
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

lib			:
	@$(MAKE) DEBUG="$(DEBUG)" -C $(LDIR)

clean		:
	@$(MAKE) clean -C $(LDIR)
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(ODIR)

fclean		:	clean
	@$(MAKE) fclean -C $(LDIR)
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re			:	fclean all

MKODIR 		=	if [ ! -d $(ODIR) ]; then \
			/bin/mkdir -p $(ODIR); \
			/bin/mkdir -p $(ODIR)/checker; \
			/bin/mkdir -p $(ODIR)/common; \
			/bin/mkdir -p $(ODIR)/push_swap; fi


CMP 		=	if [ ! -e .cmp ]; then \
				touch .cmp; fi

.PHONY		: all, clean, fclean, re
