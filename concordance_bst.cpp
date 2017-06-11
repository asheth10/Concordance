#include "concordance.h"
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
namespace CS_concordance
{

concordance::concordance(concordance& source)
{
        root=copy(source.root);
}

concordance::Node* concordance::copy(Node *p)
{
        Node *temp;
        if(p==NULL)
                return NULL;
        else
        {
                temp=new Node;
                strcpy(temp->w,p->w);
                temp->c=p->c;
                temp->left=copy(p->left);
                temp->right=copy(p->right);
                return temp;
        }
}


concordance::~concordance()//destructor
{
        destroy(root);
}

void concordance::destroy(Node *p)
{
        if(p!=NULL)
        {
                destroy(p->left);//left child
                destroy(p->right);//right child
                delete p;
        }
}


void concordance::insert(word entry)
{
        help_insert(root,entry);

}

void concordance::help_insert(Node *&p,word entry)
{
        if(p==NULL)//if initially empty
        {
                p=new Node;
                strcpy(p->w,entry);
                p->c=1;
                p->left=NULL;
                p->right=NULL;
        }
        else if(strcmp(entry,p->w)<0)//if entry is alphabetically smaller
        {
                help_insert(p->left,entry);//look to the left child of the tree
        }
        else if(strcmp(p->w,entry)==0)//if entry is the word
                p->c+=1;//increment count associated with the word
        else//if entry is alphabetically larger than the word
                help_insert(p->right,entry);//look to the right child of the tree
}


void concordance::print()
{
        cout<<setw(17)<<left<<"Word"<<"Count"<<endl;
        cout<<"----------------------"<<endl;
        help_print(root);
        cout<<"----------------------"<<endl;
}

void concordance::help_print(Node* p)
{
        if(p!=NULL)
        {
                help_print(p->left);
                cout<<setw(18)<<left<<p->w<<p->c<<endl;
                help_print(p->right);
        }
}


int concordance::get_count(word entry)
{
        return help_count(root,entry);
}

int concordance::help_count(Node *p,word entry)
{
        if(p==NULL)//if word not in the concordance
                return 0;
        else if(strcmp(entry,p->w)<0)//if entry is alphabetically smaller
                help_count(p->left,entry);//look to the left child
        else if(strcmp(entry,p->w)>0)//if entry is alphabetically larger
                help_count(p->right,entry);//look to the right child
        else//if entry is the word
                return p->c;//return the count associated with the word
}

size_t concordance::length()
{
        return concordance::get_length(root);
}

size_t concordance::get_length(Node *p)
{
        if(p==NULL)
                return 0;
        else
                return get_length(p->left)+get_length(p->right)+1;
}

}
