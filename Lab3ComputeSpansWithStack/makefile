runSpans: computeSpan.o stackWithLinkedList.o linked_list.o
	gcc -o span computeSpan.o stackWithLinkedList.o linked_list.o
	./span
	make clean

computeSpan.o: computeSpan.c stack.h linked_list.h
	gcc -c computeSpan.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

stackWithLinkedList.o: stackWithLinkedList.c stack.h linked_list.h
	gcc -c stackWithLinkedList.c

clean: 
	rm -f *.o
	rm span.exe