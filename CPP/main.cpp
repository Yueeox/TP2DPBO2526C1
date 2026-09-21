#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include "Tiket.cpp"

using namespace std;

vector<Film> listFilm;
vector<Tiket> listTiket;
int nextFilmId = 1;
int nextTiketId = 101;

string formatRupiah(int harga) {
    string str = to_string(harga);
    int len = str.length();
    string res = "";
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        res += str[i];
        count++;
        if (count % 3 == 0 && i != 0) res += ".";
    }
    reverse(res.begin(), res.end());
    return "Rp " + res;
}

string repeatString(const string& str, int times) {
    string res = "";
    for (int i = 0; i < times; i++) res += str;
    return res;
}

void buatTiketDariFilm(const Film& f, string bioskop, string studio, int harga, char row, int seat, string tgl, string waktu) {
    listTiket.push_back(Tiket(
        nextTiketId++, f.getJudul(), f.getTahun(), f.getHakCipta(),
        f.getGenre(), f.getDurasiMenit(), f.getRumahProduksi(),
        bioskop, studio, harga, row, seat, tgl, waktu
    ));
}

void initDummyData() {
    listFilm.push_back(Film(nextFilmId++, "Inception", 2010, "Warner Bros", "Sci-Fi", 148, "Syncopy"));
    listFilm.push_back(Film(nextFilmId++, "Interstellar", 2014, "Paramount", "Sci-Fi", 169, "Lynda Obst"));
    listFilm.push_back(Film(nextFilmId++, "The Dark Knight", 2008, "Warner Bros", "Action", 152, "DC Comics"));
    listFilm.push_back(Film(nextFilmId++, "Avatar: Way of Water", 2022, "20th Century", "Sci-Fi", 192, "Lightstorm"));
    listFilm.push_back(Film(nextFilmId++, "Spirited Away", 2001, "Studio Ghibli", "Anime", 125, "Studio Ghibli"));

    buatTiketDariFilm(listFilm[0], "CGV Grand Indonesia", "1", 50000, 'A', 12, "2026-03-25", "14:00");
    buatTiketDariFilm(listFilm[1], "XXI Botani Square", "2", 60000, 'B', 5, "2026-03-25", "17:30");
    buatTiketDariFilm(listFilm[2], "Cinepolis Plaza", "3", 45000, 'C', 10, "2026-03-26", "19:00");
    buatTiketDariFilm(listFilm[3], "IMAX Gandaria", "1", 75000, 'D', 14, "2026-03-26", "20:15");
    buatTiketDariFilm(listFilm[4], "CGV Paris Van Java", "4", 40000, 'E', 8, "2026-03-27", "13:00");
}

void tampilkanMasterFilmDinamis() {
    if (listFilm.empty()) {
        cout << "Belum ada data master film.\n";
        return;
    }

    int wId = 2, wJudul = 10, wTahun = 5, wHakCipta = 9, wGenre = 5, wDurasi = 6, wStudio = 14;

    for (const auto& f : listFilm) {
        wId = max(wId, (int)to_string(f.getId()).length());
        wJudul = max(wJudul, (int)f.getJudul().length());
        wTahun = max(wTahun, (int)to_string(f.getTahun()).length());
        wHakCipta = max(wHakCipta, (int)f.getHakCipta().length());
        wGenre = max(wGenre, (int)f.getGenre().length());
        wDurasi = max(wDurasi, (int)(to_string(f.getDurasiMenit()) + " Menit").length());
        wStudio = max(wStudio, (int)f.getRumahProduksi().length());
    }

    string lineSeparator = "+" + repeatString("-", wId + 2) + "+" + repeatString("-", wJudul + 2) + "+" + repeatString("-", wTahun + 2) + "+" + repeatString("-", wHakCipta + 2) + "+" + repeatString("-", wGenre + 2) + "+" + repeatString("-", wDurasi + 2) + "+" + repeatString("-", wStudio + 2) + "+";

    cout << "\n--- DAFTAR MASTER FILM ---\n";
    cout << lineSeparator << "\n";
    cout << "| " << left << setw(wId) << "ID"
         << " | " << left << setw(wJudul) << "Judul Film"
         << " | " << left << setw(wTahun) << "Tahun"
         << " | " << left << setw(wHakCipta) << "Hak Cipta"
         << " | " << left << setw(wGenre) << "Genre"
         << " | " << left << setw(wDurasi) << "Durasi"
         << " | " << left << setw(wStudio) << "Rumah Produksi" << " |\n";
    cout << lineSeparator << "\n";

    for (const auto& f : listFilm) {
        string durasiStr = to_string(f.getDurasiMenit()) + " Menit";
        cout << "| " << left << setw(wId) << f.getId()
             << " | " << left << setw(wJudul) << f.getJudul()
             << " | " << left << setw(wTahun) << f.getTahun()
             << " | " << left << setw(wHakCipta) << f.getHakCipta()
             << " | " << left << setw(wGenre) << f.getGenre()
             << " | " << left << setw(wDurasi) << durasiStr
             << " | " << left << setw(wStudio) << f.getRumahProduksi() << " |\n";
    }
    cout << lineSeparator << "\n";
}

void tambahMasterFilm() {
    cout << "\n--- TAMBAH MASTER FILM BARU ---\n";
    cout << "ID Film: " << nextFilmId << "\n";

    string judul, hakCipta, genre, studioProd;
    int tahun, durasi;

    cout << "Judul Film: "; getline(cin, judul);

    while (true) {
        cout << "Tahun Rilis: ";
        if (cin >> tahun && tahun > 0) break;
        cout << "[ERROR] Tahun rilis harus lebih besar dari 0!\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    cout << "Hak Cipta: "; getline(cin, hakCipta);
    cout << "Genre: "; getline(cin, genre);

    while (true) {
        cout << "Durasi (menit): ";
        if (cin >> durasi && durasi > 0) break;
        cout << "[ERROR] Durasi film harus lebih besar dari 0 menit!\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    cout << "Rumah Produksi: "; getline(cin, studioProd);

    listFilm.push_back(Film(nextFilmId++, judul, tahun, hakCipta, genre, durasi, studioProd));
    cout << ">> Master Film berhasil ditambahkan dengan ID: " << (nextFilmId - 1) << "\n";
    tampilkanMasterFilmDinamis();
}

void tampilkanTabelTiketDinamis() {
    if (listTiket.empty()) {
        cout << "Belum ada data tiket.\n";
        return;
    }

    int wId = 8, wJudul = 5, wTahun = 5, wGenre = 5, wBioskop = 7, wStudio = 6, wKursi = 5, wHarga = 5, wJadwal = 13;

    for (const auto& t : listTiket) {
        string studioOut = "Studio " + t.getStudio();
        wId = max(wId, (int)to_string(t.getId()).length());
        wJudul = max(wJudul, (int)t.getJudul().length());
        wTahun = max(wTahun, (int)to_string(t.getTahun()).length());
        wGenre = max(wGenre, (int)t.getGenre().length());
        wBioskop = max(wBioskop, (int)t.getNamaTempat().length());
        wStudio = max(wStudio, (int)studioOut.length());
        wHarga = max(wHarga, (int)formatRupiah(t.getHarga()).length());
        wJadwal = max(wJadwal, (int)(t.getTanggal() + " " + t.getWaktu()).length());
    }

    string lineSeparator = "+" + repeatString("-", wId + 2) + "+" + repeatString("-", wJudul + 2) + "+" + repeatString("-", wTahun + 2) + "+" + repeatString("-", wGenre + 2) + "+" + repeatString("-", wBioskop + 2) + "+" + repeatString("-", wStudio + 2) + "+" + repeatString("-", wKursi + 2) + "+" + repeatString("-", wHarga + 2) + "+" + repeatString("-", wJadwal + 2) + "+";

    cout << "\n--- DAFTAR TIKET TERSEDIA ---\n";
    cout << lineSeparator << "\n";
    cout << "| " << left << setw(wId) << "ID Tiket"
         << " | " << left << setw(wJudul) << "Judul Film"
         << " | " << left << setw(wTahun) << "Tahun"
         << " | " << left << setw(wGenre) << "Genre"
         << " | " << left << setw(wBioskop) << "Bioskop"
         << " | " << left << setw(wStudio) << "Studio"
         << " | " << left << setw(wKursi) << "Kursi"
         << " | " << left << setw(wHarga) << "Harga"
         << " | " << left << setw(wJadwal) << "Jadwal" << " |\n";
    cout << lineSeparator << "\n";

    for (const auto& t : listTiket) {
        string studioOut = "Studio " + t.getStudio();
        string kursi = string(1, t.getRow()) + to_string(t.getSeat());
        string jadwal = t.getTanggal() + " " + t.getWaktu();
        string hargaFormatted = formatRupiah(t.getHarga());

        cout << "| " << left << setw(wId) << t.getId()
             << " | " << left << setw(wJudul) << t.getJudul()
             << " | " << left << setw(wTahun) << t.getTahun()
             << " | " << left << setw(wGenre) << t.getGenre()
             << " | " << left << setw(wBioskop) << t.getNamaTempat()
             << " | " << left << setw(wStudio) << studioOut
             << " | " << left << setw(wKursi) << kursi
             << " | " << left << setw(wHarga) << hargaFormatted
             << " | " << left << setw(wJadwal) << jadwal << " |\n";
    }
    cout << lineSeparator << "\n";
}

void tambahTiketBaru() {
    if (listFilm.empty()) {
        cout << "Belum ada master film! Tambahkan film terlebih dahulu.\n";
        return;
    }

    tampilkanMasterFilmDinamis();
    cout << "\nPilih ID Film yang ingin dibeli tiketnya: ";
    int idPilihan;
    if (!(cin >> idPilihan)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "ID Film tidak valid!\n";
        return;
    }
    cin.ignore(10000, '\n');

    const Film* selectedFilm = nullptr;
    for (const auto& f : listFilm) {
        if (f.getId() == idPilihan) {
            selectedFilm = &f;
            break;
        }
    }

    if (!selectedFilm) {
        cout << "ID Film tidak ditemukan!\n";
        return;
    }

    cout << "\n--- INPUT DETAIL TIKET UNTUK FILM: " << selectedFilm->getJudul() << " ---\n";
    cout << "ID Tiket: " << nextTiketId << "\n";

    string bioskop, studio, tgl, waktu;
    int harga, seat;
    char row;

    cout << "Nama Bioskop: "; getline(cin, bioskop);

    while (true) {
        cout << "Studio(1-9): ";
        getline(cin, studio);
        if (studio.length() == 1 && studio != "0" && studio >= "1" && studio <= "9") break;
        cout << "[ERROR] Studi tersedia dari 1-9!\n";
    }

    while (true) {
        cout << "Harga (Rp): ";
        if (cin >> harga && harga > 0) break;
        cout << "[ERROR] Harga tiket harus lebih besar dari 0!\n";
        cin.clear(); cin.ignore(10000, '\n');
    }

    while (true) {
        cout << "Baris Kursi (A-J): ";
        cin >> row;
        row = toupper(row);
        if (row >= 'A' && row <= 'J') break;
        cout << "[ERROR] Baris kursi tidak valid! Hanya diperbolehkan huruf A sampai J.\n";
    }

    while (true) {
        cout << "Nomor Kursi (1-14): ";
        if (cin >> seat && seat >= 1 && seat <= 14) break;
        cout << "[ERROR] Nomor kursi tidak valid! Hanya diperbolehkan angka 1 sampai 14.\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    while (true) {
        cout << "Tanggal (YYYY-MM-DD): ";
        getline(cin, tgl);
        if (tgl.length() == 10) break;
        cout << "[ERROR] Format tanggal harus YYYY-MM-DD (tepat 10 karakter)!\n";
    }

    while (true) {
        cout << "Waktu (HH:MM): ";
        getline(cin, waktu);
        if (waktu.length() == 5) break;
        cout << "[ERROR] Format waktu harus HH:MM (tepat 5 karakter)!\n";
    }

    buatTiketDariFilm(*selectedFilm, bioskop, studio, harga, row, seat, tgl, waktu);
    cout << ">> Tiket berhasil dibuat dengan ID Tiket: " << (nextTiketId - 1) << " untuk film " << selectedFilm->getJudul() << "\n";
    tampilkanTabelTiketDinamis();
}

void tampilkanSemuaData() {
    tampilkanTabelTiketDinamis();
    tampilkanMasterFilmDinamis();
}

int main() {
    initDummyData();

    bool running = true;
    while (running) {
        cout << "\n=============================================\n";
        cout << "     SISTEM MANAJEMEN TIKET FILM (OOP)       \n";
        cout << "=============================================\n";
        cout << "| 0. Tampilkan Semua Data                   |\n";
        cout << "| 1. Tampilkan Master Film                  |\n";
        cout << "| 2. Tampilkan Semua Tiket                  |\n";
        cout << "| 3. Tambah Master Film Baru                |\n";
        cout << "| 4. Tambah Tiket Baru                      |\n";
        cout << "| 5. Keluar                                 |\n";
        cout << "=============================================\n";
        cout << "Pilih menu (0-5): ";

        int pilihan = 5;
        if (!(cin >> pilihan)) {
            cout << "Error: Anda harus memasukkan angka! Coba lagi.\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        switch (pilihan) {
            case 0: tampilkanSemuaData(); break;
            case 1: tampilkanMasterFilmDinamis(); break;
            case 2: tampilkanTabelTiketDinamis(); break;
            case 3: tambahMasterFilm(); break;
            case 4: tambahTiketBaru(); break;
            case 5:
                running = false;
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}