ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ;
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG 
#./push_swap $ARG | ./checker $ARG
#./push_swap $ARG | wc -l
#echo $ARG
#./push_swap $ARG
