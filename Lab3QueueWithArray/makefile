runQueueWithArray: queueDriver.o QueueArray.o heap_usage.o
	gcc -o runQueueWithArray queueDriver.o QueueArray.o heap_usage.o
	./runQueueWithArray

queueDriver.o: queueDriver.c Queue.h
	gcc -c queueDriver.c

QueueArray.o: QueueArray.c Queue.h heap_usage.h
	gcc -c QueueArray.c

heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c

clean:
	rm -f *.o runQueueWithArray