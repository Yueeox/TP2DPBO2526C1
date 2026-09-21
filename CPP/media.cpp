#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Media {
protected:
    int id;
    string judul;
    int tahun;
    string hakCipta;

public:
    Media() : id(0), judul(""), tahun(0), hakCipta("") {}
    
    Media(int id, string judul, int tahun, string hakCipta) {
        this->id = id;
        this->judul = judul;
        setTahun(tahun);
        this->hakCipta = hakCipta;
    }
    
    virtual ~Media() {}

    int getId() const { return id; }
    void setId(int id) { this->id = id; }

    string getJudul() const { return judul; }
    void setJudul(const string& judul) { this->judul = judul; }

    int getTahun() const { return tahun; }
    void setTahun(int tahun) { this->tahun = max(tahun, 0); }

    string getHakCipta() const { return hakCipta; }
    void setHakCipta(const string& hakCipta) { this->hakCipta = hakCipta; }
};