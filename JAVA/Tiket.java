package JAVA;

public class Tiket extends Film {
    private String namaTempat;
    private String studio;
    private int harga;
    private char row;
    private int seat;
    private String tanggal;
    private String waktu;
    /* Constractor */
    public Tiket() {}

    public Tiket(int id, String judul, int tahun, String hakCipta, String genre, int durasiMenit, 
                 String rumahProduksi, String namaTempat, String studio, int harga, 
                 char row, int seat, String tanggal, String waktu) {
        super(id, judul, tahun, hakCipta, genre, durasiMenit, rumahProduksi);
        this.namaTempat = namaTempat;
        this.studio = studio;
        this.setHarga(harga);
        this.row = row;
        this.seat = seat;
        this.tanggal = tanggal;
        this.waktu = waktu;
    }
    /* Method */
    public String getNamaTempat() { return namaTempat; }
    public void setNamaTempat(String namaTempat) { this.namaTempat = namaTempat; }

    public String getStudio() { return studio; }
    public void setStudio(String studio) { this.studio = studio; }

    public int getHarga() { return harga; }
    public void setHarga(int harga) {
        this.harga = Math.max(harga, 0);
    }

    public char getRow() { return row; }
    public void setRow(char row) { this.row = row; }

    public int getSeat() { return seat; }
    public void setSeat(int seat) { this.seat = seat; }

    public String getTanggal() { return tanggal; }
    public void setTanggal(String tanggal) { this.tanggal = tanggal; }

    public String getWaktu() { return waktu; }
    public void setWaktu(String waktu) { this.waktu = waktu; }
}