CHECKER		=	checker

PUSH_SWAP	=	push_swap

############################## DIRS ############################################

CHKDIR		=	checker

PSDIR		=	push_swap

CMNDIR		=	common

LFTDIR		=	./libft

IDIR		=	./includes

SDIR		=	./srcs

ODIR		=	./objs

############################## SRCS ############################################

# **************************************************************************** #
# Checker :

CHK_FILES	=	$(addprefix $(CHKDIR)/, \
		checker.c get_instructions.c get_flags.c exec_inst.c display.c)

# **************************************************************************** #
# Common :

CMN_FILES	=	$(addprefix $(CMNDIR)/, \
		params_to_stack.c get_input.c debug.c swap.c push.c rotate.c \
		reverse_rotate.c mem_tools.c error.c instruction_tools.c \
		struct_tools.c is_sorted.c)

# **************************************************************************** #
# Push_swap :

PS_FILES	=	$(addprefix $(PSDIR)/, \
		push_swap.c get_median.c rec_inst.c sorting_tools.c sort_a.c sort_b.c \
		small_sort.c)

# **************************************************************************** #
# Complete path :

CHK_SRCS	=	$(addprefix $(SDIR)/, $(CHK_FILES))

PS_SRCS		=	$(addprefix $(SDIR)/, $(PS_FILES))

CMN_SRCS	=	$(addprefix $(SDIR)/, $(CMN_FILES))

############################## OBJS ############################################

CHK_OBJS	=	$(CHK_FILES:.c=.o)

PS_OBJS		=	$(PS_FILES:.c=.o)

CMN_OBJS	=	$(CMN_FILES:.c=.o)

CHK_OBJ		=	$(addprefix $(ODIR)/, $(CHK_OBJS))

PS_OBJ		=	$(addprefix $(ODIR)/, $(PS_OBJS))

CMN_OBJ		=	$(addprefix $(ODIR)/, $(CMN_OBJS))

OBJ			=	$(CHK_OBJ) $(PS_OBJ) $(CMN_OBJ)

############################## INCS ############################################

LFT			=	$(addprefix $(LFTDIR)/, libft.a)

LFT_INC_DIR	=	$(addprefix $(LFTDIR)/, $(IDIR))

LFT_INC		=	$(addprefix $(LFTDIR)/, $(IDIR)/libft.h)

PS_INC		=	$(addprefix $(IDIR)/, push_swap.h)

CMN_INC		=	$(addprefix $(IDIR)/, common.h)

CHK_INC		=	$(addprefix $(IDIR)/, checker.h)

HEADERS		=	$(CHK_INC) $(CMN_INC) $(PS_INC) $(LFT_INC)

INCS		=	$(addprefix -I,$(IDIR) $(LFT_INC_DIR))

############################## COMP ############################################

CC			=	gcc

CFLAGS		=	$(DEBUG) $(if $(SILENT), , -Wall -Wextra -Werror)

############################## RULES ###########################################

all			:	$(CHECKER) $(PUSH_SWAP)

$(CHECKER)	:	$(LFT) $(CMN_OBJ) $(CMN_INC) $(CHK_OBJ) $(CHK_INC)
			@$(CC) $(CFLAGS) -o $(CHECKER) $(CMN_OBJ) $(CHK_OBJ) $(LFT) $(INCS)
			@$(IF_CMP)
			@echo $(BG)[$(BLB)CHECKER $(BG)COMPILED$(BG)]$(X)

$(PUSH_SWAP):	$(LFT) $(CMN_OBJ) $(CMN_INC) $(PS_OBJ)
			@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(CMN_OBJ) $(PS_OBJ) $(LFT) $(INCS)
			@$(IF_CMP)
			@echo $(BG)[$(BLB)PUSH_SWAP $(BG)COMPILED$(BG)]$(X)

$(ODIR)/%.o	:	$(SDIR)/%.c $(HEADERS)
			@$(CMP)
			@$(MKODIR)
			@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
			@$(CLR)
			@echo -n $@

$(LFT)		:
		@$(MAKE) DEBUG="$(DEBUG)" -C $(LFTDIR)

clean		:
	@$(MAKE) clean -C $(LFTDIR)
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(ODIR)
	@echo $(BG)[$(BLB)PUSH_SWAP $(BG)CLEANED$(BG)]$(X)

fclean		:	clean
	@/bin/rm -f $(LFT)
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)

re			:	fclean all

############################## UTIL ############################################

MKODIR 		=	if [ ! -d $(ODIR) ]; then \
			/bin/mkdir -p $(ODIR); \
			/bin/mkdir -p $(ODIR)/checker; \
			/bin/mkdir -p $(ODIR)/common; \
			/bin/mkdir -p $(ODIR)/push_swap; fi

CMP 		=	if [ ! -e .cmp ]; then \
				echo $(BY)Compiling $(B)Project $(X)files...$(BY); \
				touch .cmp; fi

IF_CMP		=	if [ -e .cmp ]; then \
			$(CLR); \
			echo $(UP) $(CUT) $(UP); \
			/bin/rm -f .cmp; fi

############################## DISPLAY #########################################

BY			=	"\033[1;33m"
BR			=	"\033[1;31m"
BG			=	"\033[1;32m"
BLB			=	"\033[1;36m"
BP			=	"\033[1;35m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[0;32m"
B			=	"\033[34m"
P			=	"\033[35m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "
CUT_UP		=	$(UP)$(CUT)$(UP)

############################## OTHER ###########################################

.PHONY		: all, clean, fclean, re
