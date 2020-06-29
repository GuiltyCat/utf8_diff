CXX=gcc
CXXFLAGS=-std=c17 -O3 -Wall -Wextra -pedantic

SRC=utf8_diff.c

PROJECT=utf8_diff

.PHONY:all clean $(PROJECT)

all:$(PROJECT)

$(PROJECT):$(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	\rm -rf $(PROJECT)
