rm *.o
rm *exe
gcc -c set_B_checker.c
gcc -c quiz.c
gcc -o B_exe set_B_checker.o quiz.o
./B_exe