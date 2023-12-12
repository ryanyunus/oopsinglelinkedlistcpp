#include <iostream>
using namespace std;

    // Deklarasi class Buku
    class Buku {
    public:
        string judul, pengarang;
        int tahunTerbit;
        Buku* next;

        // Konstruktor
        Buku(string _judul, string _pengarang, int _tahunTerbit) {
            judul = _judul;
            pengarang = _pengarang;
            tahunTerbit = _tahunTerbit;
            next = nullptr;
        }
    };

// Deklarasi class SingleLinkedList
class SingleLinkedList {
private:
    Buku* head;
    Buku* tail;

public:
    // Konstruktor
    SingleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Method untuk menambahkan buku di awal
    void addFirst(string judul, string pengarang, int tahunTerbit) {
        Buku* newNode = new Buku(judul, pengarang, tahunTerbit);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Method untuk menambahkan buku di akhir
    void addLast(string judul, string pengarang, int tahunTerbit) {
        Buku* newNode = new Buku(judul, pengarang, tahunTerbit);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method untuk menghapus buku di awal
    void removeFirst() {
        if (head != nullptr) {
            Buku* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method untuk menghapus buku di akhir
    void removeLast() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Buku* cur = head;
                while (cur->next != tail) {
                    cur = cur->next;
                }
                delete tail;
                tail = cur;
                tail->next = nullptr;
            }
        }
    }

    // Method untuk mencetak jumlah buku dalam linked list
    int countSingleLinkedList() {
        int jumlah = 0;
        Buku* cur = head;
        while (cur != nullptr) {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }

    // Method untuk mencetak semua buku dalam linked list
    void printSingleLinkedList() {
        cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
        Buku* cur = head;
        while (cur != nullptr) {
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
            cur = cur->next;
        }
    }
    // Method untuk menambahkan buku di tengah-tengah
    void addMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
        if (posisi <= 0 || head == nullptr) {
            addFirst(judul, pengarang, tahunTerbit);
        } else if (posisi >= countSingleLinkedList()) {
            addLast(judul, pengarang, tahunTerbit);
        } else {
            Buku* newNode = new Buku(judul, pengarang, tahunTerbit);
            Buku* cur = head;
            for (int i = 1; i < posisi; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
};

int main() {
    SingleLinkedList myLinkedList;

    myLinkedList.addFirst("Kata", "Geez & Aan", 2018);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addFirst("Dia adalah Kakakku", "Tere Liye", 2009);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.removeFirst();
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addLast("11.11", "Fiersa Besari", 2018);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.removeLast();
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addFirst("Berhenti di Kamu", "Gia Pratama", 2018);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addMiddle("Bumi Manusia", "Pramoedya Anata Toer", 2005, 2);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    myLinkedList.addMiddle("Negeri 5 Menara", "Ahmad Fuadi", 2009, 2);
    myLinkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    return 0;
}