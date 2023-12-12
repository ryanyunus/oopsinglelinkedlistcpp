#include <iostream>
using namespace std;

class School{
public:
    string nama;
    int tahunberdiri;
    School *next;
};
class Singlelinked{
public:
    School *kepala;
    School *buntut;
    Singlelinked(){
        kepala = nullptr;
        buntut = nullptr;
    }
    void createnode(string nm,int tb)
    {
        School *nodebaru = new School();
        nodebaru->nama = nm;
        nodebaru->tahunberdiri = tb;
        nodebaru->next = nullptr;
        if(kepala == nullptr)
        {
            kepala = nodebaru;
            buntut = nodebaru;
            buntut->next = nullptr;
        }
        else
        {
            //  kepala = nodebaru; jika dibuka maka infinite loop karena kepala sudah ada isinya
             buntut->next = nodebaru;
             buntut = nodebaru;
             buntut->next = nullptr;     
        }
    }
    void printsingle()
    {
        cout << "jumlah singlelinklist " << hitunglinkdelist() << endl;  
        School *now = kepala;
        while(now != nullptr)
        {

            cout << "nama sekolah " << now->nama << endl;
            cout << "tahun berdiri " << now->tahunberdiri <<endl;
            now = now->next;

        }
    }
    void addfirst(string nm, int tahun)
    {
        School *nodebaru = new School();
        nodebaru->nama = nm;
        nodebaru->tahunberdiri = tahun;
        nodebaru->next = kepala;
        kepala = nodebaru;
        // buntut = kepala->next;         
    }
    void addlast(string nama, int tahun)
    {
        School *nodebaru;
        nodebaru->next = nullptr;
        nodebaru->nama = nama;
        nodebaru->tahunberdiri = tahun;
        if(buntut!=nullptr)
        {
            buntut->next = nodebaru;
            buntut=nodebaru;
        }
        else
        {
            kepala = nodebaru;
            buntut = nodebaru;
        }
    }
    void delnodeawal()
    {
    
      School *nodebaru;
      if(kepala!=nullptr)
      {
        nodebaru = kepala;
        kepala = kepala->next;
        delete nodebaru;
      }
      else
      {
        kepala = nullptr;
        buntut = nullptr;
      }
    }
    void deletelastnode()
    {
       if (kepala == nullptr)
       {
        cout << "list kosong" << endl;
        return;
       }
       if(kepala->next == nullptr)
       {
        delete kepala;
        kepala = nullptr;
        buntut = nullptr;
        return;
       }
        // School *cur = new School();
        School *cur = kepala;
        while(cur->next != buntut)
        {
            // prev = cur;
            cur = cur->next;
        }
            delete buntut;            
            cur->next = nullptr;
            buntut  = cur;
        
    }
    void editawal(string nm, int thn)
    {
        kepala->nama = nm;
        kepala->tahunberdiri = thn;
    }
    void editakhir(string nm, int thn)
    {
        buntut->nama = nm;
        buntut->tahunberdiri = thn;
    }
    
    void masuktengah(string nm, int thn, int nmr)
    {
      if(nmr<1 || nmr> hitunglinkdelist())
       {
        cout << "posisi di luar jangkauan" << endl;
       }
       else if(nmr ==1 || nmr == hitunglinkdelist())
       {
        cout << "posisi bukan posisi tengah" << endl;
       }else{
        School *item = new School;
        item->nama = nm;
        item->tahunberdiri = thn;
        School *cur = kepala;
        int idx=0;
        while(cur!=nullptr&&idx<nmr-1)
        {
            cur = cur->next;
            idx++;
        }
        if(cur!=nullptr)
        {
            item->next = cur->next;
            cur->next = item;
        }
        }
    }
    void deletetengah(int nmr)
    {
       if(nmr<1 || nmr> hitunglinkdelist())
       {
        cout << "posisi di luar jangkauan" << endl;
       }
       else if(nmr ==1 || nmr == hitunglinkdelist())
       {
        cout << "poisis bukan posisi tengah" << endl;
       }
       else 
       {
       School *cur = new School();
       School *del = new School();
       School *prev = new School();
 
       int i=1;
       cur = kepala;
       while(i<=nmr)
       {
            if(i == nmr-1)
            {
                prev = cur;
            }
            if(i == nmr)
            {
                del = cur;
            }
            cur = cur->next;
            i++;
       }
       prev->next = cur;
       delete del;
       }
       
    }
    void ubahtengah(string nm, int th, int nmr)
    {
       School *cur = new School();
       if(nmr<1 || nmr> hitunglinkdelist())
       {
        cout << "posisi di luar jangkauan" << endl;
       }
       else if(nmr ==1 || nmr == hitunglinkdelist())
       {
        cout << "poisis bukan posisi tengah" << endl;
       }
       else {
        cur = kepala;
        int num = 1;
        while(num < nmr)
        {
            cur = cur -> next;
            num++;
        }
        cur->nama = nm;
        cur->tahunberdiri = th;
       }
    }
    int hitunglinkdelist()
    {
        // cout << "cuk" << endl;
       
        School *cur = new School();
        cur = kepala;
        int sum =  0;
        while (cur!= NULL)
        {
            cur = cur->next;
            sum++;
        }
        // cout << " sum :  " << sum << endl;
        return sum;
        

    }
};

int main()
{
    Singlelinked objbaru;
    objbaru.createnode("tiga",1998);
    objbaru.addfirst("dua",2000);
    objbaru.addlast("empat",2010);
    objbaru.addfirst("satu",8000);
    objbaru.addlast("lima",2010);
    objbaru.delnodeawal();
    objbaru.deletelastnode();
    objbaru.editawal("duauedit",2010);
    objbaru.addfirst("mbuhfirst",2020);
    objbaru.editakhir("empatedit",2023);
    objbaru.masuktengah("tengah",2000,2);
    objbaru.deletetengah(2);
    // objbaru.hitunglinkdelist();
    objbaru.ubahtengah("tengaubah",2000,3);
    // objbaru.hitunglinkdelist();
    objbaru.printsingle();
}