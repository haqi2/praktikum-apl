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

int main() {
    int pilihan;
    string username, password;
    int percobaanLogin = 0;
    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1) {
            if (jumlahUser < MAX_USER) {
                cout << "Masukkan Username: ";
                cin >> daftarUser[jumlahUser].username;
                cout << "Masukkan Password: ";
                cin >> daftarUser[jumlahUser].password;
                jumlahUser++;
                cout << "Registrasi berhasil! Silakan login.\n";
            } else {
                cout << "Pendaftaran user penuh!\n";
            }
        } else if (pilihan == 2) {
            percobaanLogin = 0;
            while (percobaanLogin < 3) {
                cout << "========== LOGIN ==========" << endl;
                cout << "Masukkan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
            
                bool Admin = (username == "Haci" && password == "081");
                bool found = false;
            
                if (Admin) {
                    found = true;
                } else { 
                    for (int i = 0; i < jumlahUser; i++) {
                        if (daftarUser[i].username == username && daftarUser[i].password == password) {
                            found = true;
                            break;
                        }
                    }
                }
                
                if (found) {
                    cout << "Halo, Selamat datang di lapak peminjaman akun" << endl;
                    if (Admin) {
                        cout << "Awas Ada ATMINN!" << endl;
                    }
                    
                    while (true) {
                        int Pilihan;
                        cout << "===== MENU " << (Admin ? "ADMIN" : "USER") << " =====" << endl;
                        if (Admin) {
                            cout << "1. Tambah Akun" << endl;
                            cout << "2. Lihat Akun" << endl;
                            cout << "3. Update Akun" << endl;
                            cout << "4. Hapus Akun" << endl;
                        } 
                        else {
                            cout << "1. Sewa Akun" << endl;
                            cout << "2. Lihat Akun" << endl;
                        }
                        cout << "5. Logout" << endl;
                        cout << "Pilihan: ";
                        cin >> Pilihan;
                        if (Admin && Pilihan == 1) {
                            if (jumlahAkun < MAX_AKUN) {
                                cout << "Masukkan ID Akun: ";
                                cin >> daftarAkun[jumlahAkun].id;
                                cout << "Masukkan Harga Sewa: ";
                                cin >> daftarAkun[jumlahAkun].harga;
                                jumlahAkun++;
                                cout << "Akun berhasil ditambahkan!\n";
                            }
                        } else if (Pilihan == 2) {
                            cout << "Daftar Akun:\n";
                            for (int i = 0; i < jumlahAkun; i++) {
                                cout << i + 1 << ". ID: " << daftarAkun[i].id 
                                << ", Harga Sewa: " << daftarAkun[i].harga << endl;
                            }
                        } else if (!Admin && Pilihan == 1) {
                            int index;
                            cout << "Masukkan nomor akun yang ingin disewa: ";
                            cin >> index;
                            if (index > 0 && index <= jumlahAkun) {
                                cout << "Anda telah menyewa akun " << daftarAkun[index - 1].id 
                                << " dengan harga " << daftarAkun[index - 1].harga << "\n";
                            } else {
                                cout << "Nomor akun tidak valid!\n";
                            }
                        } else if (Admin && Pilihan == 3) {
                            int index;
                            cout << "Masukkan nomor akun yang ingin diupdate: ";
                            cin >> index;
                            if (index > 0 && index <= jumlahAkun) {
                                cout << "Masukkan ID baru: ";
                                cin >> daftarAkun[index - 1].id;
                                cout << "Masukkan Harga Sewa baru: ";
                                cin >> daftarAkun[index - 1].harga;
                                cout << "Akun berhasil diperbarui!\n";
                            } else {
                                cout << "Nomor akun tidak valid!\n";
                            }
                        } else if (Admin && Pilihan == 4) {
                            int index;
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
                        } else if (Pilihan == 5) {
                            break;
                        }
                    }
                    break;
                } else {
                    cout << "Login Gagal! Akun Tidak Ditemukan!, Jangan Nguawur.\n";
                    percobaanLogin++;
                }
            }
            if (percobaanLogin == 3) {
                cout << "Login gagal 3 kali. Program berhenti.\n";
                return 0;
            }
        } else if (pilihan == 3) {
            cout << "Keluar dari program.\n";
            return 0;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (true);
    return 0;
}