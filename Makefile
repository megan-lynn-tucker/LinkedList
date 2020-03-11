CC = g++ -g
exe_file = linked_list
$(exe_file): driver.o linked_list.o node.o input.o
	$(CC) driver.o linked_list.o node.o input.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
node.o: node.cpp
	$(CC) -c node.cpp
input.o: input.cpp
	$(CC) -c input.cpp
clean:
	rm -f *.out *.o $(exe_file)
