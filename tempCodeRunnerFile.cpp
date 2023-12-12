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
            del->next = afternode;
            // del->prev = cur;
            cur->next = afternode;
            afternode->prev = cur;
            delete del;         
            }
        }
    }