// Tugas OOP Kasus 2 Sistem Karakter Game Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;

class Karakter {
protected:
    string nama;
    int kesehatan;
public:
    Karakter(const string& nama, int kesehatan) : nama(nama), kesehatan(kesehatan) {}
    virtual void tampilkan_info() = 0;
    virtual ~Karakter() {}

    void ubah_kesehatan(int jumlah) { kesehatan += jumlah; }
    int dapatkan_kesehatan() const { return kesehatan; }
    string dapatkan_nama() const { return nama; }
};

class Pemain : public Karakter {
public:
    Pemain(const string& nama, int kesehatan) : Karakter(nama, kesehatan) {}
    void tampilkan_info() override {
        cout << "[Pemain] " << nama << " - Kesehatan: " << kesehatan << endl;
    }
};

class Musuh : public Karakter {
public:
    Musuh(const string& nama, int kesehatan) : Karakter(nama, kesehatan) {}
    void tampilkan_info() override {
        cout << "[Musuh] " << nama << " - Kesehatan: " << kesehatan << endl;
    }
};

class NPC : public Karakter {
public:
    NPC(const string& nama, int kesehatan) : Karakter(nama, kesehatan) {}
    void tampilkan_info() override {
        cout << "[NPC] " << nama << " - Kesehatan: " << kesehatan << endl;
    }
};

class Kemampuan {
public:
    virtual void jalankan(Karakter& karakter) = 0;
    virtual ~Kemampuan() {}
};

class Penyembuhan : public Kemampuan {
public:
    void jalankan(Karakter& karakter) override {
        karakter.ubah_kesehatan(10);
        cout << karakter.dapatkan_nama() << " disembuhkan! Kesehatan baru: " << karakter.dapatkan_kesehatan() << endl;
    }
};

class Serangan : public Kemampuan {
public:
    void jalankan(Karakter& karakter) override {
        karakter.ubah_kesehatan(-10);
        cout << karakter.dapatkan_nama() << " diserang! Sisa kesehatan: " << karakter.dapatkan_kesehatan() << endl;
    }
};

class Pertahanan : public Kemampuan {
public:
    void jalankan(Karakter& karakter) override {
        cout << karakter.dapatkan_nama() << " sedang bertahan!" << endl;
    }
};

int main() {

    Pemain pemain("Alucard", 100);
    Musuh musuh("Balmond", 50);
    NPC npc("Layla", 80);

    Penyembuhan penyembuhan;
    Serangan serangan;
    Pertahanan pertahanan;

    cout << "\n=== Sebelum Pertempuran ===\n";
    pemain.tampilkan_info();
    musuh.tampilkan_info();
    npc.tampilkan_info();

    cout << "\n=== Alucard menyerang Balmond! ===\n";
    serangan.jalankan(musuh);
    musuh.tampilkan_info();

    cout << "\n=== Layla menyembuhkan Alucard! ===\n";
    penyembuhan.jalankan(pemain);
    pemain.tampilkan_info();

    cout << "\n=== Balmond bertahan dari serangan! ===\n";
    pertahanan.jalankan(musuh);

    return 0;
}