cc = g++ -g
main : main.o d_deque.o dll_deque.o flavio_josefo.o 
	cc -g -o main main.o d_deque.o dll_deque.o flavio_josefo.o 

main.o : main.c d_deque.h dll_deque.h flavio_josefo.h 
	cc -g -c main.c 

d_deque.o : d_deque.c d_deque.h
	cc -g -c d_deque.c

dll_deque.o : dll_deque.c dll_deque.h
	cc -g -c dll_deque.c

flavio_josefo.o : flavio_josefo.c flavio_josefo.h
	cc -g -c flavio_josefo.c



clean :
	-rm *.o $(objects)
	-rm main