# SFML config 

all: compile link run

compile:
	g++ -c texture_test.cpp -I"C:\SFML-2.6.1\include"
link:
	g++ texture_test.o -o sfml-app -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	erase -f sfml-app *.o
run:
	.\sfml-app

