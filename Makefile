OS = $(shell uname -s)

# Linux 
EXE = glutapp

ifeq ($(OS),Darwin)
	LIBS = -framework GLUT -framework OpenGL -framework Cocoa
else
	LIBS = -lGL -lGLU -lglut
endif

CC = gcc
CFLAGS = -Wall -Wno-deprecated

SRC = glutapp.c

$(EXE):		$(SRC) 
		  	$(CC) -o $@ $< $(CFLAGS) $(LIBS) 

all:		$(EXE) 

clean:		$(EXE)
			rm $(EXE) 


