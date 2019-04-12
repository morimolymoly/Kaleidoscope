build:
	clang++ lex/lex.cpp stubs/io.cpp main.cpp -o bin

run: build unittest
	./bin

unittest:
	clang++ lex/lex.cpp stubs/io.cpp  test/lex.cpp  -o lbin 2> /dev/null
	./lbin
	rm lbin

test:
	./test.sh
