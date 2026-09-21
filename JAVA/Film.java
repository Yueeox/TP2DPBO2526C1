package JAVA;

public class Film extends Media {
    private String genre;
    private int durasiMenit;
    private String rumahProduksi;
    /* Constractor */
    public Film() {}

    public Film(int id, String judul, int tahun, String hakCipta, String genre, int durasiMenit, String rumahProduksi) {
        super(id, judul, tahun, hakCipta);
        this.genre = genre;
        this.setDurasiMenit(durasiMenit);
        this.rumahProduksi = rumahProduksi;
    }
    /* Method */
    public String getGenre() { return genre; }
    public void setGenre(String genre) { this.genre = genre; }

    public int getDurasiMenit() { return durasiMenit; }
    public void setDurasiMenit(int durasiMenit) {
        this.durasiMenit = Math.max(durasiMenit, 0);
    }

    public String getRumahProduksi() { return rumahProduksi; }
    public void setRumahProduksi(String rumahProduksi) { this.rumahProduksi = rumahProduksi; }
}