#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
enum memberStatus {YA, TIDAK};
     memberStatus member_user = YA;

int   pilih, a, b, kuantitas, kodeDiskon;
bool  lanjutBelanja = true;
bool  diskonBenar   = false;
float totalBelanja  = 0.0;
float totalDiskon   = 0.0;
float totalAkhir    = 0.0;
const int dscn      = 3;
const int MENU      = 5;

const int    diskonCode [dscn] = {231167, 556297, 201023};
const string diskonTeks [dscn] = {" (5%): ", " (20%)", " (99%):"};
const float  diskon     [dscn] = {0.05, 0.2, 0.99};
const int    nomorMenu  [MENU] = {1, 2, 3, 4, 5};
const string namaMenu   [MENU] = {"Nasgor", "Telor Ceplok", "Mie Ayam", "Mie Goreng", "Mie Rebus"};
const float  hargaMenu  [MENU] = {15000.00, 5000.00, 10000.00, 12000.00, 13000.00};

void pilihan (int *num){
     *num = *num - 1;}

int cekInput (string cek, int q, int w){
    int input;
    while (true){
        cout << cek;
        if (!(cin >> input) || input < q || input > w){
            cin.clear();
            cin.ignore(99, '\n');
            cout << "| INPUT TIDAK VALID!!. Silakan coba lagi\n" << endl;
        }else{
            cin.ignore(99, '\n');
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
        pilih = cekInput("| Masukan nomor menu yang ingin dibeli: ", 0, MENU);

            if (pilih == 0){
                break;
            }

            pilihan(&pilih);
            cout << "| Menu yang anda dipilih: " << namaMenu[pilih] << endl;
            kuantitas = cekInput("| Masukan jumlah/kuantitas menu yang ingin dibeli: ", 1, numeric_limits<int>::max());

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
        if (member_user == YA){
            cout << "Kode diskon: ";
            cin >> kodeDiskon;
            for(b = 0; b < dscn; b++){
                if(diskonCode[b] == kodeDiskon){
                totalDiskon = totalBelanja * diskon[b];
                diskonBenar = true;
                cout << setw(23) << left  << ("Diskon diperoleh" + diskonTeks[b])
                     << setw(5)  << right << " Rp. "
                     << setw(13) << right << totalDiskon << endl;
                break;
            }
        }
        if(!diskonBenar){
            cout << "        --- DISKON TIDAK VALID ---\n"
                 << setw(23) << left  << "Diskon diperoleh"
                 << setw(5)  << right << " Rp. "
                 << setw(13) << right << "0.00" << endl;
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
