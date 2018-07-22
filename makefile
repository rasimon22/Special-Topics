output: main.o Block.o STransaction.o str-u256.o test.o chain.o
	g++ main.o Block.o lib/uint256_t/uint128_t.cpp lib/uint256_t/uint256_t.cpp STransaction.o test.o chain.o -o output
main.o: src/main.cpp
	g++ -c src/main.cpp -o main.o
Block.o: src/primitives/Block.cpp 
	g++ -c src/primitives/Block.cpp -o Block.o
STransaction.o: src/primitives/STransaction.cpp
	g++ -c src/primitives/STransaction.cpp -o STransaction.o
str-u256.o: src/util/str-u256.cpp 
	g++ -c src/util/str-u256.cpp
test.o: src/Tests.cpp
	g++ -c src/Tests.cpp -o test.o
chain.o: src/primitives/Chain.cpp
	g++ -c src/primitives/Chain.cpp -o chain.o
clean: 
	rm *.o
	rm output
