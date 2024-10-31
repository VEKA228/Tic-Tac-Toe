all: TicTacToe

TicTacToe: board.o game.o main.o painter.o point.o
	g++ -o TicTacToe.exe board.o game.o main.o painter.o point.o

board.o:
	g++ board.cpp -o board.o -c

game.o:
	g++ game.cpp -o game.o -c

main.o:
	g++ main.cpp -o main.o -c

painter.o:
	g++ painter.cpp -o painter.o -c

point.o:
	g++ point.cpp -o point.o -c

clean:
	del *.o TicTacToe.exe
