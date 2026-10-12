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