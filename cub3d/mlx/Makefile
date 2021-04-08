##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

OS = $(shell uname -s)

ifeq ($(OS), Darwin)
		MLX = ./mlx
		LINK = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
else
		MLX = ./minilibx-linux
		LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif

all	: do_configure

do_configure	:
	./configure

clean	:
	./configure clean

re	: clean all
