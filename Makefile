#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	Checker release variables
#

NAME= lem-in
LIBDIR= libft
LIB= libft.a
LIBHEADER=libft.h
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
#	Release checker
#

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -L$(LIBDIR) -l$(LIBSHORT) -o $@

$(LIB):
	cd $(LIBDIR) && $(MAKE) -s

$(OBJS): $(OBJSDIR)/%.o : $(SRCSDIR)/%.c $(HEADERDIR)/$(HEADER)
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBDIR) -c $< -o $@

#
#	Clean
#

clean:
	rm -rf $(OBJSDIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all