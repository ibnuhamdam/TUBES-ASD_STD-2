#ifndef SINGLECIRCULAR_H_INCLUDED
#define SINGLECIRCULAR_H_INCLUDED
#include <iostream>

#define Nil NULL
#define next(P) (P)->next
#define first(L) (L).first
#define info(P) (P)->info
using namespace std;

typedef struct elmlist_p *address_p;
typedef struct infotype{
    int ID;
    string nama;
    string alamat;
    string nohp;
    string gender;
};
struct x{
    int ID;
    string nama;
    string alamat;
    string nohp;
    string gender;
};
struct elmlist_p{
    infotype info;
    address_p next;
};
struct List_p{
    address_p first;
};

void CreateList(List_p &LP);
void deleteID(List_p &LP, int x);
address_p alokasi(int ID, string nama, string alamat, string nohp, string gender);
void dealokasi(address_p &P);
void insertFirst(List_p &LP, address_p P);
void insertAfter(List_p &LP, int Prec, address_p P);
void insertLast(List_p &LP, address_p P);
address_p findElm(List_p LP, int x);
void deleteFirst(List_p &LP, address_p &P);
void deleteLast(List_p &LP, address_p &P);
void deleteAfter(List_p &LP, address_p &Prec, address_p &P);
void printInfo(List_p LP);
address_p findMinimum(List_p LP);
void insertAscending(List_p &LP, int ID, string nama,string alamat, string nohp, string gender);

#endif // SINGLECIRCULAR_H_INCLUDED
