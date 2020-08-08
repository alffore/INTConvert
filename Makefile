##
# Código que convierte coordenadas de un tipo a otro
#
# AAFR <alffore@gmail.com>
##


CC= g++ -c

CLINKER= g++ -lm -o

CFLAGS= -O2  -Wall -std=c++11

LIBS=

OBJ= main.o \
	LectorINT.o \
	Poligonal.o


DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/


all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)int2svg.exe $(OBJ) $(LIBS) $(CFLAGS)
	@rm -rf *.o


%.o: $(DIR_SRC)%.cpp
	$(CC) $(CFLAGS)  $<

clean:
	@rm -rfv *.o

	
