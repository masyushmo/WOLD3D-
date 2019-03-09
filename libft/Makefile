#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 15:02:11 by mmasyush          #+#    #+#              #
#    Updated: 2018/10/29 16:44:31 by mmasyush         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -O3 -Wall -Werror -Wextra -I. -c

SRCS = ft_bzero.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_memalloc.c \
					ft_memdel.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_strchr.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strncpy.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strnew.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_strrev.c \
					ft_strchan.c \
					ft_memcmp.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_atoi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_sqrt.c \
					ft_expon.c \
					ft_factorial.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstnew.c \
					ft_lstmap.c \
					get_next_line.c \
					percent.c \
					line_pos.c \

OUT = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all