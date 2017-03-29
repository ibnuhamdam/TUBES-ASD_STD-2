#include "Relasi.h"

using namespace std;

void CreateList_r(List_r &LR){
    // Ibnu Hamdam , NIM : 1301164177
    first_r(LR) = NULL;
    last_r(LR)  = NULL;
};
void deletefirst_r(List_r &LR,address_r PR){
    // Ibnu Hamdam , NIM : 1301164177
    PR = first_r(LR);
    if (first_r(LR) == NULL){
        cout<<"Data kosong \n";
    }
    else if(PR == last_r(LR)){
        first_r(LR) = NULL;
        last_r(LR) = NULL;
        dealokasi(PR);
    }
    else{
        prev_r(next_r(PR)) = NULL;
        first_r(LR) = next_r(PR);
        next_r(PR) = NULL;
        dealokasi(PR);
    }
}
void deleteRel(List_r &LR, address_r PR){
    // Ibnu Hamdam , NIM : 1301164177
    if (first_r(LR) == NULL){
        cout<<"Data kosong";
    }
    else if(first_r(LR) = last_r(LR)){
        deletefirst_r(LR,PR);
    }
    else{
        address_r QR;
        QR = prev_r(PR);
        next_r(QR) = next_r(PR);
        prev_r(next_r(PR)) = QR;
        next_r(PR) = NULL;
        prev_r(PR) = NULL;
        dealokasi(PR);
    }
};
address_r alokasi_r(address_p P, address_c C){
    // Ibnu Hamdam , NIM : 1301164177
    address_r PR;
    PR = new elmlist_r;
    info_r(PR).ID = info(P).ID;
    info_r(PR).Nama = info(P).nama;
    info_r(PR).ID2 = info_c(C).ID;
    info_r(PR).Nama2 = info_c(C).nama;
    next_r(PR) = NULL;
    prev_r(PR) = NULL;

};
void dealokasi(address_r &PR){
    // Ibnu Hamdam , NIM : 1301164177
    delete PR;
};
void insertLast(List_r &LR, address_r PR){
    // Ibnu Hamdam , NIM : 1301164177
    if (first_r(LR) == NULL){
        first_r(LR) = PR;
        last_r(LR) = PR;
    }
    else{
    address_r R = first_r(LR);
    while(R != last_r(LR)){
        R = next_r(R);
    }
    next_r(R) = PR;
    prev_r(PR) = R;
    last_r(LR) = PR;
    }
};
address_r findElm_r(List_r LR, int ID, int ID2){
    // Ibnu Hamdam , NIM : 1301164177
    address_r PR = first_r(LR);
    if (first_r(LR) == NULL){
        PR = NULL;
    }
    else{
        while (info_r(PR).ID != ID && info_r(PR).ID2 != ID2 && next_r(PR) != last_r(LR)){
            PR = next_r(PR);
        }

    }
    return PR;
};
void printInfo_r(List_r LR){
    // Ibnu Hamdam , NIM : 1301164177
    int i;
    i = 1;
    if (first_r(LR) == NULL){
        cout<<"data kosong \n";
    }
    else{
    address_r PR;
    PR = first_r(LR);
    while(PR != last_r(LR)){
        cout<<"List Relasi ke-"<<i<<"\n";
        cout<<"----------"<<endl;
            cout<<"ID Psioteraphy  :"<<info_r(PR).ID;
            cout<<"  -  ";
            cout<<"ID Pasien       :"<<info_r(PR).ID2<<endl;
        PR = next_r(PR);
        i = i+1;
    }cout<<"List Relasi ke-"<<i<<endl;
    cout<<"----------"<<endl;
            cout<<"ID Psioteraphy  :"<<info_r(PR).ID;
            cout<<"  -  ";
            cout<<"ID Pasien       :"<<info_r(PR).ID2<<endl;
    }
};
void insertfirst(List_r &LR, address_r PR){
    // Ibnu Hamdam , NIM : 1301164177
    if (first_r(LR) == NULL){
        first_r(LR) = PR;
        last_r(LR) = PR;
    }
    else{
        next_r(PR) = first_r(LR);
        prev_r(first_r(LR)) = PR;
        first_r(LR) = PR;
    }
};
