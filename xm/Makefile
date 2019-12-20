OS = $(shell uname -s)

# Linux 
EXE = paperplane

ifeq ($(OS),Darwin)
	LIBS = -framework GLUT -framework OpenGL -framework Cocoa
else
	LIBS = -lGL -lGLU -lGLX -lGLw -lXm -lXt -lXext -lX11 -lm
endif

CC = gcc
CFLAGS = #-Wall -Wno-deprecated
LIBPATH = /usr/lib/x86_64-linux-gnu/

SRC = paperplane.c

$(EXE):		$(SRC) 
		  	$(CC) -o $@ $< $(CFLAGS) -L$(LIBPATH) $(LIBS) 

all:		$(EXE) 

clean:		$(EXE)
			rm $(EXE) 


