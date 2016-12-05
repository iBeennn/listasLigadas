#compilador
CC=gcc
#para que busque los .h en el directorio base
CFLAGS=-I.
#nombre del ejecutable resultante
EJEC=usaLista

# Las dos lineas de abajo hacen lo mismo que 
# obj = $(patsubst %.c,%.o,$(wildcard *.c))
# sirven para crear una lista de todos los .o que se deben crear, uno por cada .c
src= $(wildcard *.c)
#sustituye la extension de los .c de la lista src
obj=  $(src:%.c=%.o)

# la variable $< se sustituye por la primera dependencia
%.o: %.c
	$(CC) -c $< $(CFLAGS)

all: $(obj)
	$(CC) -o $(EJEC) $(obj)

clean:
	rm -fr *~ *.o $(EJEC)
