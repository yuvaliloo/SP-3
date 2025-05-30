CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC `pkg-config --cflags Qt5Widgets`
LDFLAGS = `pkg-config --libs Qt5Widgets`

SRC = main.cpp MainWindow.cpp Game.cpp Player.cpp Governor.cpp Spy.cpp Baron.cpp General.cpp Judge.cpp Merchant.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = game_gui

.PHONY: all clean valgrind run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

run: $(TARGET)
	./$(TARGET)
