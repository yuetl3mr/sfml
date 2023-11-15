# SFML config 

all: compile link run

compile:
	g++ -c dropdownmenu.cpp -I"C:\SFML-2.6.1\include"
link:
	g++ dropdownmenu.o -o sfml-app -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	erase -f sfml-app *.o
run:
	.\sfml-app

