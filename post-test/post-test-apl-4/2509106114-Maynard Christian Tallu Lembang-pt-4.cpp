#include <iostream>
#include <string>
using namespace std;

// ================= STRUCT =================
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

// ================= LOGIN =================
void login(User *user, int *kesempatan){

    string username, password;

    while(*kesempatan > 0){
        cout<<"\n=== LOGIN ===\n";
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;

        if(username == user->nama && password == user->nim){
            cout<<"Login berhasil!\n";
            return;
        }
        else{
            cout<<"Login gagal!\n";
            cout<<"Kesempatan tersisa : "<<*kesempatan<<" kali\n"; // tampil dulu
            (*kesempatan)--; // baru dikurangi

            if(*kesempatan == 0){
                cout<<"Kesempatan habis!\n";
            }
        }
    }
}

// ================= TAMBAH DATA =================
void tambahData(CuciMotor *pelanggan, int *jumlah){

    cin.ignore();

    cout<<"Nama Pelanggan : ";
    getline(cin, pelanggan[*jumlah].nama);

    cout<<"Plat Motor : ";
    getline(cin, pelanggan[*jumlah].plat);

    int paket;

    cout<<"1. Cuci Biasa\n";
    cout<<"2. Cuci + Semir Ban\n";
    cout<<"3. Cuci + Wax\n";
    cout<<"4. Cuci + Mesin\n";
    cout<<"5. Cuci Lengkap\n";
    cout<<"Pilih paket : ";
    cin>>paket;

    if(paket==1){
        pelanggan[*jumlah].paket="Cuci Biasa";
        pelanggan[*jumlah].harga=20000;
    }
    else if(paket==2){
        pelanggan[*jumlah].paket="Cuci + Semir Ban";
        pelanggan[*jumlah].harga=25000;
    }
    else if(paket==3){
        pelanggan[*jumlah].paket="Cuci + Wax";
        pelanggan[*jumlah].harga=35000;
    }
    else if(paket==4){
        pelanggan[*jumlah].paket="Cuci + Mesin";
        pelanggan[*jumlah].harga=40000;
    }
    else if(paket==5){
        pelanggan[*jumlah].paket="Cuci Lengkap";
        pelanggan[*jumlah].harga=55000;
    }
    else{
        cout<<"Paket tidak valid!\n";
        return;
    }

    // 🔥 tampilkan harga
    cout<<"Harga : "<<pelanggan[*jumlah].harga<<endl;

    (*jumlah)++;
}

// ================= LIHAT DATA =================
void lihatData(CuciMotor *pelanggan, int jumlah){

    if(jumlah == 0){
        cout<<"Data kosong!\n";
        return;
    }

    CuciMotor *ptr = pelanggan;

    for(int i=0;i<jumlah;i++){
        cout<<"\nData ke-"<<i+1<<endl;
        cout<<"Nama  : "<<ptr->nama<<endl;
        cout<<"Plat  : "<<ptr->plat<<endl;
        cout<<"Paket : "<<ptr->paket<<endl;
        cout<<"Harga : "<<ptr->harga<<endl;
        ptr++;
    }
}

// ================= UBAH DATA =================
void ubahData(CuciMotor *pelanggan, int jumlah){

    if(jumlah == 0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;
    cout<<"Pilih data yang diubah : ";
    cin>>nomor;

    if(nomor < 1 || nomor > jumlah){
        cout<<"Data tidak valid!\n";
        return;
    }

    cin.ignore();

    cout<<"Nama Baru : ";
    getline(cin, pelanggan[nomor-1].nama);

    cout<<"Plat Baru : ";
    getline(cin, pelanggan[nomor-1].plat);

    int paket;

    cout<<"1. Cuci Biasa\n";
    cout<<"2. Cuci + Semir Ban\n";
    cout<<"3. Cuci + Wax\n";
    cout<<"4. Cuci + Mesin\n";
    cout<<"5. Cuci Lengkap\n";
    cout<<"Pilih paket : ";
    cin>>paket;

    if(paket==1){
        pelanggan[nomor-1].paket="Cuci Biasa";
        pelanggan[nomor-1].harga=20000;
    }
    else if(paket==2){
        pelanggan[nomor-1].paket="Cuci + Semir Ban";
        pelanggan[nomor-1].harga=25000;
    }
    else if(paket==3){
        pelanggan[nomor-1].paket="Cuci + Wax";
        pelanggan[nomor-1].harga=35000;
    }
    else if(paket==4){
        pelanggan[nomor-1].paket="Cuci + Mesin";
        pelanggan[nomor-1].harga=40000;
    }
    else if(paket==5){
        pelanggan[nomor-1].paket="Cuci Lengkap";
        pelanggan[nomor-1].harga=55000;
    }
    else{
        cout<<"Paket tidak valid!\n";
    }
}

// ================= HAPUS DATA =================
void hapusData(CuciMotor *pelanggan, int *jumlah){

    if(*jumlah == 0){
        cout<<"Data kosong!\n";
        return;
    }

    int nomor;
    cout<<"Nomor yang dihapus : ";
    cin>>nomor;

    if(nomor < 1 || nomor > *jumlah){
        cout<<"Data tidak valid!\n";
        return;
    }

    for(int i=nomor-1;i<(*jumlah)-1;i++){
        pelanggan[i]=pelanggan[i+1];
    }

    (*jumlah)--;
}

// ================= TOTAL =================
int hitungTotal(CuciMotor *pelanggan, int jumlah){
    int total = 0;

    CuciMotor *ptr = pelanggan;

    for(int i=0;i<jumlah;i++){
        total += ptr->harga;
        ptr++;
    }

    return total;
}

// ================= MAIN =================
int main(){

    User user = {"maynard","114"};
    CuciMotor pelanggan[100];
    int jumlah = 0;

    int kesempatan = 3;

    login(&user, &kesempatan);

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
        cout<<"5. Total Pendapatan\n";
        cout<<"6. Keluar\n";
        cout<<"Pilihan : ";
        cin>>menu;

        if(menu == 1){
            tambahData(pelanggan, &jumlah);
        }
        else if(menu == 2){
            lihatData(pelanggan, jumlah);
        }
        else if(menu == 3){
            ubahData(pelanggan, jumlah);
        }
        else if(menu == 4){
            hapusData(pelanggan, &jumlah);
        }
        else if(menu == 5){
            cout<<"Total Pendapatan : "<< hitungTotal(pelanggan, jumlah) << endl;
        }

    }while(menu != 6);

    return 0;
}