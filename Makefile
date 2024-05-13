# Makefile pour INF3105 / TP3

#OPTIONS = -Wall           # option standard
#OPTIONS = -g -O0 -Wall    # pour rouler dans gdb
OPTIONS = -O2 -Wall        # pour optimiser

#
all : tp3

tp3 : tp3.cpp carte.h carte.o
	g++ ${OPTIONS} -o tp3 tp3.cpp carte.o -std=c++20

carte.o : carte.cpp carte.h graphe.h weightedEdge.h
	g++ ${OPTIONS} -c -o carte.o carte.cpp -std=c++20

clean:
	rm -rf tp3 *~ *.o

