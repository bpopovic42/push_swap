CHECKER		=	checker

PUSH_SWAP	=	push_swap

CC			=	gcc

SRC_CHK		=	checker.c get_instructions.c get_flags.c \
			exec_inst.c display.c

SRC_CMN		=	params_to_stack.c get_input.c swap.c push.c rotate.c \
			reverse_rotate.c mem_tools.c error.c instruction_tools.c \
			debug.c struct_tools.c is_sorted.c

SRC_PS		=	push_swap.c get_median.c rec_inst.c sorting_tools.c \
			sort_a.c sort_b.c small_sort.c

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

CFLAGS		=	$(DEBUG) $(if $(SILENT), , -Wall -Wextra -Werror)

all			:	$(CHECKER) $(PUSH_SWAP)
			@$(IF_CMP)

$(CHECKER)	:	$(LIB) $(CMN_OBJ) $(CMN_INC) $(CHK_OBJ) $(CHK_INC)
			@$(CC) $(CFLAGS) -o $(CHECKER) $(CMN_OBJ) $(CHK_OBJ) $(LIB) $(INC)
			@$(IF_CMP)
			@echo $(G)[$(B)CHECKER $(G)COMPILED]$(X)

$(PUSH_SWAP):	$(LIB) $(CMN_OBJ) $(CMN_INC) $(PS_OBJ)
			@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(CMN_OBJ) $(PS_OBJ) $(LIB) $(INC)
			@$(IF_CMP)
			@echo $(G)[$(B)PUSH_SWAP $(G)COMPILED]$(X)

$(ODIR)/%.o	:	$(SDIR)/%.c $(HEADERS)
			@$(CMP)
			@$(MKODIR)
			@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
			@$(CLR)
			@echo -n $@

$(LIB)		:
	@$(MAKE) DEBUG="$(DEBUG)" -C $(LDIR)

clean		:
	@$(MAKE) clean -C $(LDIR)
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(ODIR)
	@echo $(G)[$(B)PUSH_SWAP $(G)CLEANED]$(X)

fclean		:	clean
	@/bin/rm -f $(LIB)
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re			:	fclean all

MKODIR 		=	if [ ! -d $(ODIR) ]; then \
			/bin/mkdir -p $(ODIR); \
			/bin/mkdir -p $(ODIR)/checker; \
			/bin/mkdir -p $(ODIR)/common; \
			/bin/mkdir -p $(ODIR)/push_swap; fi

CMP 		=	if [ ! -e .cmp ]; then \
				echo $(Y)Compiling $(B)Project $(X)files...$(Y); \
				touch .cmp; fi

IF_CMP		=	if [ -e .cmp ]; then \
			$(CLR); \
			echo $(UP) $(CUT) $(UP); \
			/bin/rm -f .cmp; fi

BY			=	"\033[33;1m"
BR			=	"\033[31;1m"
BG			=	"\033[32;1m"
BB			=	"\033[34;1m"
BM			=	"\033[35;1m"
BC			=	"\033[36;1m"
BW			=	"\033[37;1m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
KW			=	"\033[37;5m"
KR			=	"\033[31;5m"
KG			=	"\033[32;5m"
KB			=	"\033[34;5m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "
CUT_UP		=	$(UP)$(CUT)$(UP)

.PHONY		: all, clean, fclean, re
