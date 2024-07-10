# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 13:08:56 by pschemit          #+#    #+#              #
#    Updated: 2022/05/09 17:57:47 by pschemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		:=	src/
OBJS_DIR		:=	obj/
BIN_DIR			:=	bin/

SRV_SRCS		:=	server.c
CLT_SRCS		:=	client.c

SRV_SRCS_PATH	:=	$(addprefix $(SRCS_DIR), $(SRV_SRCS))
CLT_SRCS_PATH	:=	$(addprefix $(SRCS_DIR), $(CLT_SRCS))

SRV_OBJS		:=	${SRV_SRCS_PATH:.c=.o}
CLT_OBJS		:=	${CLT_SRCS_PATH:.c=.o}

SRV_OBJS_PATH	:=	$(subst $(SRCS_DIR),$(OBJS_DIR), $(SRV_OBJS))
CLT_OBJS_PATH	:=	$(subst $(SRCS_DIR),$(OBJS_DIR), $(CLT_OBJS))

NAME			:=	minitalk
SRV				:=	server
CLT				:=	client

SRV_PATH		:=	$(addprefix $(BIN_DIR), $(SRV))
CLT_PATH		:=	$(addprefix $(BIN_DIR), $(CLT))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror -Imlx

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				@$(CC) $(CFLAGS) -c $< -o ${addprefix $(OBJS_DIR), ${<:$(SRCS_DIR)%.c=%.o}}

${NAME}			: ${SRV_PATH} ${CLT_PATH}

${SRV_PATH}		: ${SRV_OBJS_PATH}
				@mkdir -p $(BIN_DIR)
				@$(CC) ${CFLAGS} $(SRV_OBJS_PATH) -o $(SRV_PATH)

${CLT_PATH}		: ${CLT_OBJS_PATH}
				@mkdir -p $(BIN_DIR)
				@$(CC) ${CFLAGS} $(CLT_OBJS_PATH) -o $(CLT_PATH)

server			: ${SRV_PATH}

client			: ${CLT_PATH}

all				: server client

clean			:
				@rm -f $(SRV_OBJS_PATH)
				@rm -f $(CLT_OBJS_PATH)

fclean			: clean
				@rm -f $(SRV_PATH)
				@rm -f $(CLT_PATH)
				@rm -r $(OBJS_DIR)
				@rm -r $(BIN_DIR)

re				: fclean all

.PHONY			: all server client clean fclean re