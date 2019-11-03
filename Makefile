#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

## ** do not forget comment -Wno ! **
CC= gcc
CC_FLAGS= -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-function #-Wno-unused-but-set-parameter

#
#	Checker release variables
#

NAME= lem-in
LIBDIR= printf/libft
LIB= libft.a
LIBHEADER=libft.h
GNLHEADER=get_next_line.h
AVLTHEADER=avlt.h
LIBSHORT= ft
HEADERDIR= includes
SRCSDIR= srcs
HEADER= lem_in.h
OBJSDIR= objs
OBJS= $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o, $(wildcard $(SRCSDIR)/*.c))
SRCS= $(OBJS:.o=.c);

all: $(NAME)

#
#	Debug mode settings
#

debug: CC_FLAGS += $(DG_CC_FLAGS)
debug: $(NAME)

#
#	Release
#

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ -I$(HEADERDIR) -I$(LIBDIR) -L$(LIBDIR) -l$(LIBSHORT)

$(LIB):
	cd $(LIBDIR) && $(MAKE) -s

$(OBJS): $(OBJSDIR)/%.o : $(SRCSDIR)/%.c $(HEADERDIR)/$(HEADER)
	mkdir -p objs
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBDIR) -c $< -o $@

#
#	Clean
#

clean:
	rm -rf $(OBJSDIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all