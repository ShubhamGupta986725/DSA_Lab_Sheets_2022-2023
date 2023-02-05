rm *.o
rm *exe
gcc -c set_C_checker.c
gcc -c quiz.c
gcc -o C_exe set_C_checker.o quiz.o
./C_exe