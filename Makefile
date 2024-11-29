
# Directoare
TEST_DIR = tests
TEST_POINT = $(TEST_DIR)/test_point
TEST_BOARD = $(TEST_DIR)/test_board
TEST_PAINTER = $(TEST_DIR)/test_painter
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build


# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -I$(INCLUDE_DIR) -Wall -Wextra

# Fisiere Point
POINT_SRC = $(SRC_DIR)/point/point.cpp
POINT_OBJ = $(BUILD_DIR)/point.o
POINT_LIB = $(BUILD_DIR)/libpoint.a

# Fisiere Board
BOARD_SRC = $(SRC_DIR)/board/board.cpp
BOARD_OBJ = $(BUILD_DIR)/board.o
BOARD_LIB = $(BUILD_DIR)/libboard.a

# Fisiere Painter
PAINTER_SRC = $(SRC_DIR)/painter/painter.cpp
PAINTER_OBJ = $(BUILD_DIR)/painter.o
PAINTER_LIB = $(BUILD_DIR)/libpainter.a

# Fisiere Game și Main
GAME_SRC = $(SRC_DIR)/game.cpp
GAME_OBJ = $(BUILD_DIR)/game.o

MAIN_SRC = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(BUILD_DIR)/main.o

# Executabil final
EXECUTABLE = TicTacToe

# Reguli implicite
all: $(EXECUTABLE)

# Crearea executabilului
$(EXECUTABLE): $(MAIN_OBJ) $(GAME_OBJ) $(POINT_LIB) $(BOARD_LIB) $(PAINTER_LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Crearea bibliotecii statice pentru Point
$(POINT_LIB): $(POINT_OBJ)
	ar rcs $@ $^

# Compilare Point
$(POINT_OBJ): $(POINT_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crearea bibliotecii statice pentru Board
$(BOARD_LIB): $(BOARD_OBJ)
	ar rcs $@ $^

# Compilare Board
$(BOARD_OBJ): $(BOARD_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crearea bibliotecii statice pentru Painter
$(PAINTER_LIB): $(PAINTER_OBJ)
	ar rcs $@ $^

# Compilare Painter
$(PAINTER_OBJ): $(PAINTER_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilare Game
$(GAME_OBJ): $(GAME_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilare Main
$(MAIN_OBJ): $(MAIN_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crearea directorului build
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)


# Clean
clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(EXECUTABLE).exe del /q $(EXECUTABLE).exe
	@if exist tests\test_point.exe del /q tests\test_point.exe
	@if exist tests\test_board.exe del /q tests\test_board.exe
	@if exist tests\test_painter.exe del /q tests\test_painter.exe

# Test executables
tests: $(TEST_POINT) $(TEST_BOARD) $(TEST_PAINTER)

# Test for Point
$(TEST_POINT): $(TEST_DIR)/test_point.cpp $(POINT_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(POINT_LIB)

# Test for Board
$(TEST_BOARD): $(TEST_DIR)/test_board.cpp $(BOARD_LIB) $(POINT_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(BOARD_LIB) $(POINT_LIB)

# Test for Painter
$(TEST_PAINTER): $(TEST_DIR)/test_painter.cpp $(PAINTER_LIB) $(POINT_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(PAINTER_LIB) $(POINT_LIB)

# Run all tests
run-tests: tests
	./$(TEST_POINT)
	./$(TEST_BOARD)
	./$(TEST_PAINTER)