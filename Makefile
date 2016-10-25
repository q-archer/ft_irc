# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 16:35:47 by qarcher           #+#    #+#              #
#    Updated: 2016/04/13 12:11:18 by qarcher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVEUR = serveur

CC = gcc

SRCDIR_CLIENT = srcs/client
SRCDIR_SERVEUR = srcs/serveur

OBJDIR_CLIENT = objs/client
OBJDIR_SERVEUR = objs/serveur

SRCS_CLIENT = $(SRCDIR_CLIENT)/main.c $(SRCDIR_CLIENT)/create_client.c \
	$(SRCDIR_CLIENT)/init_env.c $(SRCDIR_CLIENT)/read_client.c \
	$(SRCDIR_CLIENT)/write_client.c $(SRCDIR_CLIENT)/check_fd.c \
	$(SRCDIR_CLIENT)/main_loop.c $(SRCDIR_CLIENT)/init_fd.c \
	$(SRCDIR_CLIENT)/error_client.c

SRCS_SERVEUR = $(SRCDIR_SERVEUR)/main.c $(SRCDIR_SERVEUR)/create_server.c \
	$(SRCDIR_SERVEUR)/error_server.c $(SRCDIR_SERVEUR)/init_env.c \
	$(SRCDIR_SERVEUR)/debug_print_env.c $(SRCDIR_SERVEUR)/main_loop.c \
	$(SRCDIR_SERVEUR)/accept_server.c $(SRCDIR_SERVEUR)/init_fd.c \
	$(SRCDIR_SERVEUR)/check_fd.c $(SRCDIR_SERVEUR)/read_client.c \
	$(SRCDIR_SERVEUR)/clean_fd.c $(SRCDIR_SERVEUR)/send_message.c \
	$(SRCDIR_SERVEUR)/init_channel.c $(SRCDIR_SERVEUR)/manage_msg.c \
	$(SRCDIR_SERVEUR)/add_client.c $(SRCDIR_SERVEUR)/delete_client.c \
	$(SRCDIR_SERVEUR)/manage_cmd.c $(SRCDIR_SERVEUR)/nick_cmd.c \
	$(SRCDIR_SERVEUR)/join_cmd.c $(SRCDIR_SERVEUR)/who_cmd.c \
	$(SRCDIR_SERVEUR)/msg_cmd.c $(SRCDIR_SERVEUR)/help_cmd.c \
	$(SRCDIR_SERVEUR)/fill_buf_write.c $(SRCDIR_SERVEUR)/send_channel.c \
	$(SRCDIR_SERVEUR)/manage_line.c $(SRCDIR_SERVEUR)/cmd_server.c \
	$(SRCDIR_SERVEUR)/leave_cmd.c $(SRCDIR_SERVEUR)/list_cmd.c \
	$(SRCDIR_SERVEUR)/remove_from_channel.c $(SRCDIR_SERVEUR)/free_env.c

OBJS_CLIENT = $(SRCS_CLIENT:$(SRCDIR_CLIENT)/%.c=$(OBJDIR_CLIENT)/%.o)
OBJS_SERVEUR = $(SRCS_SERVEUR:$(SRCDIR_SERVEUR)/%.c=$(OBJDIR_SERVEUR)/%.o)

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I includes/ -I libft/includes

LIBS = -L libft/ -lft

all: libs $(CLIENT) $(SERVEUR)

libs:
	make -C libft/

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) -o $@ $(OBJS_CLIENT) $(LIBS)

$(SERVEUR): $(OBJS_SERVEUR)
	$(CC) $(FLAGS) -o $@ $(OBJS_SERVEUR) $(LIBS)

$(OBJDIR_CLIENT)/%.o: $(SRCDIR_CLIENT)/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDE)

$(OBJDIR_SERVEUR)/%.o: $(SRCDIR_SERVEUR)/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDE)

clean:
	make clean -C libft/
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVEUR)

fclean:
	make fclean -C libft/
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVEUR)
	rm -rf $(CLIENT) $(SERVEUR)

re: fclean all

.PHONY: all clean fclean re
