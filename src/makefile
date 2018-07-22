output: main.o Block.o STransaction.o str-u256.o test.o chain.o
	g++ main.o Block.o ../uint256_t/uint128_t.cpp ../uint256_t/uint256_t.cpp STransaction.o test.o chain.o -o output
main.o: main.cpp
	g++ -c main.cpp -o main.o
Block.o: primitives/Block.cpp 
	g++ -c primitives/Block.cpp -o Block.o
STransaction.o: primitives/STransaction.cpp
	g++ -c primitives/STransaction.cpp -o STransaction.o
str-u256.o: util/str-u256.cpp 
	g++ -c util/str-u256.cpp
test.o: Tests.cpp
	g++ -c Tests.cpp -o test.o
chain.o: primitives/Chain.cpp
	g++ -c primitives/Chain.cpp -o chain.o
clean: 
	rm *.o
	rm output
