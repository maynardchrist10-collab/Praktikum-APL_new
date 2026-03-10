



// if (panjang = 0) {
//     cout < "Belum ada mahasiswa untuk diubah." < endl;
// } else {
//     for (int i = 0; i < panjang; i +) {
//         cout < "Mahasiswa ke-" < i + 1
//             < ": " < mahasiswa[i] < endl;

//     }   
//     cout < "Masukkan nomor mahasiswa yang akan diubah: ";
//     cin > index;
//     if (index > 0 & index = panjang) {
//         cout < "Masukkan nama baru: ";
//         cin.ignore();
//         getline(cin, mahasiswa[index - 1]);
//         cout < "Data berhasil diubah." < endl;
//     } else {
//         cout < "Nomor tidak valid." < endl;
//     }
// }


// #imclude <iostream>


#include <iostream>
using namespace std;

int main() {
    int nilai[2][2][2] = {
        { {80, 85}, {75, 90} }, // Kelas A
        { {88, 92}, {70, 78} }  // Kelas B
    };

    cout << " = DATA NILAI MAHASISWA =\n\n";

    for (int k = 0; k < 2; k++) {
        cout << "Kelas " << char('A' + k) << endl;

        for (int m = 0; m < 2; m++) {
            cout << " Mahasiswa " << m + 1 << endl;
            cout << " UTS : " << nilai[k][m][0] << endl;
            cout << " UAS : " << nilai[k][m][1] << endl;
        }
        cout << endl;
    }

    return 0;
}