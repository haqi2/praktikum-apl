#include "iostream"

using namespace std;
#define max 100 
int panjangarray = 0; 
string panjangArray[max]; 
int pilihan, index;

int main() {


while(true){

    cout << "pilih menu" << endl;
    cout << "1. input data" << endl;
    cout << "2. Tampilkan data" << endl;
    cout << "3. Hapus Data" << endl;
    cout << "4. Keluar" << endl;

    cin >> pilihan;

    if (pilihan == 1){
        if (panjangarray < max){
        cout << "Masukkan Data :";
        cin >> arr[panjangarray];
        panjangArray++;
        } else if (panjangArray = 0)
    }
}
//     // int arr[3][3][3] = {
    // {
    // {1, 2, 3},
    // {4, 5, 6},
    // {7, 8, 9}
    // },
    // {
    // {10, 11, 12},
    // {13, 14, 15},
    // {16, 17, 18}
    // },
    // {
    // {19, 20, 21},
    // {22, 23, 24},
    // {25, 26, 27}
    // }
    // };
    // cout << arr[1][2][1] << endl; // Output: 17
    // return 0;
    }


// int main() {

//     // string nama[] = {"haqi, reki, leki, haci, lip"};
//     string nama [4][4] = {
//         {"fahmi", "informatika", "123", "mangan"},
//         {"febri", "informatika", "132", "roblox"},
//         {"haci", "sisfor", "001", "aaaa"},
//         {"jek", "sipil", "090" "kucing", }
//     };

    // cout << nama [3][2] << endl;
    // cout << nama [3] [1];
    // cout << sizeof(nama) / sizeof(string) << endl;


    // int panjang = sizeof(nama) / sizeof(nama[0]);

    // for ( int i = 0; i < panjang; i++){
    // //     cout << nama [i] << endl;
    // }



//     // cout << sizeof(nama) / sizeofnama([0]) endl; otal elemen array
//     cout << sizeof(nama) / sizeof(string) << endl;
//     // cout << nama[-5] << endl;
//     return 0;
