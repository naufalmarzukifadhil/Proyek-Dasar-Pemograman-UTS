#include <iostream>
#include <iomanip>

using namespace std;
enum memberStatus {YA, TIDAK};
    memberStatus member_user = YA;
struct diskon{
    int kode;
    string diskonTeks;
    float diskon;};
        diskon memberBiasa {231167, " (5%): ", 0.05};
        diskon memberSetia {556297, " (20%):", 0.2};
        diskon memberKesayanganAtmin {201023, " (99%):", 0.99};
int pilih, a, kuantitas, kodeDiskon;
bool lanjutBelanja = true;
float totalBelanja = 0.0;
float totalDiskon = 0.0;
float totalAkhir = 0.0;
const int MENU = 5;

const int nomorMenu[MENU] = {1, 2, 3, 4, 5};
const string namaMenu[MENU] = {"Nasgor", "Telor Ceplok", "Mie Ayam", "Mie Goreng", "Mie Rebus"};
const float hargaMenu [MENU] = {15000.00, 5000.00, 10000.00, 12000.00, 13000.00};

void pilihan (int *num){
    *num = *num - 1;}

void tampilkanMenu(){
    cout << "=========================================" << endl;
    cout << "=== PROGRAM TAGIHAN BELANJA SEDERHANA ===" << endl;
    cout << "=========================================" << endl;
    cout << "NO |       NAMA MENU      |    HARGA     " << endl;
    cout << "=========================================" << endl;
    for (a = 0 ; a < MENU; a++){
        cout << setw(2) << nomorMenu[a] << " | "
             << setw(20) << left << namaMenu[a] << " | " << " Rp "
             << setw(9) << right << fixed << setprecision(2) << hargaMenu[a] << endl;
    }};

int main(){
    tampilkanMenu();

    do{
        cout << "\n| TEKAN *0* UNTUK SELESAI" << endl;
        cout << "| Masukan nomor menu yang ingin dibeli: ";
        cin >> pilih;

            if (pilih == 0){
                break;
            }else if (pilih > MENU || pilih < 1){
                cout << "\n//////NOMOR TIDAK VALID!!. Silakan coba lagi//////" << endl;
                continue;}

            pilihan(&pilih);
            cout << "| Menu yang anda dipilih: " << namaMenu[pilih] << endl;
            cout << "| Masukan jumlah/kuantitas menu yang ingin dibeli: ";
            cin >> kuantitas;

            if (kuantitas < 1){
                cout << "\n//////KUANTITAS TIDAK VALID!!. Silakan coba lagi//////" << endl;
                continue;}

        float subtotal = hargaMenu[pilih] * kuantitas;
        totalBelanja += subtotal;

        cout << "| Menu yang anda pilih " << namaMenu[pilih] << ", sebanyak " << kuantitas << 'x' << endl;
        cout << "| Subtotal = (Rp. " << subtotal << ")" << endl;
        cout << string (3, '\n');
        tampilkanMenu();

    } while (lanjutBelanja);

    if (totalBelanja > 0){
        cout << "\n=========================================" << endl;
        cout << "             -Detail tagihan-" << endl;
        cout << "=========================================" << endl;
        cout << "Total belanja awal: Rp. " << right << setw(17) << totalBelanja << endl;
        if (member_user == YA){
            cout << "Kode diskon: ";
            cin >> kodeDiskon;
            if (memberBiasa.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberBiasa.diskon;
                cout << "Diskon diperoleh" << memberBiasa.diskonTeks
                     << setw(18) << totalDiskon << endl;
            }else if(memberSetia.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberSetia.diskon;
                cout << "Diskon diperoleh" << memberSetia.diskonTeks
                     << setw(18) << totalDiskon << endl;
            }else if (memberKesayanganAtmin.kode == kodeDiskon){
                totalDiskon = totalBelanja * memberKesayanganAtmin.diskon;
                cout << "Diskon diperoleh" << memberKesayanganAtmin.diskonTeks
                     << setw(18) << totalDiskon << endl;
            }else{
                cout << "Diskon diperoleh:                     0.00" << endl;}
        }
        totalAkhir = totalBelanja - totalDiskon;
        cout << "-----------------------------------------" << endl;
        cout << "Total belanja akhir: Rp." << right << setw(17) << totalAkhir << endl;
        cout << "=========================================" << endl;
        cout << "     Terimakasih telah berbelanja :D" << endl;
    } else if (totalBelanja <= 0){
            cout << "\nTidak ada menu yang dipilih :(" << endl;}

    return 0;
}
