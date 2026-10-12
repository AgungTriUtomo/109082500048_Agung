#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

// Fungsi: menghitung nilai akhir = 0.3*uts + 0.4*uas + 0.3*tugas
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f * uts + 0.4f * uas + 0.3f * tugas;
}

void inputMhs(mahasiswa &m) {
    cout << "Nama   : ";
    cin.ignore(10000, '\n');
    getline(cin, m.nama);
    cout << "NIM    : ";
    cin >> m.nim;
    cout << "UTS    : ";
    cin >> m.uts;
    cout << "UAS    : ";
    cin >> m.uas;
    cout << "Tugas  : ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilMhs(const mahasiswa &m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}

int main() {
    mahasiswa data[MAX];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX << ") : ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMhs(data[i]);
    }

    cout << "\n===== DAFTAR MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilMhs(data[i]);
    }
    return 0;
}