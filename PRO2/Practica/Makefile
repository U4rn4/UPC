OPCIONS = -DJUDGE -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: Barco.o Total_productos.o Ciudad.o Mapa.o program.o
	g++ -o program.exe Barco.o Total_productos.o Ciudad.o Mapa.o program.o

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONS)

Total_productos.o: Total_productos.cc Total_productos.hh
	g++ -c Total_productos.cc $(OPCIONS)

Ciudad.o: Ciudad.cc Ciudad.hh
	g++ -c Ciudad.cc $(OPCIONS)

Mapa.o: Mapa.cc Mapa.hh
	g++ -c Mapa.cc $(OPCIONS)

program.o: program.cc 
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe *.tar

tar:
	tar cvf practica.tar program.cc Barco.cc Barco.hh Total_productos.cc Total_productos.hh Ciudad.cc Ciudad.hh Mapa.cc Mapa.hh BinTree.hh Makefile