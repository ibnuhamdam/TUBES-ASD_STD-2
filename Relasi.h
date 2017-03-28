#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "Childs.h"
#include "singlecircular.h"
#include "Relasi.h"

#define Nil NULL
#define next_r(P) (P)->next_r
#define prev_r(P) (P)->prev_r
#define first_r(L) (L).first_r
#define last_r(L) (L).last_r
#define info_r(P) (P)->info_r
using namespace std;

typedef struct elmlist_r *address_r;
typedef struct infotype_r{
    int ID;
    int ID2;
    string Nama;
    string Nama2;
};
struct elmlist_r{
    infotype_r info_r;
    address_r next_r;
    address_r prev_r;
    address_c child;
    address_p parent;
};
struct List_r{
    address_r first_r;
    address_r last_r;
};
void CreateList_r(List_r &LR);
void deletefirst_r(List_r &LR,address_r PR);
void insertfirst(List_r &LR, address_r PR);
void deleteRel(List_r &LR, address_r PR);
address_r alokasi_r(address_p PR, address_c CR);
void dealokasi(address_r &PR);
void insertLast(List_r &LR, address_r PR);
address_r findElm_r(List_r LR, int ID, int ID2);
void printInfo_r(List_r LR);

#endif // RELASI_H_INCLUDED
