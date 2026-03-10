#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string nama, password;
    string namaBenar = "Maynard";
    string passBenar = "114";   // 3 digit terakhir NIM
    int kesempatan = 3;

    // ================= LOGIN =================
    while (kesempatan > 0) {
        cout << "====================================" << endl;
        cout << "            LOGIN PROGRAM           " << endl;
        cout << "====================================" << endl;
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == namaBenar && password == passBenar) {
            cout << endl;
            cout << "Login Berhasil! Selamat datang, " << nama << endl;
            break;
          } 
            else {
            kesempatan--;
            cout << endl;
            cout << "Login gagal! Sisa kesempatan: " << kesempatan << endl;
            cout << "------------------------------------" << endl;
        }
    }

    if (kesempatan == 0) {
        cout << endl;
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    // ================= MENU =================
    int pilihan;
    double nilai;

    do {
        cout << endl;
        cout << "====================================" << endl;
        cout << "        MENU KONVERSI PANJANG       " << endl;
        cout << "====================================" << endl;
        cout << "1. Meter -> Kilometer & Centimeter" << endl;
        cout << "2. Kilometer -> Meter & Centimeter" << endl;
        cout << "3. Centimeter -> Meter & Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "------------------------------------" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << endl;
                cout << "Masukkan nilai dalam Meter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:" << endl;
                cout << nilai / 1000 << " km" << endl;
                cout << nilai * 100 << " cm" << endl;
                break;

            case 2:
                cout << endl;
                cout << "Masukkan nilai dalam Kilometer: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:" << endl;
                cout << nilai * 1000 << " m" << endl;
                cout << nilai * 100000 << " cm" << endl;
                break;

            case 3:
                cout << endl;
                cout << "Masukkan nilai dalam Centimeter: ";
                cin >> nilai;
                cout << fixed << setprecision(2);
                cout << "Hasil:" << endl;
                cout << nilai / 100 << " m" << endl;
                cout << nilai / 100000 << " km" << endl;
                break;

            case 4:
                cout << endl;
                cout << "Terima kasih telah menggunakan program" << endl;
                break;

            default:
                cout << endl;
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}