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
    School *afternode;
    Singlelinked(){
        kepala = nullptr;
        buntut = nullptr;
        // cur = nullptr;
    }
    void createcirculardoublelink(string y[3])
    {
        kepala = new School;
        kepala->nama = y[0];
        kepala->nim = y[1];
        kepala->email = y[2];
        kepala->prev = kepala;
        kepala->next = kepala;
        buntut = kepala;
    }
     void addfirst(string y[3])
    {
        School *newnode = new School();
        newnode->nama = y[0];
        newnode->nim = y[1];
        newnode->email = y[2];
        newnode->next = kepala;
        newnode->prev = buntut;
        kepala->prev = newnode;
        buntut->next = newnode;
        kepala = newnode;
    }
    void delfirst()
    {
        School *newnode = new School();
        del = kepala;
        cur = kepala->next;
        kepala = cur;
        buntut->next = kepala;
        kepala->prev = buntut;
        delete del;
    }
    void dellast()
    {
        School *newnode = new School();
        del = buntut;
        buntut = buntut->prev;
        buntut->next = kepala;
        kepala->prev = buntut;
        delete del;

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
            }else if(posisi < 1)
            {
                cout << "Posisi di luar jangkauan" <<endl;
            }
            else
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
                afternode = cur->next;
                cur->next = newnode;
                afternode->prev = newnode;
                newnode->prev = cur;
                newnode->next = afternode;
               }
        }
       
     }
     void removemiddle(int posisi)
    {
        if(kepala == NULL)
        {
            cout << "Buat Linked List dulu!!" <<endl;
        }else
        {
            if(posisi==1)
            {
                cout << "Posisi satu bukan posisi tengah" <<endl;
            }else if(posisi < 1)
            {
                cout << "Posisi di luar jangkauan" <<endl;
            }else
            {
                School *newnode = new School();   
                int iterasi=1;
                cur = kepala;
                while(iterasi<posisi-1)
                {
                    cur = cur->next;
                    iterasi++;
                }
                del = cur->next;
                // cur->next = del->next;
                afternode = del->next;
                cur->next = afternode;
                afternode->prev = cur;
                delete del;
                
            }
        }
       
    }
    void addlast(string y[3])
    {
        School *newnode = new School();
        newnode->nama = y[0];
        newnode->nim = y[1];
        newnode->email = y[2];
        newnode->prev = buntut;
        newnode->next = kepala;
        kepala->prev = newnode;
        buntut->next = newnode;
        buntut = newnode;
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
    objbaru.createcirculardoublelink(data1);
    objbaru.addfirst(data2);
    // objbaru.printcircular();
    objbaru.addlast(data3);
    // objbaru.delfirst();
    // objbaru.dellast();
    // objbaru.printcircular();
    // objbaru.removefirst();
    // objbaru.removelast();
    // objbaru.printcircular();
    objbaru.addmiddle(data3,3);
    objbaru.removemiddle(2);
    objbaru.printcircular();
    // objbaru.removemiddle(2);
    // objbaru.printcircular();

    return 0;
}
  
  