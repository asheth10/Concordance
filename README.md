# Concordance
A Concordance class and its implementation written in C++.

Concordance of a text is the count of all words that appear in the text. 

In this program, the maximum allowed length of a word is 8 characters.

#A sample run of the program:
Enter an input file name: n.txt
Do you want to view the concordance?(y/n): y

Word             Count
----------------------
a                 2
certain           1
contains          1
file              1
is                1
it                1
manipula          1
number            1
of                1
program           1
text              1
the               1
this              1
to                1
tries             1
words             1
----------------------
This file contains 16 distinct words.

Do you want to check occurrence of a word in the concordance?(y/n): n



#Implementation using singly-linked list structure (Iterative)
concordance_singly.h/concordance_singly.cpp
 
#Implementation using singly-linked list structure (Recursive)
concordance_recursive.h/concordance_recursive.cpp

#implementation using Binary Search Trees structure
concordance_bst.h/concordance_bst.cpp
