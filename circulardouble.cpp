#include <iostream>
using namespace std;

class School{
public:
    string nama,nim,email;
    School *next;
    School *prev;
};
class Singlelinked{
public:
    School *kepala;
    School *buntut;
    School *cur;
    School *del;
    Singlelinked(){
        kepala = nullptr;
        buntut = nullptr;
        // cur = nullptr;
    }
    void createcircular(string y[3])
    {
        kepala = new School;
        kepala->nama = y[0];
        kepala->nim = y[1];
        kepala->email = y[2];
        buntut = kepala;
        buntut->next = kepala;
    }
     void addfirst(string y[3])
    {
        School *newnode = new School();
        newnode->nama = y[0];
        newnode->nim = y[1];
        newnode->email = y[2];
        newnode->next = kepala;
        buntut->next = newnode;
        kepala = newnode;
    }
       void addmiddle(string y[3],int posisi)
    {
        if(kepala == NULL)
        {
            cout << "Buat Linked List dulu!!" <<endl;
        }else
        {
            if(posisi==1)
            {
                cout << "Posisi satu bukan posisi tengah" <<endl;
            }else
            {
                School *newnode = new School();
                newnode->nama = y[0];
                newnode->nim = y[1];
                newnode->email = y[2];
                
                int iterasi=1;
                cur = kepala;
                while(iterasi<posisi-1)
                {
                    cur = cur->next;
                    iterasi++;
                }
                newnode->next = cur->next;
                cur->next = newnode;
                
            }
        }
       
    }
    void addlast(string y[3])
    {
        School *newnode = new School();
        newnode->nama = y[0];
        newnode->nim = y[1];
        newnode->email = y[2];
        newnode->next = kepala;
        buntut->next = newnode;
        buntut = newnode;
    }
    void removefirst()
    {
        del = kepala;
        kepala = kepala->next;
        buntut->next = kepala;
        delete del;
    }
     void removelast()
    {
        del = buntut;
        cur = kepala;
        while(cur->next!=buntut)
        {
            cur=cur->next;
        }
        buntut = cur;
        buntut->next = kepala;
        delete del;
    }
    void printcircular()
    {
        if (kepala == nullptr) {
            cout << "Daftar kosong" << endl;
            return;
        }
        cout << "Data mahasiswa" << endl;
        cout << "=====================================" <<endl;
        cout << "|NPM\t\t|Nama\t\t|Jurusan|" <<endl;
        cout << "=====================================" <<endl;
        
        cur = kepala;
        while(cur->next != kepala)
        {

             cout << "|" << cur->nama <<"\t\t|" << cur->nim <<"\t\t|"<< cur->email <<"|" <<endl;
             cur = cur->next;
             cout << "=====================================" <<endl;
        }
        
        cout << "|" << cur->nama <<"\t\t|" << cur->nim <<"\t\t|"<< cur->email <<"|" <<endl;
        cout << "=====================================" <<endl;
       

    }
    
};

int main()
{
    Singlelinked objbaru;
    string data[3] = {"diky","001","gmail"};
    string data1[3] = {"riky","003","gmail"};
    string data2[3] = {"ryan","002","gmail"};
    string data3[3] = {"riko","002","gmail"};
    objbaru.createcircular(data);
    objbaru.addfirst(data2);
    objbaru.addlast(data1);
    // objbaru.removefirst();
    // objbaru.removelast();
    objbaru.printcircular();
    objbaru.addmiddle(data3,3);
    objbaru.printcircular();

    return 0;
}
  
  