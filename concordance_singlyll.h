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

        concordance(){first=NULL;}//default constructor
        //post: concordance initialized to be empty

        ~concordance();//destructor

        void insert(word entry);
        //post: calls the insert_help function to insert a word


        int length();
        //post::calls the get_length function to return the length of a concordance

        friend std::ostream& operator<<(std::ostream& out_s,concordance c);
        //post:: concordance c written to out_s by calling write function

    private:
        struct Node
        {
            word w;//word
            count c;//count for the word
            Node *next;//pointer to the next word
        };
        Node *first;//pointer to the first word

        Node* get_node(word entry,Node* link,count counts);
        //post::returns a pointer to the new node with a word,count and pointer to next node

        void give_back(Node *p);
        //post:deallocates memory(used by destructor)
        void insert_help(Node* &p,word entry);
        //post: inserts a word in a concordance(used by insert function)
        int get_length(Node *l);
        //post: returns the length of a concordance(used by length function)
        void write(std::ostream& o_f,Node *p);
        //post: writes the content of concordance(used by overloaded << friend function)
};

}
#endif // CONCORDANCE_H
