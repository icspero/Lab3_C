CXX = g++-11
CXXFLAGS = -I/path/to/boost/include
LDFLAGS = -L/path/to/boost/lib -lboost_system -lboost_timer

TARGET = Benchmark_Main
SRC = Benchmark_Main.cpp
OUTPUT = Benchmarks.html

all: $(TARGET)
	./$(TARGET)
	xdg-open $(OUTPUT)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean