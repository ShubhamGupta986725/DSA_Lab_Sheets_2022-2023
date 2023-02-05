rm *.o
rm *exe
gcc -c count_vowels.c
gcc -c master.c
gcc -o count_vowels_exe count_vowels.o master.o
./count_vowels_exe
