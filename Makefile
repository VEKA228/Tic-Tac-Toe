# Target to build the final executable
all: TicTacToe

# Rule to link all object files and create the executable
TicTacToe: board.o game.o main.o painter.o point.o
	g++ -o TicTacToe board.o game.o main.o painter.o point.o

# Compile board.cpp into board.o
board.o: board.cpp board.hpp point.hpp
	g++ -c board.cpp -o board.o

# Compile game.cpp into game.o
game.o: game.cpp game.hpp board.hpp point.hpp
	g++ -c game.cpp -o game.o

# Compile main.cpp into main.o
main.o: main.cpp game.hpp board.hpp point.hpp painter.hpp
	g++ -c main.cpp -o main.o

# Compile painter.cpp into painter.o
painter.o: painter.cpp painter.hpp point.hpp
	g++ -c painter.cpp -o painter.o

# Compile point.cpp into point.o
point.o: point.cpp point.hpp
	g++ -c point.cpp -o point.o

# Clean up object files and executable
clean:
	del *.o TicTacToe.exe

