OS				=  $(shell uname -s)
SRC_PATH		=	src/
OBJ_PATH		=	obj/$(OS)
INCLUDE_PATH	=	include/
LPTHREAD		=	-lpthread
INCLUDE			=	-I$(INCLUDE_PATH)

CC				=	gcc
CFLAGS			=	-MD -Wall -Wextra -Werror $(INCLUDE)
LDFLAGS			=	$(LPTHREAD)

NAME			=	philo

RM				=	rm -rfv
LN				=	ln -s

OBJS			=	$(SRCS:.c=.o)

REL_CFLAGS		=	$(CFLAGS)
REL_LDFLAGS		=	$(LDFLAGS)
REL_OBJS		=	$(patsubst $(SRC_PATH)%,$(REL_PATH)%,$(SRCS:.c=.o))
REL_PATH		=	$(OBJ_PATH)/$(REL_SUFFIX)/
REL_SUFFIX		=	release

-include		sources.mk

all:				$(NAME)

$(REL_PATH)%.o:		$(SRC_PATH)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(REL_CFLAGS)

$(NAME):			$(REL_OBJS)
	$(CC) $(REL_OBJS) -o $@ $(REL_LDFLAGS)
#	strip $@

-include		debug.mk

re: fclean all

tag:
	ctags $(SRCS)

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

run:	all
	./$(NAME) $(arg)

.PHONY: re clean fclean debug sanitize
