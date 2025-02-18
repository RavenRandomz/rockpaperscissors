INC_DIR = ./include
CXXFLAGS  = -Wall -Wextra -Weffc++ -Wconversion -Wsign-conversion -I$(INC_DIR)

run: rockpaperscissors
	./rockpaperscissors

rockpaperscissors: main.o classicarena.o humanplayer.o move.o randomautoplayer.o utility.o weightedautoplayer.o roundinfo.o learningautoplayer.o
	$(CXX) $(CXXFLAGS) main.o classicarena.o humanplayer.o move.o randomautoplayer.o utility.o weightedautoplayer.o roundinfo.o learningautoplayer.o -o rockpaperscissors

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

weightedautoplayer.o: ./src/weightedautoplayer.cpp
	$(CXX) $(CXXFLAGS) -c ./src/weightedautoplayer.cpp -o weightedautoplayer.o

utility.o: ./src/utility.cpp
	$(CXX) $(CXXFLAGS) -c ./src/utility.cpp -o utility.o

roundinfo.o: ./src/roundinfo.cpp
	$(CXX) $(CXXFLAGS) -c ./src/roundinfo.cpp -o roundinfo.o

learningautoplayer.o: ./src/learningautoplayer.cpp
	$(CXX) $(CXXFLAGS) -c ./src/learningautoplayer.cpp -o learningautoplayer.o
clean:
	rm -rf *.o



