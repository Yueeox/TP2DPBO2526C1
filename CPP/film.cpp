#include "Media.cpp"

class Film : public Media {
protected:
    string genre;
    int durasiMenit;
    string rumahProduksi;

public:
    Film() : Media(), genre(""), durasiMenit(0), rumahProduksi("") {}
    
    Film(int id, string judul, int tahun, string hakCipta, string genre, int durasiMenit, string rumahProduksi)
        : Media(id, judul, tahun, hakCipta) {
        this->genre = genre;
        setDurasiMenit(durasiMenit);
        this->rumahProduksi = rumahProduksi;
    }

    string getGenre() const { return genre; }
    void setGenre(const string& genre) { this->genre = genre; }

    int getDurasiMenit() const { return durasiMenit; }
    void setDurasiMenit(int durasiMenit) { this->durasiMenit = max(durasiMenit, 0); }

    string getRumahProduksi() const { return rumahProduksi; }
    void setRumahProduksi(const string& rumahProduksi) { this->rumahProduksi = rumahProduksi; }
};