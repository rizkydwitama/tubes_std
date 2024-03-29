#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

List_parent LP;
List_child LC;

int main()
{
    address_parent P;
    address_child C;
    matkul x;
    mahasiswa y;
    int pilihan;

    createList(LP);
    createList(LC);

    pilihan = selectMenu();
    while (pilihan != 0) {
        int i = 0;
        char jawab;
        int jmlMK,jmlMhs;
        switch(pilihan) {
        case 1: ///(DONE!!)
            cout << "Masukkan Jumlah Matkul: ";
            cin >> jmlMK;
            while (i < jmlMK) {
                cin.ignore();
                cout << "Masukkan Mata Kuliah: ";
                getline(cin, x.namaMK);
                cout << "Masukkan Nama Kelas: ";
                getline(cin, x.namaKls);
                cout << "Masukkan Kuota Maksimal: ";
                cin >> x.kuotaMaks;
                cout << "Masukkan Jenis Mahasiswa: ";
                cin >> x.jenisMhs;
                cout << endl;
                P = alokasi(x);
                insertLast(LP, P);
                i++;
            }
            break;

        case 2: ///(DONE!!)
            printInfo(LP);
            break;

        case 3: ///(DONE!!)
            cout << "Masukkan Jumlah Mahasiswa: ";
            cin >> jmlMhs;
            while(i < jmlMhs){
                cin.ignore();
                cout << "Masukkan Nama Mahasiswa: ";
                getline(cin, y.namaMhs);
                cout << "Masukkan NIM Mahasiswa: ";
                getline(cin, y.nimMhs);
                cout << "Masukkan Asal Kelas: ";
                getline(cin, y.asalKls);
                cout << "Masukkan Jenis Mahasiswa: ";
                cin >> y.jenisMhs;
                cout << endl;
                C = alokasi(y);
                insertLast(LC, C);
                i++;
            }
            break;

        case 4: ///(DONE!!)
            printInfo(LC);
            break;

        case 5: ///(DONE!!)
            cout<<"Masukkan Nama Matkul : ";
            cin.ignore();
            getline(cin, x.namaMK);
            findElm(LP, x);

            cout<<"Masukkan Nama Mahasiswa : ";
            getline(cin, y.namaMhs);
            findElm(LC, y);
            cout<<endl;

            if (x.jenisMhs == y.jenisMhs) {
                insertLast(child(P), alokasi(y));
                cout << "Mahasiswa Sudah Ditambahkan!" << endl;
            } else {
                cout << "Jenis Mahasiswa Harus Sama!" << endl;
            }
            break;

        case 6: ///(Masii eror xixixi)
            //printAjah(LP, LC);
            break;

        case 7:
            printInfo(LP);
            break;

        case 8:
            cout<<"Masukkan Nama Matkul : ";
            cin.ignore();
            getline(cin, x.namaMK);
            findElm(LP, x);
            deleteFirst(LP, P);
            printInfo(LP);
            break;
        case 9:
            cout<<"Masukkan Nama Mahasiswa : ";
            cin.ignore();
            getline(cin, y.namaMhs);
            findElm(LC, y);
            deleteFirst(LC, C);
            printInfo(LC);
            break;

        case 10:
            cout << "Masukkan Nama Matkul: ";
            cin.ignore();
            getline(cin, x.namaMK);
            findElm(LP, x);
            deleteFirstParent(LP, P);
            printInfo(LP);
            break;
        }

        cout << "Kembali ke menu utama ? (Y/N)" << endl;
        cin >> jawab;
        if(jawab == 'Y' || jawab == 'y'){
            pilihan = selectMenu();
        } else {
            cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
        }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    return 0;
}
