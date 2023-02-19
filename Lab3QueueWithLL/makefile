runQueueWithLL: queueDriver.o queue_ll.o linked_list.o
	gcc -o runQueueWithLL queueDriver.o queue_ll.o linked_list.o
	./runQueueWithLL
	make clean

queueDriver.o: queueDriver.c queue_ll.h
	gcc -c queueDriver.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

queue_ll.o: queue_ll.c queue_ll.h
	gcc -c queue_ll.c

clean:
	rm -f *.o runQueueWithArray