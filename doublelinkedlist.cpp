#include <iostream>
#include <string>
using namespace std;

class Supermarket{
public:
    string namabarang,user,mail,pssword;
    Supermarket *next;
    Supermarket *prev;
    Supermarket *head;
    Supermarket *tail;
    void createdoublelinkedlist(string x[4])
    {    
        head = new Supermarket(); 
        head->namabarang = x[0];
        head->user=x[1];
        head->mail=x[2];
        head->pssword=x[3];
        head->prev=NULL;
        head->next=NULL;
        tail=head;
    }
    void addfirst(string x[4])
    {         
       if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{ 
        
        Supermarket *item = new Supermarket(); 
        item->namabarang = x[0];
        item->user=x[1];
        item->mail=x[2];
        item->pssword=x[3];
        item->prev=NULL;
        item->next=head;
        head->prev=item;
        head=item;
        }
    }
     void addlast(string x[4])
    {         
       if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{ 
        Supermarket *item = new Supermarket(); 
        item->namabarang = x[0];
        item->user=x[1];
        item->mail=x[2];
        item->pssword=x[3];
        item->prev=tail;
        tail->next = item;
        item->next=NULL;
        tail=item;
        }
    }
    int printdouble()
    {
        if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else 
        {
        Supermarket *saiki = head;
        // saiki = head;
        while(saiki!=NULL)
        {
            cout << "Nama user : " << saiki->namabarang <<endl;
            cout << "Username user : " << saiki->user<<endl;
            cout << "Email : " << saiki->mail <<endl;
            cout << "Password : " << saiki->pssword <<endl;
            saiki = saiki->next;    
        }
        }
        
    }
    void removeFirst()
    {
        Supermarket *del = new Supermarket();
         if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else 
        {
        
            del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        }
    }
     void removeLast()
    {
        Supermarket *del = new Supermarket();
         if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else 
        {
        
            del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
        }
    }
};

int main()
{
    Supermarket ada;

    //print
    string data[4] = {"2","ryan","ryandinus@gmail.com","12334"};
    string data1[4] = {"3","last","last@gmail","12334"};
    ada.createdoublelinkedlist(data);
    ada.addlast(data1);
    string data2[4] = {"1","usersarimi","mie@gmail.com","12334"};
    ada.addfirst(data2);
    ada.removeFirst();
    ada.removeLast();
    ada.printdouble();

    

}