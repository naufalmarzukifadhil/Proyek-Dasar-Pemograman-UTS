#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
enum memberStatus {YA, TIDAK};
     memberStatus member_user = YA;

int   pilih, a, b, kuantitas, kodeDiskon;
bool  lanjutBelanja = true;
float totalBelanja  = 0.0;
float totalDiskon   = 0.0;
float totalAkhir    = 0.0;
const int dscn      = 3;
const int MENU      = 5;

const int diskonCode    [dscn] = {231167, 556297, 201023};
const string diskonTeks [dscn] = {" (5%): ", " (20%)", " (99%):"};
const float diskon      [dscn] = {0.05, 0.2, 0.99};
const int    nomorMenu  [MENU] = {1, 2, 3, 4, 5};
const string namaMenu   [MENU] = {"Nasgor", "Telor Ceplok", "Mie Ayam", "Mie Goreng", "Mie Rebus"};
const float  hargaMenu  [MENU] = {15000.00, 5000.00, 10000.00, 12000.00, 13000.00};

void pilihan (int *num){
     *num = *num - 1;}

int cekAngka (string cek){
    int input;
    while (true){
        cout << cek;
        if (!(cin >> input)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "| INPUT TIDAK VALID!!. Silakan coba lagi\n" << endl;
        }else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return input;
        }
    }
}

void tampilkanMenu(){
    cout << "=========================================" << endl;
    cout << "=== PROGRAM TAGIHAN BELANJA SEDERHANA ===" << endl;
    cout << "=========================================" << endl;
    cout << "NO |       NAMA MENU      |    HARGA     " << endl;
    cout << "=========================================" << endl;
    for (a = 0 ; a < MENU; a++){
        cout << setw(2) << nomorMenu[a] << " | "
             << setw(20) << left << namaMenu[a] << " | " << " Rp. "
             << setw(8) << right << fixed << setprecision(2) << hargaMenu[a] << endl;
    }};

int main(){
    tampilkanMenu();
    cout << "\n| TEKAN *0* UNTUK SELESAI" << endl;
    do{
        pilih = cekAngka("| Masukan nomor menu yang ingin dibeli: ");

            if (pilih == 0){
                break;
            }else if (pilih > MENU || pilih < 1){
                cout << "| NOMOR TIDAK VALID!!. Silakan coba lagi\n" << endl;
                continue;}

            pilihan(&pilih);
            cout << "| Menu yang anda dipilih: " << namaMenu[pilih] << endl;
            kuantitas = cekAngka("| Masukan jumlah/kuantitas menu yang ingin dibeli: ");

            if (kuantitas < 1){
                cout << "| NOMOR TIDAK VALID!!. Silakan coba lagi\n" << endl;
                continue;}

        float subtotal = hargaMenu[pilih] * kuantitas;
        totalBelanja += subtotal;

        cout << "| Menu yang anda pilih " << namaMenu[pilih] << ", sebanyak " << kuantitas << 'x' << endl;
        cout << "| Subtotal = (Rp. " << subtotal << ")" << endl;
        cout << '\n';
        tampilkanMenu();
        cout << "\n| TEKAN *0* UNTUK SELESAI" << endl;

    } while (lanjutBelanja);

    if (totalBelanja > 0){
        cout << "\n=========================================" << endl;
        cout << "             -Detail tagihan-" << endl;
        cout << "=========================================" << endl;
        cout << setw(23) << left  << "Total belanja awal: "
             << setw(5)  << right << "Rp. "
             << setw(13) << right << totalBelanja << endl;
    }
    if (member_user == YA){
        cout << "Kode diskon: ";
        cin >> kodeDiskon;
        for(b = 0; b < dscn; b++){
            if(diskonCode[b] == kodeDiskon){
            totalDiskon = totalBelanja * diskon[b];
            cout << setw(23) << left  << ("Diskon diperoleh" + diskonTeks[b])
                 << setw(5)  << right << " Rp. "
                 << setw(13) << right << totalDiskon << endl;
        }
    }
        totalAkhir = totalBelanja - totalDiskon;
        cout << "-----------------------------------------" << endl;
        cout << setw(23) << left  << "Total belanja akhir: "
             << setw(5)  << right << "Rp. "
             << setw(13) << right << totalAkhir << endl;
        cout << "=========================================" << endl;
        cout << "     Terimakasih telah berbelanja :D" << endl;
    } else if (totalBelanja <= 0){
        cout << "\nTidak ada menu yang dipilih :(" << endl;
    }

    return 0;
}

    return 0;
}


