package JAVA;

public class Media {
    private int id;
    private String judul;
    private int tahun;
    private String hakCipta;
    /* Constructor */
    public Media() {}

    public Media(int id, String judul, int tahun, String hakCipta) {
        this.id = id;
        this.judul = judul;
        this.setTahun(tahun);
        this.hakCipta = hakCipta;
    }
    
    /* Method */
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getJudul() { return judul; }
    public void setJudul(String judul) { this.judul = judul; }

    public int getTahun() { return tahun; }
    public void setTahun(int tahun) {    
        this.tahun = tahun;
    }

    public String getHakCipta() { return hakCipta; }
    public void setHakCipta(String hakCipta) { this.hakCipta = hakCipta; }
}