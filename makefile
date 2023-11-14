all: compile link

compile:
	g++ -c window.cpp -I"C:\SFML-2.6.1\include"
link:
	g++ window.o -o sfml-app -L"C:\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f main *.o
