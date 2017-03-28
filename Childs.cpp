#include "Childs.h"
#include "singlecircular.h"
using namespace std;

void CreateList_c(List_c &LC){
    first(LC) = NULL;
    last(LC) = NULL;
};

address_c alokasi_c(int ID, string nama, string alamat, string nohp, string gender){
    address_c PC;
    PC = new elmlist_c;
    info_c(PC).ID = ID;
    info_c(PC).nama = nama;
    info_c(PC).alamat = alamat;
    info_c(PC).nohp = nohp;
    info_c(PC).gender = gender;
    next(PC) = NULL;
    prev(PC) = NULL;
        return PC;
};
void dealokasi_c(address_c &PC){
    delete PC;
};
void insertFirst_c(List_c &LC, address_c PC){
    if (first(LC) == NULL){
        first(LC) = PC;
        last(LC) = PC;
    }
    else{
        next(PC) = first(LC);
        prev(first(LC)) = PC;
        first(LC) = PC;
    }
};
void insertAfter_c(List_c &LC, address_c Precc, address_c PC){
    if (first(LC) == NULL){
        PC = first(LC);
        PC = last(LC);
    }
    else if (first(LC) == last(LC)){
        next(Precc) = PC;
        prev(PC) = Precc;
        last(LC) = PC;
    }
    else{
        next(PC) = next(Precc);
        prev(PC) = Precc;
        next(Precc) = PC;
        prev(next(PC)) = PC;
    }
};
address_c findElm_c(List_c LC, int x){
    address_c C = first(LC);
    if (first(LC) == NULL){
        C = NULL;
    }
    else if(first(LC) == last(LC)){
        C = first(LC);
    }
    else{
        while (info_c(C).ID != x && (C) != last(LC)){
            C = next(C);
        }
    }
    return C;
};
void deleteFirst_c(List_c &LC, address_c &PC){
    PC = first(LC);
    if (first(LC) == NULL){
        cout<<"Data kosong \n";
    }
    else if(PC == last(LC)){
        first(LC) = NULL;
        last(LC) = NULL;
        dealokasi_c(PC);
    }
    else{
        prev(next(PC)) = NULL;
        first(LC) = next(PC);
        next(PC) = NULL;
        dealokasi_c(PC);
    }
};
void deleteafter_c(List_c &LC, address_c &Precc, address_c &PC){
    PC = first(LC);
    if (first(LC) == NULL){
        cout<<"Data kosong \n";
    }
    else if(PC == first(LC)){
        deleteFirst_c(LC,PC);
    }
    else{
        PC = next(Precc);
        next(Precc) = next(PC);
        prev(next(PC)) = Precc;
        next(PC) = NULL;
        prev(PC) = NULL;
        dealokasi_c(PC);
    }
}
void printInfo_c(List_c LC){
    int i;
    i = 1;
    if (first(LC) == NULL){
        cout<<"data kosong";
    }
    else{
    address_c C;
    C = first(LC);
    while(C != last(LC)){
        cout<<"List Pasien ke-"<<i<<"\n";
        cout<<"----------"<<endl;
            cout<<"ID       :"<<info_c(C).ID<<endl;
            cout<<"Nama     :"<<info_c(C).nama<<endl;
        C = next(C);
        i = i+1;
    }cout<<"List Pasien ke-"<<i<<endl;
    cout<<"----------"<<endl;
            cout<<"ID       :"<<info_c(C).ID<<endl;
            cout<<"Nama     :"<<info_c(C).nama<<endl;
    }
};
void insertAscending_c(List_c &LC, int ID, string nama,string alamat, string nohp, string gender){
    address_c PC,C;
    int v;
    string w,x,y,z;
    v = ID;
    w = nama;
    x = alamat;
    y = nohp;
    z = gender;
    PC = alokasi_c(v,w,x,y,z);
    if(first(LC) == NULL || info_c(first(LC)).ID > v){
        insertFirst_c(LC, PC);
    }
    else{
        C = first(LC);
        while(C != last(LC) && info_c(next(C)).ID < v){
            C = next(C);
        }
        insertAfter_c(LC,C,PC);
    }
};
void deleteID_c(List_c &LC, int x){
        address_c PC;
            if (first(LC) != NULL){
            PC = findElm_c(LC,x);
            if (info_c(PC).ID == x){
                address_c QC;
                QC = first(LC);
                if (next(QC) == NULL){
                    QC = first(LC);
                }
                else{
                while(next(QC) != PC){
                    QC = next(QC);
                }
                }
                deleteafter_c(LC,QC,PC);
                cout<<"Data telah dihapus\n";
            }
            else{
                cout<<"ID tidak ditemukan \n";
            }
            }
            else{
                cout<<"Data kosong \n";
            }
};
