#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

## ** do not forget comment -Wno ! **
CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	Checker release variables
#

NAME= lem-in
LIBDIR= printf/libft
LIB= libft.a
LIBHEADER=libft.h
LIBPFDIR= printf
LIBPF= libftprintf.a
LIBPFHEADER=libftprintf.h
GNLHEADER=get_next_line.h
AVLTHEADER=avlt.h
LIBSHORT= ft
LIBPFSHORT= ftprintf
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

$(NAME): $(LIB) $(LIBPF) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ -I$(HEADERDIR) -I$(LIBDIR) -I$(LIBPFDIR) -L$(LIBDIR) -l$(LIBSHORT) -L$(LIBPFDIR) -l$(LIBPFSHORT)

$(LIB):
	cd $(LIBDIR) && $(MAKE) -s

$(LIBPF):
	cd $(LIBPFDIR) && $(MAKE) -s

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