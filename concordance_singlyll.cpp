#include "concordance.h"
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
namespace CS_concordance
{
concordance::~concordance()//destructor
{
        concordance::give_back(first);
}

void concordance::give_back(Node *p)
{
        if(p!=NULL)
        {
                concordance::give_back(p->next);
                delete p;
        }
}

void concordance::insert(word entry)
{
        insert_help(first,entry);

}
void concordance::insert_help(Node *&p,word entry)
{
        if(p==NULL||strcmp(entry,p->w)<0)
                p=get_node(entry,p,1);
        else if(strcmp(p->w,entry)==0)
                p->c+=1;
        else
                insert_help(p->next,entry);
}

int concordance::length()
{
        return concordance::get_length(first);
}

int concordance::get_length(Node *l)
{
        if(l==NULL)
                return 0;
        else
                return 1+concordance::get_length(l->next);
}

ostream& operator<<(std::ostream& out_s,concordance c)
{
        out_s<<setw(17)<<left<<"Word"<<"Count"<<endl;
        out_s<<"----------------------"<<endl;
        c.concordance::write(out_s,c.first);
        out_s<<"----------------------"<<endl;
        return out_s;
}
void concordance::write(std::ostream& o_f,Node *p)
{
        if(p!=NULL)
        {
                o_f<<setw(18)<<left<<p->w<<p->c<<endl;
                concordance::write(o_f,p->next);
        }
}

concordance::Node* concordance::get_node(word entry,Node* link, count counts)
{
        Node *temp;
        temp=new Node;
        strcpy(temp->w,entry);
        temp->next=link;
        temp->c=counts;
        return temp;
}
}
