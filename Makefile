CXX = g++
CPPFLAGS = -I./include

example : example.cpp
	$(CXX) -o $@ $< -std=c++11 $(CPPFLAGS)

clean:
	rm example
