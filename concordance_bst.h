#ifndef CONCORDANCE_H
#define CONCORDANCE_H

#include <cstdlib>
#include <iostream>
#include <string>

namespace CS_concordance
{
    const size_t MAX=8;//maximum length of word allowed
class concordance
{
    public:
        typedef char word[MAX+1];//what can go in concordance
        typedef size_t count;//number of words

        concordance(){root=NULL;}//default constructor
        //post: concordance initialized to be empty

        concordance(concordance& source);//copy constructor
        //post:the invoking concordance initialized as copy of source

        ~concordance();//destructor

        void insert(word entry);
        //pre ::a word no longer than 8 characters
        //post::inserts the word in the invoking concordance


        std::size_t length();
        //post:returns the length of invoking concordance

        void print();
        //post:print the contents of a concordance to the output stream

        int get_count(word entry);
        //post:returns the count associated with a word in the concordance

    private:
        struct Node
        {
            word w;//word
            count c;//count for the word
            Node *left;//pointer to the left child
            Node *right;//pointer to the right child
        };
        Node *root;//pointer to the first node of the tree


        Node* copy(Node *p);
        //post:called by the constructor to copy the contents of one tree to another

        void help_print(Node *p);
        //post:called by print() to print the concordance to an output stream

        void help_insert(Node *&p,word entry);
        //post:called by insert() to insert a word in the concordance

        void destroy(Node *p);
        //post:called by the destructor to deallocate memory

        int help_count(Node *p,word entry);
        //post:called by the get_count function to get the count for a word in the concordance

        size_t get_length(Node *p);
        //post:called by the length() function to get the total number of unique words in the concordance
};

}
#endif // CONCORDANCE_H
