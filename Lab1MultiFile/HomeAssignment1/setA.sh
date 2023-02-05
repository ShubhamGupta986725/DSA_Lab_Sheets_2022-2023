rm *.o
rm *exe
gcc -c set_A_checker.c
gcc -c quiz.c
gcc -o A_exe set_A_checker.o quiz.o
./A_exe