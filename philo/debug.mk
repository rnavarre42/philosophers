# Debug build settings
DBG_NAME 	= $(NAME)_$(DBG_SUFFIX)
DBG_PATH	= $(OBJ_PATH)/$(DBG_SUFFIX)/
DBG_OBJS	= $(patsubst $(SRC_PATH)%,$(DBG_PATH)%,$(SRCS:.c=.o))
DBG_CFLAGS	= -O0 -g3
DBG_SUFFIX	= debug

# Sanitize build settings
SAN_NAME	= $(NAME)_$(SAN_SUFFIX)
SAN_PATH	= $(OBJ_PATH)/$(SAN_SUFFIX)/
SAN_OBJS	= $(patsubst $(SRC_PATH)%,$(SAN_PATH)%,$(SRCS:.c=.o))
SAN_CFLAGS	= -O0 -g3 -fsanitize=address -DBONUS
SAN_LDFLAGS = -fsanitize=address
SAN_SUFFIX	= sanitize

# Rules
debug:		$(DBG_NAME)

sanitize:	$(SAN_NAME)

lib_debug:
	make -C $(LIBFT_PATH) debug

lib_sanitize:
	make -C $(LIBFT_PATH) sanitize

# Debug rules
$(DBG_NAME): $(DBG_OBJS)
	$(CC) -o $@ $(DBG_OBJS) $(LDFLAGS) $(DBG_LFT)

$(DBG_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(DBG_CFLAGS) $(CFLAGS)

$(DBG_LIBFT):
	make -C $(LIBFT_PATH) debug

# Sanitize rules
$(SAN_NAME):	$(SAN_OBJS)
	$(CC) -o $@ $(SAN_OBJS) $(SAN_LDFLAGS) $(LDFLAGS) $(SAN_LFT)

$(SAN_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(SAN_CFLAGS) $(CFLAGS)

$(SAN_LIBFT):
	make -C $(LIBFT_PATH) sanitize
