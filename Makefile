build:
	clang++ lex.cpp -o bin

run: build
	./bin

test:
	./test.sh
