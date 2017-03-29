#include "program.h"
#include "singlecircular.h"
#include "Childs.h"
#include "Relasi.h"
// Ibnu Hamdam , NIM : 1301164177
address_p P,Q;
int pil,a,q,angka,id,idc,p,chil,psi,pasien,nom,nim,ID1,ID2;
string b,t,w,x,y,c,d,e,u;
List_p LP;
List_c LC;
List_r LR;

void menu(){
    CreateList(LP);
    CreateList_c(LC);
    CreateList_r(LR);
    pil = 0;
    while(pil != 13){
    cout<<"1.) Masukan data Psioteraphy\n";
    cout<<"2.) Masukan data Pasien\n";
    cout<<"3.) Tampilkan data Psioteraphy\n";
    cout<<"4.) Koneksikan \n";
    cout<<"5.) Tampilkan data koneksi \n";
    cout<<"6.) Putuskan koneksi \n";
    cout<<"7.) Cari data koneksi \n";
    cout<<"8.) Tampilkan data pasien \n";
    cout<<"9.) Hapus data Psioteraphy \n";
    cout<<"10.)Hapus data pasien \n";
    cout<<"11.)Cari data Psioteraphy \n";
    cout<<"12.)Cari data Pasien \n";
    cout<<"13.) EXIT \n";
    cout<<"Masukan pilihan anda :  ";
    cin>>pil;
    switch(pil){
    case 1 : insertParents();
             break;
    case 2 : insertchilds();
             break;
    case 3 : viewparents();
             break;
    case 4 : connectrel();
             break;
    case 5 : viewconnected();
             break;
    case 6 : deleterelat();
             break;
    case 7 : findrel();
             break;
    case 8 : viewchilds();
             break;
    case 9 : deleteParents();
             break;
    case 10 : deletechilds();
             break;
    case 11 : FindParents();
             break;
    case 12 : findchilds();
             break;
    };
    getche();
    system("cls");
    }
};
void findrel(){
    address_r PR;
    string pil2;
    cout<<"Masukan ID psioteraphy : ";
    cin>>ID1;
    cout<<"Masukan ID pasien      : ";
    cin>>ID2;
    PR = findElm_r(LR,ID1,ID2);
    if (PR == NULL){
        cout<<"maaf list kosong \n";
    }
    else if (info_r(PR).ID == ID1 && info_r(PR).ID2 == ID2){
        cout<<"Data ditemukan ingin menampilkannya : (y/t) \n";
        cin>>pil2;
        if (pil2 == "y" || pil2 == "Y"){
            cout<<"----------"<<endl;
           cout<<"ID Psioteraphy  :"<<info_r(PR).ID<<endl;
            cout<<"Nama Psioteraphy:"<<info_r(PR).Nama<<endl;
            cout<<"      |     "<<endl;
            cout<<"      |     "<<endl;
            cout<<"      V     "<<endl;
            cout<<"ID Pasien       :"<<info_r(PR).ID2<<endl;
            cout<<"Nama Pasien     :"<<info_r(PR).Nama2<<endl;
        }
        else{

        }
    }
    else{
        if(info_r(PR).ID != ID1){
            cout<<"Maaf ID psioteraphy yang anda masukan tidak ada didalam list";
        }
        else{
            cout<<"Maaf, ID Pasien yang anda masukan tidak ada didalam list";
        }
    }
}
void deleterelat(){
    address_p PR;
    address_c CR;
    address_r R;
    cout<<"Masukan ID Psioteraphy yang ingin didelete : ";
    cin>>nom;
    cout<<"Masukan ID Pasien yang ingin didelete      : ";
    cin>>nim;
    PR = findElm(LP,nom);
    CR = findElm_c(LC,nim);
    R = first_r(LR);
    if(info(PR).ID == nom && info_c(CR).ID == nim){
    while(info_r(R).ID != nom || info_r(R).ID2 != nim){
        R = next_r(R);
    }
    deleteRel(LR, R);
    }
    else{
        cout<<"Data kosong";
    }
};
void deleteParents(){
             address_p P;
             address_r PR;
             address_r PQ;
             cout<<"Masukan ID Psioteraphy yang ingin didelete : ";
             cin>>angka;
              P = findElm(LP,angka);
              PR = first_r(LR);
              if (first_r(LR) != NULL){
              while (PR != last_r(LR)){
                    if(angka == info_r(PR).ID){
                deletefirst_r(LR,PR);
                PR = first_r(LR);
                   }
             }
             if (angka == info_r(PR).ID){
                deleteRel(LR,PR);
             }
              };
             deleteID(LP,angka);
    };
void findchilds(){
        address_c QC;
    cout<<"Masukan ID pasien yang ingin dicari : ";
    cin>>idc;
    QC = findElm_c(LC,idc);
    if(QC == NULL){
        cout<<"Maaf data pasien yang anda cari tidak ada \n";
    }
    else if(info_c(QC).ID != idc){
        cout<<"ID pasien yang anda cari tidak ditemukan \n";
    }
    else{
            cout<<"Data pasien yang anda cari tersedia dalam list \n";
        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";
        cin>>u;
        if (u == "Y" || u == "y"){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Nama     :"<<info_c(QC).nama<<endl;
                cout<<"Alamat   :"<<info_c(QC).alamat<<endl;
                cout<<"No HP    :"<<info_c(QC).nohp<<endl;
                cout<<"Gender   :"<<info_c(QC).gender<<endl;

        }
    }
};
void deletechilds(){
    address_c PC;
    cout<<"Masukan ID pasien yang ingin dihapus : ";
    cin>>chil;
    cout<<" --- \n";
    PC = findElm_c(LC,chil);
             address_r PR = first_r(LR);
              if (first_r(LR) != NULL){
              while (PR != last_r(LR)){
                    if(chil == info_r(PR).ID2){
                deletefirst_r(LR,PR);
                PR = first_r(LR);
                   }
             }
             if (chil == info_r(PR).ID2){
                deleteRel(LR,PR);
             }
              };
             deleteID_c(LC,chil);
};
void insertchilds(){
    address_c PC;
    address_c P;
    cout<<"Masukan ID Pasien : ";
             cin>>q;
             cout<<"Masukan nama Pasien : ";
             cin>>t;
             cout<<"Masukan alamat Pasien : ";
             cin>>w;
             cout<<"Masukan no hp Pasien : ";
             cin>>x;
             cout<<"Masukan Gender Pasien : ";
             cin>>y;
            PC = alokasi_c(q,t,w,x,y);
        if (first(LC) == NULL){
                insertAscending_c(LC,q,t,w,x,y);
             }
             else{
                PC = findElm_c(LC, q);
                    if (info_c(PC).ID != q){
             insertAscending_c(LC,q,t,w,x,y);
                    }
                    else{
            cout<<"ID duplicate\n";
                    }
             }
}
void insertParents(){
    address_p P;
        cout<<"Masukan ID Psioteraphy : ";
             cin>>a;
             cout<<"Masukan nama Psioteraphy : ";
             cin>>b;
             cout<<"Masukan alamat Psioteraphy : ";
             cin>>c;
             cout<<"Masukan no hp Psioteraphy: ";
             cin>>d;
             cout<<"Masukan Gender Psioteraphy: ";
             cin>>e;
             if (first(LP) == NULL){
                insertAscending(LP,a,b,c,d,e);
             }
             else{
                P = findElm(LP, a);
                    if (info(P).ID != a){
             insertAscending(LP, a,b,c,d,e);
                    }
                    else{
            cout<<"ID duplicate\n";
                    }
             }
    };
void viewparents(){
        printInfo(LP);
             cout<<endl;
    };
void viewchilds(){
     printInfo_c(LC);
             cout<<endl;
}

void connectrel(){
    address_p P;
    address_c C;
    address_r PR;
    cout<<"Masukan nomor ID psioteraphy : ";
    cin>>psi;
    cout<<"Masukan nomor ID pasien : ";
    cin>>pasien;
    P = findElm(LP,psi);
    C = findElm_c(LC,pasien);
    if (info(P).ID == psi && info_c(C).ID == pasien){
    PR = alokasi_r(P,C);
    insertLast(LR,PR);
    }
    else{
        if(info(P).ID != psi){
            cout<<"Maaf ID psioteraphy yang anda masukan salah";
        }
        else{}
        cout<<"Maaf ID Pasien yang anda masukan salah";
    }
};
void viewconnected(){
    printInfo_r(LR);
};
void FindParents(){
    address_p Q;
    cout<<"Masukan ID Psioteraphy yang ingin dicari : ";
    cin>>id;
    Q = findElm(LP,id);
    if(Q == NULL){
        cout<<"Maaf Data Psioteraphy yang anda cari tidak ada \n";
    }
    else if(info(Q).ID != id){
        cout<<"ID Psioteraphy yang anda cari tidak ditemukan \n";
    }
    else{
            cout<<"Psioteraphy yang anda cari tersedia dalam list \n";
        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";
        cin>>u;
        if (u == "Y" || u == "y"){
            address_p Q;
            Q = first(LP);
            if ((Q) == first(LP)){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info(Q).ID<<endl;
                cout<<"Nama     :"<<info(Q).nama<<endl;
                cout<<"Alamat   :"<<info(Q).alamat<<endl;
                cout<<"No HP    :"<<info(Q).nohp<<endl;
                cout<<"Gender   :"<<info(Q).gender<<endl;
            }
            else{
            while(next(Q) != first(LP)){
                    if (info(Q).ID == id){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info(Q).ID<<endl;
                cout<<"Nama     :"<<info(Q).nama<<endl;
                cout<<"Alamat   :"<<info(Q).alamat<<endl;
                cout<<"No HP    :"<<info(Q).nohp<<endl;
                cout<<"Gender   :"<<info(Q).gender<<endl;
                    }
                    Q = next(Q);
            }
            if (info(Q).ID == id){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info(Q).ID<<endl;
                cout<<"Nama     :"<<info(Q).nama<<endl;
                cout<<"Alamat   :"<<info(Q).alamat<<endl;
                cout<<"No HP    :"<<info(Q).nohp<<endl;
                cout<<"Gender   :"<<info(Q).gender<<endl;
                    }
            }
        }
    }

};
