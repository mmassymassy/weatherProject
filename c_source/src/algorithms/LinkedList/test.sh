# awk -F ";" '{print $3}' ../BST/test.csv > test.txt 
gcc ./test.c ./linked_list.c -o a 
./a  ./test.txt 