#include <iostream>
using namespace std;

int main() {
    system("cls");
    string username, password;
    int login = 0;
    bool berhasillogin = false;

    while (login < 3) {
        cout << "\n==== LOGIN ====" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        system("cls");

        if (username == "Haqi" && password == "081") {
            berhasillogin = true;
            cout << "Login Berhasil!\n";
            cout << "Klik untuk melanjutkan...";
            cin.ignore();
            cin.get();
            break;
        } else {
            cout << "Login gagal! Coba lagi. (Percobaan: " << (login + 1) << "/3)\n";
            cout << "Klik untuk melanjutkan...";
            cin.ignore();
            cin.get();
            login++;
        }
    }

    if (!berhasillogin) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        cout << "Klik untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return 0;
    }

    int pilihan;
    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Konversi Mata Uang\n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. LOGOUT\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        system("cls");

        if (pilihan == 1) {
            int pilihUang;
            double rupiah, dollar, euro;
            double kursDollar = 15000;
            double kursEuro = 17200;
            double kursDollarKeEuro = 0.93;
            do {
                system("cls");
                cout << "\n====Konversi Mata Uang====\n";
                cout << "1. Rupiah ke Dollar AS" << endl;
                cout << "2. Rupiah ke EURO" << endl;
                cout << "3. Dollar AS ke Rupiah" << endl;
                cout << "4. Dollar AS ke EURO" << endl;
                cout << "5. EURO ke Rupiah" << endl;
                cout << "6. EURO ke Dollar AS" << endl;
                cout << "7. Kembali" << endl;
                cout << "Pilih konversi (1-7): ";
                cin >> pilihUang;
                system("cls");

                if (pilihUang == 1) {
                    system("cls");
                    cout << "Masukkan jumlah Rupiah: ";
                    cin >> rupiah;
                    cout << rupiah << " Rupiah = " << rupiah / kursDollar << " Dollar AS\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihUang == 2) {
                    system("cls");
                    cout << "Masukkan jumlah Rupiah: ";
                    cin >> rupiah;
                    cout << rupiah << " Rupiah = " << rupiah / kursEuro << " EURO\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihUang == 3) {
                    system("cls");
                    cout << "Masukkan jumlah Dollar: ";
                    cin >> dollar;
                    cout << dollar << " Dollar AS = " << dollar * kursDollar << " Rupiah\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihUang == 4) {
                    system("cls");
                    cout << "Masukkan jumlah Dollar: ";
                    cin >> dollar;
                    cout << dollar << " Dollar AS = " << dollar * kursDollarKeEuro << " EURO\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihUang == 5) {
                    system("cls");
                    cout << "Masukkan jumlah EURO: ";
                    cin >> euro;
                    cout << euro << " EURO = " << euro * kursEuro << " Rupiah\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihUang == 6) {
                    system("cls");
                    cout << "Masukkan jumlah EURO: ";
                    cin >> euro;
                    cout << euro << " EURO = " << euro / kursDollarKeEuro << " Dollar AS\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
            } while (pilihUang != 7);
        }

        else if (pilihan == 2) {
            int pilihJarak;
            double kilometer, meter, centimeter;
            do {
                cout << "\n==== Konversi Jarak ====\n";
                cout << "1. Kilometer ke Meter\n2. Kilometer ke Centimeter\n3. Meter ke Kilometer\n";
                cout << "4. Meter ke Centimeter\n5. Centimeter ke Kilometer\n6. Centimeter ke Meter\n7. Kembali\n";
                cout << "Pilih konversi (1-7): ";
                cin >> pilihJarak;
                system("cls");

                if (pilihJarak == 1) {
                    system("cls");
                    cout << "Masukkan Kilometer: ";
                    cin >> kilometer;
                    cout << kilometer << " Kilometer = " << kilometer * 1000 << " Meter\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihJarak == 2) {
                    system("cls");
                    cout << "Masukkan Kilometer: ";
                    cin >> kilometer;
                    cout << kilometer << " Kilometer = " << kilometer * 100000 << " Centimeter\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihJarak == 3) {
                    system("cls");
                    cout << "Masukkan jumlah Meter: ";
                    cin >> meter;
                    cout << meter << " Meter = " << meter / 1000 << " Kilometer\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihJarak == 4) {
                    system("cls");
                    cout << "Masukkan jumlah Meter: ";
                    cin >> meter;
                    cout << meter << " Meter = " << meter * 100 << " Centimeter\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihJarak == 5) {
                    system("cls");
                    cout << "Masukkan jumlah Centimeter: ";
                    cin >> centimeter;
                    cout << centimeter << " Centimeter = " << centimeter / 100000 << " Kilometer\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihJarak == 6) {
                    system("cls");
                    cout << "Masukkan jumlah Centimeter: ";
                    cin >> centimeter;
                    cout << centimeter << " Centimeter = " << centimeter / 100 << " Meter\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
            } while (pilihJarak != 7);
        }

        else if (pilihan == 3) {
            int pilihWaktu,detik ;
            double jam, menit, sisaDetik;
            do {
                cout << "\n==== Konversi Waktu ====\n";
                cout << "1. Jam ke Menit\n2. Jam ke Detik\n3. Menit ke Jam\n4. Menit ke Detik\n";
                cout << "5. Detik ke Jam\n6. Detik ke Menit\n7. Kembali\n";
                cout << "Pilih konversi (1-7): ";
                cin >> pilihWaktu;
                system("cls");

                if (pilihWaktu == 1) {
                    system("cls");
                    cout << "Masukkan jumlah Jam: ";
                    cin >> jam;
                    cout << jam << " Jam = " << jam * 60 << " Menit\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihWaktu == 2) {
                    system("cls");
                    cout << "Masukkan jumlah Jam: ";
                    cin >> jam;
                    cout << jam << " Jam = " << jam * 3600 << " Detik\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihWaktu == 3) {
                    system("cls");
                    cout << "Masukkan jumlah Menit: ";
                    cin >> menit;
                    cout << menit << " Menit = " << menit / 60 << " Jam\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihWaktu == 4) {
                    system("cls");
                    cout << "Masukkan jumlah Menit: ";
                    cin >> menit;
                    cout << menit << " Menit = " << menit * 60 << " Detik\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihWaktu == 5) {
                    system("cls");
                    cout << "Masukkan jumlah Detik: ";
                    cin >> detik;
                    cout << detik << " Detik = " << detik / 3600 << " Jam\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (pilihWaktu == 6) {
                    system("cls");
                    cout << "Masukkan jumlah Detik: ";
                    cin >> detik;
                    int menit = detik / 60; 
                    int sisaDetik = detik % 60;
                    cout << detik << " Detik = " << menit << " Menit " << sisaDetik << " Detik\n";
                    cout << "Klik untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
            } while (pilihWaktu != 7);
        }

    } while (pilihan != 4);

    cout << "Terima kasih, logout berhasil.\n";
    cin.ignore();
    cin.get();
    return 0;
}
