output: main.o Block.o STransaction.o
	mpiCC main.o Block.o ../uint256_t/uint128_t.cpp ../uint256_t/uint256_t.cpp STransaction.o -o output
main.o: main.cpp
	mpiCC -c main.cpp -o main.o
Block.o: primitives/Block.cpp 
	mpiCC -c primitives/Block.cpp -o Block.o
STransaction.o: primitives/STransaction.cpp
	mpiCC -c primitives/STransaction.cpp -o STransaction.o
clean: 
	rm *.o
	rm output
