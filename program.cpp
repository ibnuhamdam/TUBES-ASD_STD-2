#include "program.h"
#include "singlecircular.h"
#include "Childs.h"
#include "Relasi.h"

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
    cout<<"1.) Insert parents\n";
    cout<<"2.) Insert Childs\n";
    cout<<"3.) view Parents\n";
    cout<<"4.) Connecting relation\n";
    cout<<"5.) View Connected\n";
    cout<<"6.) Disconnect Relation\n";
    cout<<"7.) Find Relation \n";
    cout<<"8.) view Childs\n";
    cout<<"9.) delete parents\n";
    cout<<"10.) delete Childs\n";
    cout<<"11.) Find parents\n";
    cout<<"12.) Find Childs\n";
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
        cout<<"Maaf data tidak ditemukan ";
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
    while(info_r(R).ID != nom || info_r(R).ID2 != nim){
        R = next_r(R);
    }
    deleteRel(LR, R);
};
void findchilds(){
        address_c QC;
    cout<<"Masukan ID parent yang ingin dicari : ";
    cin>>idc;
    QC = findElm_c(LC,idc);
    if(QC == NULL){
        cout<<"Maaf child yang anda cari tidak ada \n";
    }
    else if(info_c(QC).ID != idc){
        cout<<"ID child yang anda cari tidak ditemukan \n";
    }
    else{
            cout<<"Parents yang anda cari tersedia dalam list \n";
        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";
        cin>>u;
        if (u == "Y" || u == "y"){
            address_c QC;
            QC = first(LC);
            if ((QC) == first(LC)){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Nama     :"<<info_c(QC).nama<<endl;
                cout<<"Alamat   :"<<info_c(QC).alamat<<endl;
                cout<<"No HP    :"<<info_c(QC).nohp<<endl;
                cout<<"Gender   :"<<info_c(QC).gender<<endl;
            }
            else{
            while(next(QC) != last(LC)){
                    if (info_c(QC).ID == idc){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Nama     :"<<info_c(QC).nama<<endl;
                cout<<"Alamat   :"<<info_c(QC).alamat<<endl;
                cout<<"No HP    :"<<info_c(QC).nohp<<endl;
                cout<<"Gender   :"<<info_c(QC).gender<<endl;
                    }
                    QC = next(QC);
            }
            if (info_c(QC).ID == idc){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Nama     :"<<info_c(QC).nama<<endl;
                cout<<"Alamat   :"<<info_c(QC).alamat<<endl;
                cout<<"No HP    :"<<info_c(QC).nohp<<endl;
                cout<<"Gender   :"<<info_c(QC).gender<<endl;
                    }
            }
        }
    }
};
void deletechilds(){
    address_c PC;
    cout<<"Masukan ID child yang ingin dihapus : ";
    cin>>chil;
    cout<<"okay\n";
    deleteID_c(LC,chil);
};
void insertchilds(){
    address_c PC;
    cout<<"Masukan ID Parent : ";
             cin>>q;
             cout<<"Masukan nama Parent : ";
             cin>>t;
             cout<<"Masukan alamat Parent : ";
             cin>>w;
             cout<<"Masukan no hp Parent : ";
             cin>>x;
             cout<<"Masukan Gender Parent : ";
             cin>>y;
            PC = alokasi_c(q,t,w,x,y);
        if (first(LC) == NULL){
                insertAscending_c(LC,q,t,w,x,y);
             }
             else{
                PC = findElm_c(LC, q);
                    if (info_c(PC).ID != q){
             insertAscending_c(LC, q,t,w,x,y);
                    }
                    else{
            cout<<"ID duplicate\n";
                    }
             }
}
void insertParents(){
    address_p P;
        cout<<"Masukan ID Parent : ";
             cin>>a;
             cout<<"Masukan nama Parent : ";
             cin>>b;
             cout<<"Masukan alamat Parent : ";
             cin>>c;
             cout<<"Masukan no hp Parent : ";
             cin>>d;
             cout<<"Masukan Gender Parent : ";
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
void deleteParents(){
             cout<<"Masukan ID parent yang ingin didelete : ";
             cin>>angka;
             deleteID(LP,angka);
    };
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
    PR = alokasi_r(P,C);
    insertfirst(LR,PR);
};
void viewconnected(){
    printInfo_r(LR);
};
void FindParents(){
    address_p Q;
    cout<<"Masukan ID parent yang ingin dicari : ";
    cin>>id;
    Q = findElm(LP,id);
    if(Q == NULL){
        cout<<"Maaf parents yang anda cari tidak ada \n";
    }
    else if(info(Q).ID != id){
        cout<<"ID parent yang anda cari tidak ditemukan \n";
    }
    else{
            cout<<"Parents yang anda cari tersedia dalam list \n";
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
