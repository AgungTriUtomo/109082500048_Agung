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

#endif 