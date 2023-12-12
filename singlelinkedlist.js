class Buku {
    constructor(judul, pengarang, tahunTerbit) {
      this.judul = judul;
      this.pengarang = pengarang;
      this.tahunTerbit = tahunTerbit;
      this.next = null;
    }
  }
  
  class SingleLinkedList {
    constructor() {
      this.head = null;
      this.tail = null;
    }
  
    addFirst(judul, pengarang, tahunTerbit) {
      const newNode = new Buku(judul, pengarang, tahunTerbit);
      if (this.head === null) {
        this.head = newNode;
        this.tail = newNode;
      } else {
        newNode.next = this.head;
        this.head = newNode;
      }
    }
  
    addLast(judul, pengarang, tahunTerbit) {
      const newNode = new Buku(judul, pengarang, tahunTerbit);
      if (this.head === null) {
        this.head = newNode;
        this.tail = newNode;
      } else {
        this.tail.next = newNode;
        this.tail = newNode;
      }
    }
  
    removeFirst() {
      if (this.head !== null) {
        const temp = this.head;
        this.head = this.head.next;
        temp.next = null;
      }
    }
  
    removeLast() {
      if (this.head !== null) {
        if (this.head === this.tail) {
          this.head = null;
          this.tail = null;
        } else {
          let cur = this.head;
          while (cur.next !== this.tail) {
            cur = cur.next;
          }
          cur.next = null;
          this.tail = cur;
        }
      }
    }
  
    countSingleLinkedList() {
      let count = 0;
      let cur = this.head;
      while (cur !== null) {
        count++;
        cur = cur.next;
      }
      return count;
    }
  
    printSingleLinkedList() {
      console.log("Jumlah data ada: " + this.countSingleLinkedList());
      let cur = this.head;
      while (cur !== null) {
        console.log("Judul Buku: " + cur.judul);
        console.log("Pengarang Buku: " + cur.pengarang);
        console.log("Tahun Terbit Buku: " + cur.tahunTerbit);
        cur = cur.next;
      }
    }
  
    addMiddle(judul, pengarang, tahunTerbit, posisi) {
      if (posisi <= 0 || this.head === null) {
        this.addFirst(judul, pengarang, tahunTerbit);
      } else if (posisi >= this.countSingleLinkedList()) {
        this.addLast(judul, pengarang, tahunTerbit);
      } else {
        const newNode = new Buku(judul, pengarang, tahunTerbit);
        let cur = this.head;
        for (let i = 1; i < posisi; i++) {
          cur = cur.next;
        }
        newNode.next = cur.next;
        cur.next = newNode;
      }
    }
  }
  
  const myLinkedList = new SingleLinkedList();
  
  myLinkedList.addFirst("Kata", "Geez & Aan", 2018);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addFirst("Dia adalah Kakakku", "Tere Liye", 2009);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.removeFirst();
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addLast("11.11", "Fiersa Besari", 2018);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.removeLast();
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addFirst("Berhenti di Kamu", "Gia Pratama", 2018);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addMiddle("Bumi Manusia", "Pramoedya Anata Toer", 2005, 2);
  myLinkedList.printSingleLinkedList();
  console.log("\n");
  
  myLinkedList.addMiddle("Negeri 5 Menara", "Ahmad Fuadi", 2009, 2);
  myLinkedList.printSingleLinkedList();
  console.log("\n");