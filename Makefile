CXX = g++-11
CXXFLAGS = -std=c++20 -Wall -MMD -Werror=vla
SRCS = $(shell find . -type f -name "*.cc")
OBJECTS = ${SRCS:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a3q4

.PHONY: all clean

all: ${EXEC}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@ -lX11

-include ${DEPENDS}

clean:
	rm -rf ${DEPENDS} ${OBJECTS}
