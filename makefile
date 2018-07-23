output: main.o Block.o STransaction.o str-u256.o test.o chain.o
	g++ build/main.o build/Block.o lib/uint256_t/uint128_t.cpp lib/uint256_t/uint256_t.cpp build/STransaction.o build/test.o build/chain.o -o bin/output
main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o
Block.o: src/primitives/Block.cpp 
	g++ -c src/primitives/Block.cpp -o build/Block.o
STransaction.o: src/primitives/STransaction.cpp
	g++ -c src/primitives/STransaction.cpp -o build/STransaction.o
str-u256.o: src/util/str-u256.cpp 
	g++ -c src/util/str-u256.cpp -o build/str-u256.o
test.o: src/Tests.cpp
	g++ -c src/Tests.cpp -o build/test.o
chain.o: src/primitives/Chain.cpp
	g++ -c src/primitives/Chain.cpp -o build/chain.o
clean: 
	@echo "Cleaning..."
	rm bin/output
