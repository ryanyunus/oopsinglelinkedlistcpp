#include <iostream>
using namespace std;


//kelas manusia
class Manusia{
  public:
    string nama;
    int tangan,kaki;
    Manusia* berikut;

    //Konstruktor
    Manusia(string namaorg,int tanganorg,int kakiorg)
    {
      nama = namaorg;
      tangan = tanganorg;
      kaki = kakiorg;
      berikut = nullptr;
    }
};

class LatihSingleLinkedlist{
private:
  Manusia* kepala;
  Manusia* buntut;

public:
  //konstruktor
  LatihSingleLinkedlist(){
      kepala = nullptr;
      buntut = nullptr;
  }
  //method single linked list
  void createSingleLinked(string nm, int tgn, int kki)
  {
    kepala = new Manusia(nm, tgn, kki);
    kepala->berikut = nullptr;
    buntut = kepala;
  }
  void printsinglinkedlist(){
    Manusia* sekarang = kepala;
    while(sekarang != nullptr)
    {
      cout << "nama " << sekarang->nama << endl;
      cout << "jumlah-tangan: " << sekarang->tangan<< endl;
      cout << "jumlah-kaki : " << sekarang->kaki << endl;
      sekarang = sekarang->berikut;
    }
  }

};

int main(){
  LatihSingleLinkedlist manusiabaru;

  manusiabaru.createSingleLinked("ryan",2,2);
  manusiabaru.printsinglinkedlist();

  cout << "test\n\n" << endl;
}