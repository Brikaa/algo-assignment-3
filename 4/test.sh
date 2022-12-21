while read p; do
    echo $p | ./a.out
done < tests.txt
