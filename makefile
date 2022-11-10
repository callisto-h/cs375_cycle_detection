# Specifiy the target
all: executable.exe

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
executable.exe: main.o LL.o
	g++ main.o LL.o -g -o executable.exe

# Specify how the object files should be created from source files
main.o: main.cpp
	g++ -c -g main.cpp

LL.o: LL.cpp LL.h
	g++ -c -g LL.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.h.gch executable.exe