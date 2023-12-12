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
    void printdouble()
    {
        if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else 
        {
            cout << "Jumlah Data :" << countdouble() << endl;            
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
    void ubahakhir(string x[4])
    {         
       if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{ 
        Supermarket *item = new Supermarket(); 
        tail->namabarang = x[0];
        tail->user=x[1];
        tail->mail=x[2];
        tail->pssword=x[3];
        }
    }
    int countdouble()
    {
        Supermarket *cur = new Supermarket();
        if(head == NULL)
        {
            cout << "double link belum dibuat!!";
        }
        else
        {
      
            cur = head;
            int sum = 0;
            while(cur != NULL)
            {
                sum++;
                cur = cur->next;
            }
            return sum;
        }
    
    }
    void ubahawal(string x[4])
    {         
       if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{ 
        Supermarket *item = new Supermarket(); 
        head->namabarang = x[0];
        head->user=x[1];
        head->mail=x[2];
        head->pssword=x[3];
        }
    }
    void deleteMiddle(int nomer)
    {  
      if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{
            if(nomer == 1)
            {
                cout << "bukan posisi tengah" << endl;
            }else if(nomer>countdouble()){
                cout << "posisi di luar jangkauan" << endl;
            }else{
                Supermarket *cur = new Supermarket();
                Supermarket *newnode = new Supermarket();
                Supermarket *afternode = new Supermarket(); 
                Supermarket *del = new Supermarket(); 
                
            
            cur = head;
            int hitung =1;
            while(hitung<nomer-1)
            {
                cur = cur->next;
                hitung++;
            }
            // cur->next = del;
            del = cur->next;
            afternode = del->next;
            cur->next = afternode;
            afternode->prev = cur;
            delete del;         
            }
        }
    }
    void addMiddle(string x[4],int nomer)
    {  
      if(head == NULL)
        {
            cout << "double linked belum dibuat" << endl;
        }else{
            if(nomer == 1)
            {
                cout << "bukan posisi tengah" << endl;
            }else if(nomer>countdouble()){
                cout << "posisi di luar jangkauan" << endl;
            }else{
                 Supermarket *cur = new Supermarket();
                Supermarket *newnode = new Supermarket();
                Supermarket *afternode = new Supermarket(); 
            
                newnode->namabarang = x[0];
                newnode->user=x[1];
                newnode->mail=x[2];
                newnode->pssword=x[3];
                cur = head;

            int hitung =1;
            while(hitung<nomer-1)
            {
                cur = cur->next;
                hitung++;
            }
            afternode = cur->next;
            newnode->prev = cur;
            newnode->next = afternode;
            cur->next = newnode;
            afternode->prev = newnode;         
            }
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
    string data3[4] = {"4","ubahakhir","ubah@gmail.com","9879"};
    string dataupdatefirst[4] = {"1","updatefirst","ubah@gmail.com","9879"};
    string datatengah[4] = {"mid","datatengah","tengah.com","9879"};
    ada.addfirst(data2);
    ada.ubahakhir(data3);
    ada.ubahawal(dataupdatefirst);
    ada.addMiddle(datatengah,2);
    ada.printdouble();
    ada.deleteMiddle(2);
    // ada.removeFirst();
    // ada.removeLast();
    ada.printdouble();


    

}