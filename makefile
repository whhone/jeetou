all: genpng gencmd

genpng:	genpng.c
	gcc genpng.c -lpng -lass -o genpng

gencmd: gencmd.c
	gcc gencmd.c -lpng -lass -o gencmd

