# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">(Nama Lengkap) - (NIM)</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. Program penyimpanan data mahasiswa (maks. 10) dalam array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus 0.3*uts + 0.4*uas + 0.3*tugas

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/Output-Unguided1-2.png)

Program ini menyimpan data mahasiswa dalam array `data[10]` bertipe `struct mahasiswa`. Pengguna terlebih dahulu memasukkan jumlah mahasiswa (1-10), lalu mengisi nama, NIM, UTS, UAS, dan tugas untuk tiap mahasiswa. Nilai akhir tidak dihitung langsung di `main`, melainkan lewat fungsi `hitungNilaiAkhir()` yang mengembalikan `0.3*uts + 0.4*uas + 0.3*tugas`. Fungsi tersebut dipanggil di dalam prosedur `inputMhs()`, yang menerima parameter secara referensi (`&m`) agar perubahan nilai tersimpan pada elemen array. Setelah semua data terisi, prosedur `tampilMhs()` menampilkan seluruh data beserta nilai akhirnya. Sebagai contoh, UTS 80, UAS 90, dan tugas 70 menghasilkan nilai akhir 81.

### 2. Membuat ADT pelajaran pada file "pelajaran.h", implementasinya pada "pelajaran.cpp", dan mencobanya pada "main.cpp"

**pelajaran.h**
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Konstruktor: membentuk ADT pelajaran dari nama dan kode
pelajaran create_pelajaran(string namapel, string kodepel);

// Initial state: pel terdefinisi
// Final state  : nama dan kode pelajaran tampil di layar
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```

**pelajaran.cpp**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

**main.cpp**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/Output-Unguided2-1.png)

Program dipisah menjadi tiga file sesuai konsep ADT. File `pelajaran.h` berisi spesifikasi type `pelajaran` (field `namaMapel` dan `kodeMapel`) serta prototype primitif `create_pelajaran()` sebagai konstruktor dan `tampil_pelajaran()` untuk menampilkan data. File `pelajaran.cpp` berisi realisasi (body) kedua primitif tersebut. File `main.cpp` bertindak sebagai driver yang membuat objek `pel` dengan nama "Struktur Data" dan kode "STD", lalu menampilkannya. Perintah compile: `g++ main.cpp pelajaran.cpp -o pelajaran`. Output yang dihasilkan:

```
nama pelajaran : Struktur Data
nilai : STD
```

### 3. Program dengan 2 array 2D integer 3x3 dan 2 pointer integer, dengan fungsi/prosedur untuk menampilkan array, menukar isi kedua array pada posisi tertentu, dan menukar isi variabel yang ditunjuk oleh 2 pointer

```C++
#include <iostream>
using namespace std;

const int N = 3;

// Menampilkan isi array integer 2D 3x3
void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Menukar isi array A dan B pada posisi (baris, kolom) tertentu
void tukarPosisi(int A[N][N], int B[N][N], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

// Menukar isi variabel yang ditunjuk oleh dua pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A awal:" << endl;
    tampilArray(A);
    cout << "\nArray B awal:" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2) : ";
    cin >> baris >> kolom;
    if (baris < 0 || baris >= N || kolom < 0 || kolom >= N) {
        cout << "Posisi tidak valid!" << endl;
        return 1;
    }

    tukarPosisi(A, B, baris, kolom);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);
    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    cout << "\nSebelum tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/Output-Unguided3-2.png)

Program memiliki dua array `A` dan `B` berukuran 3x3 serta dua pointer `p1` dan `p2` yang menunjuk ke variabel `x` dan `y`. Prosedur `tampilArray()` menampilkan isi array dengan dua perulangan bersarang. Prosedur `tukarPosisi()` menukar elemen `A[baris][kolom]` dengan `B[baris][kolom]` menggunakan variabel `temp`; posisi dimasukkan oleh pengguna dan divalidasi agar berada pada rentang 0-2. Prosedur `tukarPointer()` menukar isi variabel yang ditunjuk oleh kedua pointer (`*p1` dan `*p2`), sehingga nilai `x` dan `y` saling bertukar (misalnya dari 10 dan 20 menjadi 20 dan 10), sedangkan alamat yang disimpan pointer tidak berubah.

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
