#include <iostream>
#include <string>
using namespace std;

struct User{
    string nama;
    string nim;
};

struct CuciMotor{
    string nama;
    string plat;
    string paket;
    int harga;
};

int main(){

    User user = {"maynard","114"};

    CuciMotor pelanggan[100];
    int jumlah = 0;

    string username,password;
    int kesempatan = 3;

    while(kesempatan > 0){

        cout<<"=== LOGIN ===\n";
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;

        if(username == user.nama && password == user.nim){
            cout<<"Login berhasil\n";
            break;
        }
        else{
            kesempatan--;
            cout<<"Login gagal\n";
        }
    }

    if(kesempatan == 0){
        cout<<"Program berhenti\n";
        return 0;
    }

    int menu;

    do{

        cout<<"\n=== MENU CUCI MOTOR ===\n";
        cout<<"1. Tambah Data\n";
        cout<<"2. Lihat Data\n";
        cout<<"3. Ubah Data\n";
        cout<<"4. Hapus Data\n";
        cout<<"5. Keluar\n";
        cout<<"Pilihan : ";
        cin>>menu;

        if(menu == 1){

            cin.ignore();

            cout<<"Nama Pelanggan : ";
            getline(cin,pelanggan[jumlah].nama);

            cout<<"Plat Motor : ";
            getline(cin,pelanggan[jumlah].plat);

            int paket;

            cout<<"1. Cuci Biasa\n";
            cout<<"2. Cuci + Semir Ban\n";
            cout<<"3. Cuci + Wax\n";
            cout<<"4. Cuci + Mesin\n";
            cout<<"5. Cuci Lengkap\n";
            cout<<"Pilih paket : ";
            cin>>paket;

            if(paket==1){
                pelanggan[jumlah].paket="Cuci Biasa";
                pelanggan[jumlah].harga=20000;
            }
            else if(paket==2){
                pelanggan[jumlah].paket="Cuci + Semir Ban";
                pelanggan[jumlah].harga=25000;
            }
            else if(paket==3){
                pelanggan[jumlah].paket="Cuci + Wax";
                pelanggan[jumlah].harga=35000;
            }
            else if(paket==4){
                pelanggan[jumlah].paket="Cuci + Mesin";
                pelanggan[jumlah].harga=40000;
            }
            else if(paket==5){
                pelanggan[jumlah].paket="Cuci Lengkap";
                pelanggan[jumlah].harga=55000;
            }

            jumlah++;
        }

        else if(menu == 2){

            for(int i=0;i<jumlah;i++){

                cout<<"\nData ke-"<<i+1<<endl;
                cout<<"Nama : "<<pelanggan[i].nama<<endl;
                cout<<"Plat : "<<pelanggan[i].plat<<endl;
                cout<<"Paket : "<<pelanggan[i].paket<<endl;
                cout<<"Harga : "<<pelanggan[i].harga<<endl;
            }
        }

        else if(menu == 3){

            int nomor;

            cout<<"Pilih data yang diubah : ";
            cin>>nomor;

            cin.ignore();

            cout<<"Nama Baru : ";
            getline(cin,pelanggan[nomor-1].nama);

            cout<<"Plat Baru : ";
            getline(cin,pelanggan[nomor-1].plat);
        }

        else if(menu == 4){

            int nomor;

            cout<<"Nomor yang dihapus : ";
            cin>>nomor;

            for(int i=nomor-1;i<jumlah-1;i++){
                pelanggan[i]=pelanggan[i+1];
            }

            jumlah--;
        }

    }while(menu != 5);

}