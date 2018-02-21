build:
	g++ cpp_build.cpp -o cpp_build

movebin: build
	sudo chmod a+rx cpp_build
	sudo mv cpp_build /usr/local/bin

all: build movebin