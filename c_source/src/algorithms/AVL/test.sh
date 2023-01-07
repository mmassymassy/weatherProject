awk -F ";" '{print $3}' ../BST/test.csv > test.txt 
gcc ./test.c ./avl.c -o a 
./a  ./test.txt 