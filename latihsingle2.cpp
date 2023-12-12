#include <iostream>
using namespace std;
class Mobil
{
public:
    string nama;
    int roda;
    int pintu;
    Mobil *next;
};

class singlelinkmobil
{
private:
    Mobil *kepala;
    Mobil *buntut;

public:     
    
     singlelinkmobil() {
        kepala = nullptr;
        buntut = nullptr;
    }

    void createSingleLinked(string nm, int pt)
    {
        Mobil *itembaru = new Mobil();
        itembaru->nama = nm;
        itembaru->pintu = pt;
        itembaru->next = nullptr;
        if(kepala == nullptr)
        {
            kepala = itembaru;
            buntut = itembaru;
        }else
        {
            buntut->next = itembaru;
            // buntut = itembaru;
        }
      
    }
    void printsinglink()
    {
        Mobil *saatini = kepala;
        while(saatini != nullptr)
        {
         cout << "nama mobil  : " << saatini->nama << endl;
         cout << "punya pintu : " << saatini->pintu << endl;
         saatini = saatini->next;
        }
    }
    void tambahawal(string nama,int pintu)
    {
         Mobil *itembaru = new Mobil();
            itembaru->nama = nama;
            itembaru->pintu = pintu;
            itembaru->next = kepala;
            kepala = itembaru;

            if(buntut == nullptr)
            {
                buntut = itembaru;
            }
    }
};
int main(){
  singlelinkmobil mobilobj;
  mobilobj.createSingleLinked("inova",2);
  mobilobj.createSingleLinked("alphard",2);
  mobilobj.tambahawal("ferrari",5);
  mobilobj.tambahawal("bmwold",2);
  mobilobj.printsinglink();
 
//   cout << "test\n\n" << endl;
}