##
# Código que convierte coordenadas de un tipo a otro
#
# AAFR <alffore@gmail.com>
##


CC= g++ -c

CLINKER= g++ -o

CFLAGS= -O2  -Wall -std=c++14

LIBS= -lm -lproj

OBJ= main.o \
	LectorINT.o \
	Poligonal.o \
	ConvertidorC.o \
	SalidaINT.o


DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/


all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)intconvert.exe $(OBJ) $(LIBS) $(CFLAGS)
	@rm -rf *.o


%.o: $(DIR_SRC)%.cpp
	$(CC) $(CFLAGS)  $<

clean:
	@rm -rfv *.o

	
