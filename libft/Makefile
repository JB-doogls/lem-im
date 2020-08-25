# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoll <edoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 22:58:53 by edoll             #+#    #+#              #
#    Updated: 2019/09/20 22:58:53 by edoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FUNCTIONS = ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_strlen \
			ft_strdup \
			ft_strsdup \
			ft_strcpy \
			ft_strncpy \
			ft_strcat \
			ft_strncat \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strstr \
			ft_strnstr \
			ft_strcmp \
			ft_strncmp \
			ft_atoi \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_memalloc \
			ft_strnew \
			ft_memdel \
			ft_strdel \
			ft_strclr \
			ft_striter \
			ft_striteri \
			ft_putchar_fd \
			ft_putchar \
			ft_putstr_fd \
			ft_putstr \
			ft_putstr_color \
			ft_putendl_fd \
			ft_putendl \
			ft_putnbr_fd \
			ft_putnbr_color \
			ft_putnbr \
			ft_strmap \
			ft_strmapi \
			ft_strsub \
			ft_strequ \
			ft_strnequ \
			ft_strjoin \
			ft_strtrim \
			ft_iswspace \
			ft_strsplit \
			ft_word_count \
			ft_power \
			ft_long_power \
			ft_nbrmax \
			ft_nbrmin \
			ft_strrev \
			ft_itoa \
			ft_itoa_base \
			ft_lstnew \
			ft_lstdelone \
			ft_lstdel \
			ft_lstadd \
			ft_lstadd_back \
			ft_lstiter \
			ft_lstmap \
			ft_lstinsert_before \
			ft_lstinsert_after \
			ft_lstnewset \
			ft_strjoin_free \
			get_next_line

OBJ		= $(patsubst %,%.o,$(FUNCTIONS))
SRC		= $(patsubst %,%.c,$(FUNCTIONS))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
HEAD	= libft.h

# ---- Colors ----
RED		= "\033[0;31m"
GREEN	= "\033[0;32m"
CYAN	= "\033[0;36m"
EOC		= "\033[0m"
# ================

all: $(NAME)

$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	@echo $(GREEN) "object files libft created" $(EOC)
	ar rc $(NAME) $(OBJ)
	@echo $(GREEN) "static lib file created" $(EOC)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@echo $(RED) "libft object files deleted" $(EOC)

fclean: clean
	/bin/rm -f $(NAME)
	@echo $(RED) "libft static lib file deleted" $(EOC)

re: fclean all

.PHONY: all clean fclean re
