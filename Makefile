# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:05:11 by jaguillo          #+#    #+#              #
#    Updated: 2015/02/26 18:07:01 by fcosnefr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
all: client server

client:
	@make -f client.Makefile

server:
	@make -f server.Makefile

clean:
	@make -f client.Makefile clean
	@make -f server.Makefile clean

_clean:
	@make -f client.Makefile _clean
	@make -f server.Makefile _clean

fclean:
	@make -f client.Makefile fclean
	@make -f server.Makefile fclean

_fclean:
	@make -f client.Makefile _fclean
	@make -f server.Makefile _fclean

debug:
	@make -f client.Makefile debug
	@make -f server.Makefile debug

rebug:
	@make -f client.Makefile rebug
	@make -f server.Makefile rebug

_rebug:
	@make -f client.Makefile _rebug
	@make -f server.Makefile _rebug

re: fclean all

_re:
	@make -f client.Makefile _re
	@make -f server.Makefile _re