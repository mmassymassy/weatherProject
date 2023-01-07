awk -F ";" '{print $3}' ./test.csv > test.txt 
gcc ./test.c ./bst.c -o a 
./a  ./test.txt 