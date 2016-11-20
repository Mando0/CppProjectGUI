all:
	g++ main.cpp newWin.cpp -o main -std=c++11 `fltk-config --ldflags`
