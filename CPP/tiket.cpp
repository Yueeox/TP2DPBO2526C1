#include "Film.cpp"

class Tiket : public Film {
private:
    string namaTempat;
    string studio;
    int harga;
    char row;
    int seat;
    string tanggal;
    string waktu;

public:
    Tiket() : Film(), namaTempat(""), studio(""), harga(0), row(' '), seat(0), tanggal(""), waktu("") {}
    
    Tiket(int id, string judul, int tahun, string hakCipta, string genre, int durasiMenit, 
          string rumahProduksi, string namaTempat, string studio, int harga, 
          char row, int seat, string tanggal, string waktu)
        : Film(id, judul, tahun, hakCipta, genre, durasiMenit, rumahProduksi) {
        this->namaTempat = namaTempat;
        this->studio = studio;
        setHarga(harga);
        this->row = row;
        this->seat = seat;
        this->tanggal = tanggal;
        this->waktu = waktu;
    }

    string getNamaTempat() const { return namaTempat; }
    void setNamaTempat(const string& namaTempat) { this->namaTempat = namaTempat; }

    string getStudio() const { return studio; }
    void setStudio(const string& studio) { this->studio = studio; }

    int getHarga() const { return harga; }
    void setHarga(int harga) { this->harga = max(harga, 0); }

    char getRow() const { return row; }
    void setRow(char row) { this->row = row; }

    int getSeat() const { return seat; }
    void setSeat(int seat) { this->seat = seat; }

    string getTanggal() const { return tanggal; }
    void setTanggal(const string& tanggal) { this->tanggal = tanggal; }

    string getWaktu() const { return waktu; }
    void setWaktu(const string& waktu) { this->waktu = waktu; }
};