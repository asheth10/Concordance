# Concordance
A Concordance class and its implementation written in C++.

Concordance of a text is an alphabetical list of all words that appear in the text with their respective counts. In this program, the maximum allowed length of a word is 8 characters. Suppose, we have two words, manipulate and manipulation. The program identifies those two words as two instances of "manipula". Also, all non alphabetical characters are treated as word separators. In addition to its primary function, this program also allows user to look for a word and return the count associated with it.

The concordance class was separately implemented using two data structures: Singly linked list and Binary Search Trees. Both data structures were designed using pointers. A data structure Node was defined  with required data elements and pointer to the following nodes. A node in singly linked structure contains a word, its count and a pointer to the next node. In a Binary Search Tree, a node contains a word, its count and nodes to its children.


 
# Implementation using singly-linked list structure

concordance_singlyll.h/concordance_singlyll.cpp

# Implementation using Binary Search Trees structure

concordance_bst.h/concordance_bst.cpp

# Main Program

mainpro.cpp
