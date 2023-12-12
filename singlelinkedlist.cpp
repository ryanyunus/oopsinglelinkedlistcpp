#include <iostream>
using namespace std;

// deklarasi single linked list
struct Buku{
  
//   komponen / member
string judul, pengarang;
int tahunTerbit;

Buku *next;

};

Buku *head, *tail, *cur, *newNode, *del;

// create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB){
head = new Buku();
head->judul = judul;
head->pengarang = pengarang;
head->tahunTerbit = tB;
head->next = NULL;
tail = head;
}

// tambahAwal single linked list
void addFrist(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

// tambahAkhir single linked list
void addLast(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// Remove First
void removeFrist(){
    del = head;
    head = head->next;
    delete del;
}

// Removw Last
void removeLast(){
    del = tail;
    cur = head;
    while ( cur->next != tail )
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// ubahAwal single linked list
void changeFrist(string judul, string pengarang, int tB){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

// ubahAkhir single linked list
void changeLast(string judul, string pengarang, int tB){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

// print single linked list
void printSingleLinkedList(){
cur = head;
while (cur != NULL){
    /* code */
    cout << "Judul Buku : " << cur->judul << endl;
    cout << "Pengarang Buku : " << cur->pengarang << endl;
    cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

    cur = cur->next;
    }
}

int main(){

    createSingleLinkedList("Kata", "Geez & Aan", 2018);
    printSingleLinkedList();

    cout << "\n\n" << endl;
addFrist("Dia adalah Kakakku", "Tere Liye", 2009);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addLast("Aroma Karsa", "Dee lestari", 2018);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    removeFrist();
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addLast("11.11", "Fiersa Besari", 2018);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    removeLast();
    printSingleLinkedList();
    cout << "\n\n" << endl;

    changeFrist("Berhenti di Kamu", "Gita Pratama", 2018);
    printSingleLinkedList();
    cout << "\n\n" << endl;

}
