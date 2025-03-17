#include <iostream>
using namespace std;

const int MAX_AKUN = 100;

string idakun[MAX_AKUN];

double hargasewa[MAX_AKUN];
int jumlahakun = 0;

string idakunawal[] = {"Reki", "Lyev", "Alex Killer Pro"};
double hargasewaawal[] = {150, 200, 250};
int jumlahakunAwal = sizeof(idakunawal) / sizeof(idakunawal[0]);

bool validInput(int input, int min, int max) {
    return input >= min && input <= max;
}

int TekanUntukLanjut() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
    return 1;
}

int TambahAkun(string id, double harga) {
    if (jumlahakun < MAX_AKUN) {
        idakun[jumlahakun] = id;
        hargasewa[jumlahakun] = harga;
        system("cls");
        jumlahakun++;
        cout << "Akun dengan ID " << id << " berhasil ditambahkan dengan harga sewa " << harga << "!" << endl;
        return 1; 
    } else {
        cout << "Penyimpanan akun penuh!" << endl;
        return 0; 
    }
}

int TampilkanAkun() {
    if (jumlahakun == 0) {
        cout << "Tidak ada akun yang tersedia." << endl;
        return 0; 
    } else {
        cout << "\n===============================" << endl;
        cout << "      Daftar Akun Tersedia      " << endl;
        cout << "===============================" << endl;
        for (int i = 0; i < jumlahakun; i++) {
            cout << i + 1 << ". ID Akun: " << idakun[i] << ", Harga Sewa: " << hargasewa[i] << endl;
        }
        cout << "===============================" << endl;
        return 1; 
    }
}

int UpdateAkun(string id, string newId, double harga) {
    bool found = false;
    for (int i = 0; i < jumlahakun; i++) {
        if (idakun[i] == id) {
            idakun[i] = newId;
            hargasewa[i] = harga;
            found = true;
            cout << "Akun dengan ID " << id << " berhasil diupdate menjadi ID " << newId << " dengan harga sewa baru " << harga << "!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "ID akun tidak ditemukan." << endl;
        return 0; 
    }
    return 1; 
}

int HapusAkun(string id) {
    bool found = false;
    for (int i = 0; i < jumlahakun; i++) {
        if (idakun[i] == id) {
            for (int j = i; j < jumlahakun - 1; j++) {
                idakun[j] = idakun[j + 1];
                hargasewa[j] = hargasewa[j + 1];
            }
            jumlahakun--;
            found = true;
            cout << "Akun dengan ID " << id << " berhasil dihapus!" << endl;
            return 1; 
        }
    }
    if (!found) {
        cout << "ID akun tidak ditemukan." << endl;
        return 0; 
    }
    return 0;
}

int main() {
    system("cls");
    string username, password;
    bool berhasillogin = false;
    int percobaan = 0; 

    for (int i = 0; i < jumlahakunAwal; i++) {
        idakun[i] = idakunawal[i];
        hargasewa[i] = hargasewaawal[i];
        jumlahakun++;
    }

    do {
        cout << "===============================" << endl;
        cout << "          LOGIN ADMIN          " << endl;
        cout << "===============================" << endl;
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);
        
        if (username == "Haci" && password == "081") {
            berhasillogin = true;
            system("cls");
            cout << "Login berhasil sebagai Admin!" << endl;
            TekanUntukLanjut();
        } else {
            percobaan++; 
            cout << "Login gagal! Coba lagi." << endl;
            TekanUntukLanjut();
            system("cls");
            if (percobaan >= 3) { 
                cout << "Anda telah gagal login 3 kali. Program berakhir." << endl;
                return 0; 
            }
        }
    } while (!berhasillogin);

    int pilihan;
    do {
        system("cls");
        cout << "\n===============================" << endl;
        cout << "          MENU ADMIN           " << endl;
        cout << "===============================" << endl;
        cout << "1. Masukkan Id Akun" << endl;
        cout << "2. Tampilkan Daftar Akun" << endl;
        cout << "3. Update Akun" << endl;
        cout << "4. Hapus Akun" << endl;
        cout << "5. LOGOUT" << endl;
        cout << "===============================" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();
        system("cls");

        if (pilihan == 1) {
            string id;
            double harga;
            cout << "Masukkan ID Akun: ";
            getline(cin, id);
            cout << "Masukkan Harga Sewa: ";
            cin >> harga;
            cin.ignore();
            TambahAkun(id, harga);
            TekanUntukLanjut();
        }
        else if (pilihan == 2) {
            TampilkanAkun();
            TekanUntukLanjut();
        }
        else if (pilihan == 3) {
            string id, newId;
            double harga;
            cout << "Masukkan ID Akun yang ingin diupdate: ";
            getline(cin, id);
            cout << "Masukkan ID Akun Baru: ";
            getline(cin, newId);
            cout << "Masukkan Harga Sewa Baru: ";
            cin >> harga;
            cin.ignore();
            UpdateAkun(id, newId, harga);
            TekanUntukLanjut();
        }
        else if (pilihan == 4) {
            string hapusID;
            cout << "Masukkan ID akun yang ingin dihapus: ";
            getline(cin, hapusID);
            HapusAkun(hapusID);
            TekanUntukLanjut();
        }
    } while (pilihan != 5);

    cout << "Terima kasih, logout berhasil." << endl;
    cin.get();
    return 0;
}
