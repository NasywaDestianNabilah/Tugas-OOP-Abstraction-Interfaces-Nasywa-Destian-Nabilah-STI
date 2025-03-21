// Tugas OOP Kasus 1 Notifikasi Sistem Nasywa Destian Nabilah STI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <ctime>

using namespace std;

string get_current_time() {
    time_t now = time(0);
    struct tm timeinfo;
    char buf[80];

    localtime_s(&timeinfo, &now); 
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);

    return string(buf);
}

class Notifikasi {
public:
    virtual void kirim(const string& pesan, const string& penerima) = 0;
    virtual ~Notifikasi() {}
};

class NotifikasiEmail : public Notifikasi {
public:
    void kirim(const string& pesan, const string& penerima) override {
        cout << "[EMAIL] " << get_current_time() << " - Mengirim Email ke " << penerima << "\n"
            << "       Pesan: \"" << pesan << "\"\n" << endl;
    }
};

class NotifikasiSMS : public Notifikasi {
public:
    void kirim(const string& pesan, const string& penerima) override {
        cout << "[SMS] " << get_current_time() << " - Mengirim SMS ke " << penerima << "\n"
            << "       Pesan: \"" << pesan << "\"\n" << endl;
    }
};

class NotifikasiPush : public Notifikasi {
public:
    void kirim(const string& pesan, const string& penerima) override {
        cout << "[PUSH] " << get_current_time() << " - Mengirim Push Notifikasi ke " << penerima << "\n"
            << "       Pesan: \"" << pesan << "\"\n" << endl;
    }
};

class PabrikNotifikasi {
public:
    static unique_ptr<Notifikasi> buat_notifikasi(const string& tipe) {
        if (tipe == "email") return make_unique<NotifikasiEmail>();
        if (tipe == "sms") return make_unique<NotifikasiSMS>();
        if (tipe == "push") return make_unique<NotifikasiPush>();
        throw invalid_argument("Tipe notifikasi tidak dikenal");
    }
};

int main() {
    
    auto notif_email = PabrikNotifikasi::buat_notifikasi("email");
    notif_email->kirim("Halo! Ini adalah email percobaan.", "usernasywadestiann@gmail.com");

    auto notif_sms = PabrikNotifikasi::buat_notifikasi("sms");
    notif_sms->kirim("Jangan lupa pertemuan besok jam 10 pagi!", "+628123456789");

    auto notif_push = PabrikNotifikasi::buat_notifikasi("push");
    notif_push->kirim("Selamat! Anda mendapatkan hadiah spesial.", "user_nasywa");

    return 0;
}