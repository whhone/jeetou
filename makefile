BIN_DIR=bin
GCC=gcc

all: genpng gencmd

genpng:	src/genpng.c
	${GCC} \
	-I/usr/local/Cellar/libass/0.13.2/include -L/usr/local/Cellar/libass/0.13.2/lib \
	-I/usr/local/Cellar/libpng/1.6.21/include -L/usr/local/Cellar/libpng/1.6.21/lib \
	src/genpng.c -lpng -lass \
	-o ${BIN_DIR}/genpng

gencmd: src/gencmd.c
	${GCC} \
	-I/usr/local/Cellar/libass/0.13.2/include -L/usr/local/Cellar/libass/0.13.2/lib \
	-I/usr/local/Cellar/libpng/1.6.21/include -L/usr/local/Cellar/libpng/1.6.21/lib \
	src/gencmd.c -lpng -lass \
	-o ${BIN_DIR}/gencmd

clean:
	rm bin/genpng
	rm bin/gencmd