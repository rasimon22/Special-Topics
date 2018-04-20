output: main.o Block.o 
	mpiCC main.o Block.o primitives/uint256_t/uint128_t.cpp primitives/uint256_t/uint256_t.cpp  -o output
main.o: main.cpp
	mpiCC -c main.cpp -o main.o
Block.o: primitives/Block.cpp 
	mpiCC -c primitives/Block.cpp -o Block.o
clean: 
	rm *.o
	rm output
