rm *.o
rm *exe
gcc -c count_consonants.c
gcc -c master.c
gcc -o count_consonants_exe count_consonants.o master.o
./count_consonants_exe