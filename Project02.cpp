#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
enum memberStatus {YA, TIDAK};
     memberStatus member_user = YA;
struct diskon{
    int    kode;
    string diskonTeks;
    float  diskon;};
        diskon memberBiasa {231167, " (5%): ", 0.05};
        diskon memberSetia {556297, " (20%):", 0.2};
        diskon memberKesayanganAtmin {201023, " (99%):", 0.99};
int   pilih, a, kuantitas, kodeDiskon;
bool  lanjutBelanja = true;
float totalBelanja  = 0.0;
float totalDiskon   = 0.0;
float totalAkhir    = 0.0;
const int MENU      = 5;

const int    nomorMenu  [MENU] = {1, 2, 3, 4, 5};
const string namaMenu   [MENU] = {"Nasgor", "Telor Ceplok", "Mie Ayam", "Mie Goreng", "Mie Rebus"};
const float  hargaMenu  [MENU] = {15000.00, 5000.00, 10000.00, 12000.00, 13000.00};

void pilihan (int *num){
     *num = *num - 1;}

int cekAngka (string cek){
    int input;
    while (true){
        cout << cek;
        cin >> input;

        if (cin.fail()){
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
        if (member_user == YA){
            cout << "Kode diskon: ";
            cin >> kodeDiskon;
            if (memberBiasa.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberBiasa.diskon;
                cout << setw(23) << left  << ("Diskon diperoleh" + memberBiasa.diskonTeks)
                     << setw(5)  << right << " Rp. "
                     << setw(13) << right << totalDiskon << endl;
            }else if(memberSetia.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberSetia.diskon;
                cout << setw(23) << left  << ("Diskon diperoleh" + memberSetia.diskonTeks)
                     << setw(5)  << right << " Rp. "
                     << setw(13) << right << totalDiskon << endl;
            }else if (memberKesayanganAtmin.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberKesayanganAtmin.diskon;
                cout << setw(23) << left  << ("Diskon diperoleh" + memberKesayanganAtmin.diskonTeks)
                     << setw(5)  << right << " Rp. "
                     << setw(13) << right << totalDiskon << endl;
            }else{
                cout << "Diskon diperoleh:                    0.00" << endl;}
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

