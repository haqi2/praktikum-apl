#include <iostream>
using namespace std;

const int MAX_AKUN = 100;
const int MAX_USER = 100;

struct Akun {
    string id;
    double harga;
};

struct User {
    string username;
    string password;
};

Akun daftarAkun[MAX_AKUN] = {
    {"Reki", 150},
    {"Lyev", 200},
    {"Alex Killer Pro", 250}
};

User daftarUser[MAX_USER];
int jumlahAkun = 3;
int jumlahUser = 0;

void cetakAkun(Akun* akun) { 
    cout << "ID Akun: " << akun->id << ", Harga Sewa: " << akun->harga << endl;
}

void tampilkanSemuaAkun(int index = 0) {
    if (index >= jumlahAkun) return;
    cout << index + 1 << ". ";
    cetakAkun(&daftarAkun[index]); 
    tampilkanSemuaAkun(index + 1);
}

void tambahAkun() {
    if (jumlahAkun < MAX_AKUN) {
        Akun* newAkun = &daftarAkun[jumlahAkun]; 
        cout << "Masukkan ID Akun: ";
        cin.ignore();
        getline(cin, newAkun->id); 
        cout << "Masukkan Harga Sewa: ";
        cin >> newAkun->harga;
        jumlahAkun++;
        cout << "Akun berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas akun penuh!\n";
    }
}

void updateAkun() {
    int index;
    tampilkanSemuaAkun();
    cout << "Masukkan nomor akun yang ingin diupdate: ";
    cin >> index;
    if (index > 0 && index <= jumlahAkun) {
        Akun* akunToUpdate = &daftarAkun[index - 1];
        cout << "Masukkan ID baru: ";
        cin.ignore();
        getline(cin, akunToUpdate->id);
        cout << "Masukkan Harga Sewa baru: ";
        cin >> akunToUpdate->harga;
        cout << "Akun berhasil diperbarui!\n";
    } else {
        cout << "Nomor akun tidak valid!\n";
    }
}

void hapusAkun() {
    int index;
    tampilkanSemuaAkun();
    cout << "Masukkan nomor akun yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= jumlahAkun) {
        for (int i = index - 1; i < jumlahAkun - 1; i++) {
            daftarAkun[i] = daftarAkun[i + 1];
        }
        jumlahAkun--;
        cout << "Akun berhasil dihapus!\n";
    } else {
        cout << "Nomor akun tidak valid!\n";
    }
}

void sewaAkun() {
    int index;
    tampilkanSemuaAkun();
    cout << "Masukkan nomor akun yang ingin disewa: ";
    cin >> index;
    if (index > 0 && index <= jumlahAkun) {
        Akun* akunToSewa = &daftarAkun[index - 1];  
        cout << "Anda telah menyewa akun " << akunToSewa->id << " dengan harga " << akunToSewa->harga << "\n";
    } else {
        cout << "Nomor akun tidak valid!\n";
    }
}

bool login(string username, string password, bool& isAdmin) {
    if (username == "Haci" && password == "081") {
        isAdmin = true;
        return true;
    }
    for (int i = 0; i < jumlahUser; i++) {
        User* user = &daftarUser[i]; 
        if (user->username == username && user->password == password) {
            isAdmin = false;
            return true;
        }
    }
    return false;
}

int main() {
    int pilihan;
    string username, password;
    bool isAdmin;
    int percobaanLogin = 0;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1) {
            if (jumlahUser < MAX_USER) {
                User* newUser = &daftarUser[jumlahUser];        
                cout << "Masukkan Username: ";
                cin >> newUser->username;
                cout << "Masukkan Password: ";
                cin >> newUser->password;
                jumlahUser++;
                cout << "Registrasi berhasil!\n";
            } else {
                cout << "Pendaftaran user penuh!\n";
            }
        } else if (pilihan == 2) {
            while (percobaanLogin < 3) {
                cout << "\n========== LOGIN ==========\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (login(username, password, isAdmin)) {
                    cout << "\nSelamat datang, " << username << endl;
                    if (isAdmin) cout << "(Aturlah bang, abangkan admin)\n";
                    int menuPilihan;
                    do {
                        cout << "\n===== MENU " << (isAdmin ? "ADMIN" : "USER") << " =====\n";
                        if (isAdmin) {
                            cout << "1. Tambah Akun\n";
                            cout << "2. Lihat Akun\n";
                            cout << "3. Update Akun\n";
                            cout << "4. Hapus Akun\n";
                            cout << "5. Logout\n";
                        } else {
                            cout << "1. Sewa Akun\n";
                            cout << "2. Lihat Akun\n";
                            cout << "3. Logout\n";
                        }
                        cout << "Pilihan: ";
                        cin >> menuPilihan;
                        if (isAdmin) {
                            switch (menuPilihan) {
                                case 1: tambahAkun(); break;
                                case 2: tampilkanSemuaAkun(); break;
                                case 3: updateAkun(); break;
                                case 4: hapusAkun(); break;
                                case 5: break;
                                default: cout << "Pilihan tidak valid!\n";
                            }
                            if (menuPilihan == 5) break;
                        } else {
                            switch (menuPilihan) {
                                case 1: sewaAkun(); break;
                                case 2: tampilkanSemuaAkun(); break;
                                case 3: break;
                                default: cout << "Pilihan tidak valid!\n";
                            }
                            if (menuPilihan == 3) break;
                        }
                    } while (true);
                    break;
                } else {
                    cout << "Login gagal. Silakan coba lagi.\n";
                    percobaanLogin++;
                }
            }
            if (percobaanLogin == 3) {
                cout << "Gagal login 3 kali. Program dihentikan.\n";
                return 0;
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih. Program selesai.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (true);

    return 0;
}