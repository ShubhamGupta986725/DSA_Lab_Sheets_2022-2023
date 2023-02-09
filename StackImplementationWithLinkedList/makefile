runStackWithLL: stackDriver.o stackWithLinkedList.o linked_list.o
	gcc -o runStackWithLL stackDriver.o stackWithLinkedList.o linked_list.o
	./runStackWithLL

stackDriver.o: stackDriver.c stack.h linked_list.h
	gcc -c stackDriver.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

stackWithLinkedList.o: stackWithLinkedList.c stack.h linked_list.h
	gcc -c stackWithLinkedList.c

clean:
	rm -f *.o runStackWithLL