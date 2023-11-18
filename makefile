# SFML config 

all: compile link run

compile:
	g++ -c key_mouse_input_event.cpp -I"C:\SFML-2.6.1\include"
link:
	g++ key_mouse_input_event.o -o sfml-app -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	erase -f sfml-app *.o
run:
	.\sfml-app

