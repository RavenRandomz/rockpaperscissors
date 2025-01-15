INC_DIR = ./include
CXXFLAGS  = -Wall -Wextra -Weffc++ -Wconversion -Wsign-conversion -I$(INC_DIR)

run: rockpaperscissors
	./rockpaperscissors

rockpaperscissors: main.o classicarena.o humanplayer.o move.o randomautoplayer.o utility.o
	$(CXX) $(CXXFLAGS) main.o classicarena.o humanplayer.o move.o randomautoplayer.o utility.o -o rockpaperscissors

main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) -c ./src/main.cpp -o main.o

classicarena.o: ./src/classicarena.cpp
	$(CXX) $(CXXFLAGS) -c ./src/classicarena.cpp -o classicarena.o

humanplayer.o: ./src/humanplayer.cpp
	$(CXX) $(CXXFLAGS) -c ./src/humanplayer.cpp -o humanplayer.o

move.o: ./src/move.cpp
	$(CXX) $(CXXFLAGS) -c ./src/move.cpp -o move.o

randomautoplayer.o: ./src/randomautoplayer.cpp
	$(CXX) $(CXXFLAGS) -c ./src/randomautoplayer.cpp -o randomautoplayer.o

utility.o: ./src/utility.cpp
	$(CXX) $(CXXFLAGS) -c ./src/utility.cpp -o utility.o
clean:
	rm -rf *.o



