# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:41:55 by jdenis            #+#    #+#              #
#    Updated: 2024/02/08 10:46:24 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	cc

CFLAGS		= 	-Wall -Wextra -Werror -g -O3 -I $(HEADER) -fsanitize=thread

HEADER		= 	includes/

CPPFLAGS	= 	-I srcs/													\
				-I includes/												\
				-I srcs/utils/												\
				-I srcs/actions/											\
				

OBJS		=																\
																			\
				$(addprefix srcs/,											\
				main.o														\
				philo.o														\
				data.o														\
				handle_args.o												\
				monitoring.o												\
																			\
				$(addprefix actions/,										\
				eat.o														\
				think.o														\
				sleep.o						)								\
																			\
				$(addprefix utils/,											\
				ft_atoi.o													\
				print_lock.o												\
				exit_philo.o												\
				ft_usleep.o					))								\
																			\

NAME		=	philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re