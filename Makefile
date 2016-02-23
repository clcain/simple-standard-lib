linked-list:
	g++ main.cpp -o linked-list

clean:
	rm -f *.o

exclean: clean
	rm -f linked-list
