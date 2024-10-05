#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


struct Barang {
    string nama;
    double harga;
    int jumlah;
};


double hitungTotalPendapatan(const Barang& barang) {
    return barang.harga * barang.jumlah;
}

int main() {
    vector<Barang> daftarBarang;
    char tambahData;

    do {
        Barang barang;
        cout << "Masukkan nama barang: ";
        cin.ignore(); 
        getline(cin, barang.nama);
        cout << "Masukkan harga per barang: ";
        cin >> barang.harga;
        cout << "Masukkan jumlah barang terjual: ";
        cin >> barang.jumlah;

        daftarBarang.push_back(barang);

        cout << "Ingin memasukkan data penjualan lagi? (y/n): ";
        cin >> tambahData;
    } while (tambahData == 'y' || tambahData == 'Y');


    cout << "--------------------------------------------------------------\n";
    cout << "| No | Nama Barang   | Harga per Barang | Jumlah Terjual | Total Pendapatan |\n";
    cout << "--------------------------------------------------------------\n";
    for (size_t i = 0; i < daftarBarang.size(); ++i) {
        const Barang& barang = daftarBarang[i];
        double totalPendapatan = hitungTotalPendapatan(barang);
        cout << "| " << setw(2) << i + 1 << " | " << setw(13) << barang.nama << " | " << setw(16) << barang.harga << " | " << setw(14) << barang.jumlah << " | " << setw(17) << totalPendapatan << " |\n";
    }
    cout << "--------------------------------------------------------------\n";

    return 0;
}

