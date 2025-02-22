all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Gen.cpp -o ./lib/Gen.o
	g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
	g++ -c -I "./include" ./src/KromozomDugum.cpp -o ./lib/KromozomDugum.o
	g++ -c -I "./include" ./src/KromozomListesi.cpp -o ./lib/KromozomListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/Gen.o ./lib/Kromozom.o ./lib/KromozomDugum.o ./lib/KromozomListesi.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program