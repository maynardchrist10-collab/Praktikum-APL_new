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
        } else {
            cout<<"Login gagal!\n";
            (*kesempatan)--;
            cout<<"Sisa kesempatan : "<<*kesempatan<<endl;
        }
    }
}


void tambahData(CuciMotor *p, int *j){
    cin.ignore();

    cout<<"Nama : "; getline(cin, p[*j].nama);
    cout<<"Plat : "; getline(cin, p[*j].plat);

    int paket;
    cout<<"1. Biasa\n2. Semir\n3. Wax\n4. Mesin\n5. Lengkap\n";
    cout<<"Pilih : "; cin>>paket;

    if(paket==1){ p[*j].paket="Biasa"; p[*j].harga=20000; }
    else if(paket==2){ p[*j].paket="Semir"; p[*j].harga=25000; }
    else if(paket==3){ p[*j].paket="Wax"; p[*j].harga=35000; }
    else if(paket==4){ p[*j].paket="Mesin"; p[*j].harga=40000; }
    else if(paket==5){ p[*j].paket="Lengkap"; p[*j].harga=55000; }
    else{
        cout<<"Paket tidak valid!\n";
        return;
    }

    (*j)++;
}


void lihatData(CuciMotor *p, int j){
    if(j==0){
        cout<<"Data kosong!\n";
        return;
    }

    for(int i=0;i<j;i++){
        cout<<"\nData ke-"<<i+1<<endl;
        cout<<"Nama  : "<<p[i].nama<<endl;
        cout<<"Plat  : "<<p[i].plat<<endl;
        cout<<"Paket : "<<p[i].paket<<endl;
        cout<<"Harga : "<<p[i].harga<<endl;
    }
}


void ubahData(CuciMotor *p, int j){
    if(j==0){
        cout<<"Data kosong!\n";
        return;
    }

    int no;
    cout<<"Pilih data : ";
    cin>>no;

    if(no<1 || no>j){
        cout<<"Tidak valid!\n";
        return;
    }

    cin.ignore();

    cout<<"Nama baru : "; getline(cin, p[no-1].nama);
    cout<<"Plat baru : "; getline(cin, p[no-1].plat);

    int paket;
    cout<<"1. Biasa\n2. Semir\n3. Wax\n4. Mesin\n5. Lengkap\n";
    cout<<"Pilih : "; cin>>paket;

    if(paket==1){ p[no-1].paket="Biasa"; p[no-1].harga=20000; }
    else if(paket==2){ p[no-1].paket="Semir"; p[no-1].harga=25000; }
    else if(paket==3){ p[no-1].paket="Wax"; p[no-1].harga=35000; }
    else if(paket==4){ p[no-1].paket="Mesin"; p[no-1].harga=40000; }
    else if(paket==5){ p[no-1].paket="Lengkap"; p[no-1].harga=55000; }
}


void hapusData(CuciMotor *p, int *j){
    if(*j==0){
        cout<<"Data kosong!\n";
        return;
    }

    int no;
    cout<<"Hapus nomor : ";
    cin>>no;

    if(no<1 || no>*j){
        cout<<"Tidak valid!\n";
        return;
    }

    for(int i=no-1;i<*j-1;i++){
        p[i]=p[i+1];
    }

    (*j)--;
}


int total(CuciMotor *p, int j){
    int t=0;
    for(int i=0;i<j;i++){
        t+=p[i].harga;
    }
    return t;
}


void sortNamaDesc(CuciMotor *p, int j){
    for(int i=0;i<j-1;i++){
        for(int k=0;k<j-i-1;k++){
            if(p[k].nama < p[k+1].nama){
                swap(p[k], p[k+1]);
            }
        }
    }
}

void sortHargaAsc(CuciMotor *p, int j){
    for(int i=0;i<j-1;i++){
        for(int k=0;k<j-i-1;k++){
            if(p[k].harga > p[k+1].harga){
                swap(p[k], p[k+1]);
            }
        }
    }
}


void cariNama(CuciMotor *p, int j, string target){
    bool ketemu=false;

    for(int i=0;i<j;i++){
        if(p[i].nama == target){
            cout<<"\nData ditemukan!\n";
            cout<<"Nama  : "<<p[i].nama<<endl;
            cout<<"Plat  : "<<p[i].plat<<endl;
            cout<<"Paket : "<<p[i].paket<<endl;
            cout<<"Harga : "<<p[i].harga<<endl;
            ketemu=true;
        }
    }

    if(!ketemu) cout<<"Tidak ditemukan\n";
}


int binaryHarga(CuciMotor *p, int j, int target){
    int low=0, high=j-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(p[mid].harga==target) return mid;
        else if(p[mid].harga<target) low=mid+1;
        else high=mid-1;
    }

    return -1;
}


int main(){

    User user={"maynard","114"};
    CuciMotor pelanggan[100];
    int jumlah=0, kesempatan=3;

    login(&user,&kesempatan);
    if(kesempatan==0) return 0;

    int menu;

    do{
        cout<<"\n=== MENU CUCI MOTOR ===\n";
        cout<<"1. Tambah Data\n";
        cout<<"2. Lihat Data\n";
        cout<<"3. Ubah Data\n";
        cout<<"4. Hapus Data\n";
        cout<<"5. Total Pendapatan\n";
        cout<<"6. Sorting Nama (Desc)\n";
        cout<<"7. Sorting Harga (Asc)\n";
        cout<<"8. Cari Nama (Linear)\n";
        cout<<"9. Cari Harga (Binary)\n";
        cout<<"10. Keluar\n";
        cout<<"Pilih : ";
        cin>>menu;

        if(menu==1) tambahData(pelanggan,&jumlah);
        else if(menu==2) lihatData(pelanggan,jumlah);
        else if(menu==3) ubahData(pelanggan,jumlah);
        else if(menu==4) hapusData(pelanggan,&jumlah);
        else if(menu==5) cout<<"Total : "<<total(pelanggan,jumlah)<<endl;
        else if(menu==6) sortNamaDesc(pelanggan,jumlah);
        else if(menu==7) sortHargaAsc(pelanggan,jumlah);

        else if(menu==8){
            cin.ignore();
            string x;
            cout<<"Cari nama : ";
            getline(cin,x);
            cariNama(pelanggan,jumlah,x);
        }

        else if(menu==9){
            int x;
            cout<<"Cari harga : ";
            cin>>x;

            sortHargaAsc(pelanggan,jumlah); // wajib
            int idx = binaryHarga(pelanggan,jumlah,x);

            if(idx!=-1){
                cout<<"\nData ditemukan!\n";
                cout<<"Nama  : "<<pelanggan[idx].nama<<endl;
                cout<<"Plat  : "<<pelanggan[idx].plat<<endl;
                cout<<"Paket : "<<pelanggan[idx].paket<<endl;
                cout<<"Harga : "<<pelanggan[idx].harga<<endl;
            } else {
                cout<<"Tidak ditemukan\n";
            }
        }

    }while(menu!=10);

    return 0;
}