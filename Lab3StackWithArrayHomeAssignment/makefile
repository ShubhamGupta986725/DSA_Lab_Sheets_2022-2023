runStackWithArrayHA: stackDriver.o stack_array_HA.o
	gcc -o runStackWithArray stackDriver.o stack_array_HA.o
	./runStackWithArray

stack_array_HA.o: stack_array_HA.c stack2.h
	gcc -c stack_array_HA.c
	
stack_array.o: stack_array.c stack2.h
	gcc -c stack_array.c

clean:
	rm -f *.o runStackWithArray

