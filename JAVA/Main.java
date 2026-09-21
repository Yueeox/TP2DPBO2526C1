package JAVA;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static final ArrayList<Film> listFilm = new ArrayList<>();
    private static final ArrayList<Tiket> listTiket = new ArrayList<>();
    private static final Scanner scanner = new Scanner(System.in);

    // Counter otomatis untuk menjamin keunikan ID
    private static int nextFilmId = 1;
    private static int nextTiketId = 101;

    public static void main(String[] args) {
        initDummyData();
        // Perulangan Menu
        boolean running = true;
        while (running) {
            System.out.println("\n=============================================");
            System.out.println("     SISTEM MANAJEMEN TIKET FILM (OOP)       ");
            System.out.println("=============================================");
            System.out.println("| 0. Tampilkan Semua Data                   |");
            System.out.println("| 1. Tampilkan Master Film                  |");
            System.out.println("| 2. Tampilkan Semua Tiket                  |");
            System.out.println("| 3. Tambah Master Film Baru                |");
            System.out.println("| 4. Tambah Tiket Baru                      |");
            System.out.println("| 5. Keluar                                 |");
            System.out.println("=============================================");
            System.out.print("Pilih menu (0-5): ");
            
            int pilihan = 5; // default 5 agar ketika di isikan huruf maka langsung exit
            try {
                pilihan = scanner.nextInt(); // Berpotensi error jika diisi huruf
            } catch (Exception e) {
                System.out.println("Error: Anda harus memasukkan angka! Coba lagi.\n");
                scanner.next(); 
            }

            // Case untuk pilihan menu
            switch (pilihan) {
                
                case 0 -> tampilkanSemuaData();
                case 1 -> tampilkanMasterFilmDinamis();
                case 2 -> tampilkanTabelTiketDinamis();
                case 3 -> tambahMasterFilm(); 
                case 4 -> tambahTiketBaru();
                case 5 -> {
                    running = false;
                    System.out.println("Terima kasih! Program selesai.");
                }
                default -> System.out.println("Pilihan tidak valid!");
            }
        }
    }

    private static void initDummyData() {
        // 5 Dummy Master Film
        listFilm.add(new Film(nextFilmId++, "Inception", 2010, "Warner Bros", "Sci-Fi", 148, "Syncopy"));
        listFilm.add(new Film(nextFilmId++, "Interstellar", 2014, "Paramount", "Sci-Fi", 169, "Lynda Obst"));
        listFilm.add(new Film(nextFilmId++, "The Dark Knight", 2008, "Warner Bros", "Action", 152, "DC Comics"));
        listFilm.add(new Film(nextFilmId++, "Avatar: Way of Water", 2022, "20th Century", "Sci-Fi", 192, "Lightstorm"));
        listFilm.add(new Film(nextFilmId++, "Spirited Away", 2001, "Studio Ghibli", "Anime", 125, "Studio Ghibli"));

        // 5 Dummy Tiket
        buatTiketDariFilm(listFilm.get(0), "CGV Grand Indonesia", "1", 50000, 'A', 12, "2026-03-25", "14:00");
        buatTiketDariFilm(listFilm.get(1), "XXI Botani Square", "2", 60000, 'B', 5, "2026-03-25", "17:30");
        buatTiketDariFilm(listFilm.get(2), "Cinepolis Plaza", "3", 45000, 'C', 10, "2026-03-26", "19:00");
        buatTiketDariFilm(listFilm.get(3), "IMAX Gandaria", "1", 75000, 'D', 14, "2026-03-26", "20:15");
        buatTiketDariFilm(listFilm.get(4), "CGV Paris Van Java", "4", 40000, 'E', 8, "2026-03-27", "13:00");
    }

    // otomatis membuat tiket dari data film yang sudah ada
    private static void buatTiketDariFilm(Film f, String bioskop, String studio, int harga, char row, int seat, String tgl, String waktu) {
        listTiket.add(new Tiket(
            nextTiketId++, f.getJudul(), f.getTahun(), f.getHakCipta(),
            f.getGenre(), f.getDurasiMenit(), f.getRumahProduksi(),
            bioskop, studio, harga, row, seat, tgl, waktu
        ));
    }

    // untuk menampilkan data film secara dinamis
    private static void tampilkanMasterFilmDinamis() {
        if (listFilm.isEmpty()) {
            System.out.println("Belum ada data master film.");
            return;
        }

        int wId = 2, wJudul = 10, wTahun = 5, wHakCipta = 9, wGenre = 5, wDurasi = 6, wStudio = 14;

        for (Film f : listFilm) {
            wId = Math.max(wId, String.valueOf(f.getId()).length());
            wJudul = Math.max(wJudul, f.getJudul().length());
            wTahun = Math.max(wTahun, String.valueOf(f.getTahun()).length());
            wHakCipta = Math.max(wHakCipta, f.getHakCipta().length());
            wGenre = Math.max(wGenre, f.getGenre().length());
            wDurasi = Math.max(wDurasi, (f.getDurasiMenit() + " Menit").length());
            wStudio = Math.max(wStudio, f.getRumahProduksi().length());
        }

        String formatHeader = "| %-" + wId + "s | %-" + wJudul + "s | %-" + wTahun + "s | %-" + wHakCipta + "s | %-" + wGenre + "s | %-" + wDurasi + "s | %-" + wStudio + "s |\n";
        String lineSeparator = "+" + "-".repeat(wId + 2) + "+" + "-".repeat(wJudul + 2) + "+" + "-".repeat(wTahun + 2) + "+" + "-".repeat(wHakCipta + 2) + "+" + "-".repeat(wGenre + 2) + "+" + "-".repeat(wDurasi + 2) + "+" + "-".repeat(wStudio + 2) + "+";

        System.out.println("\n--- DAFTAR MASTER FILM ---");
        System.out.println(lineSeparator);
        System.out.printf(formatHeader, "ID", "Judul Film", "Tahun", "Hak Cipta", "Genre", "Durasi", "Rumah Produksi");
        System.out.println(lineSeparator);

        for (Film f : listFilm) {
            String durasiStr = f.getDurasiMenit() + " Menit";
            System.out.printf(formatHeader, f.getId(), f.getJudul(), f.getTahun(), f.getHakCipta(), f.getGenre(), durasiStr, f.getRumahProduksi());
        }
        System.out.println(lineSeparator);
    }
    
    // menambahkan film baru
    private static void tambahMasterFilm() {
        System.out.println("\n--- TAMBAH MASTER FILM BARU ---");
        System.out.println("ID Film: " + nextFilmId);
        
        System.out.print("Judul Film: "); String judul = scanner.nextLine();

        int tahun;
        while (true) {
            System.out.print("Tahun Rilis: ");
            tahun = scanner.nextInt();
            if (tahun > 0) break;
            System.out.println("[ERROR] Tahun rilis harus lebih besar dari 0!");
        }
        scanner.nextLine();

        System.out.print("Hak Cipta: "); String hakCipta = scanner.nextLine();
        System.out.print("Genre: "); String genre = scanner.nextLine();

        int durasi;
        while (true) {
            System.out.print("Durasi (menit): ");
            durasi = scanner.nextInt();
            if (durasi > 0) break;
            System.out.println("[ERROR] Durasi film harus lebih besar dari 0 menit!");
        }
        scanner.nextLine();

        System.out.print("Rumah Produksi: "); String studioProd = scanner.nextLine();

        listFilm.add(new Film(nextFilmId++, judul, tahun, hakCipta, genre, durasi, studioProd));
        System.out.println(">> Master Film berhasil ditambahkan dengan ID: " + (nextFilmId - 1));
        // menampilkan langsung film yang baru di tambahkan
        tampilkanMasterFilmDinamis();
    }

    // menambahkan tiket baru
    private static void tambahTiketBaru() {
        if (listFilm.isEmpty()) {
            System.out.println("Belum ada master film! Tambahkan film terlebih dahulu.");
            return;
        }

        tampilkanMasterFilmDinamis();
        System.out.print("\nPilih ID Film yang ingin dibeli tiketnya: ");
        int idPilihan = scanner.nextInt(); scanner.nextLine();

        Film selectedFilm = null;
        for (Film f : listFilm) {
            if (f.getId() == idPilihan) {
                selectedFilm = f;
                break;
            }
        }

        if (selectedFilm == null) {
            System.out.println("ID Film tidak ditemukan!");
            return;
        }

        System.out.println("\n--- INPUT DETAIL TIKET UNTUK FILM: " + selectedFilm.getJudul() + " ---");
        System.out.println("ID Tiket: " + nextTiketId);
        
        System.out.print("Nama Bioskop: "); String bioskop = scanner.nextLine();
        //System.out.print("Studio(1-9): "); String studio = scanner.nextLine();

        // agar inputan user benar
        // kita akan pastikan bahwa inputan sesuai
        String studio;
        while (true) {
            System.out.print("Studio(1-9): ");
            studio = scanner.nextLine();
            if ((studio.length() > 0) && (studio.length() < 2)){
                if (studio.compareTo("0") != 0){
                    break;
                }
            }
            System.out.println("[ERROR] Studi tersedia dari 1-9!");
        }
        
        // kita akan pastikan bahwa inputan sesuai
        int harga;
        while (true) {
            System.out.print("Harga (Rp): ");
            harga = scanner.nextInt();
            if (harga > 0) break;
            System.out.println("[ERROR] Harga tiket harus lebih besar dari 0!");
        }
        
        // kita akan pastikan bahwa inputan sesuai
        char row;
        while (true) {
            System.out.print("Baris Kursi (A-J): ");
            row = Character.toUpperCase(scanner.next().charAt(0));
            if (row >= 'A' && row <= 'J') break;
            System.out.println("[ERROR] Baris kursi tidak valid! Hanya diperbolehkan huruf A sampai J.");
        }
        
        // kita akan pastikan bahwa inputan sesuai
        int seat;
        while (true) {
            System.out.print("Nomor Kursi (1-14): ");
            seat = scanner.nextInt();
            if (seat >= 1 && seat <= 14) break;
            System.out.println("[ERROR] Nomor kursi tidak valid! Hanya diperbolehkan angka 1 sampai 14.");
        }
        scanner.nextLine();
        
        // kita akan pastikan bahwa inputan sesuai
        String tgl;
        while (true) {
            System.out.print("Tanggal (YYYY-MM-DD): ");
            tgl = scanner.nextLine();
            if (tgl.length() == 10) break;
            System.out.println("[ERROR] Format tanggal harus YYYY-MM-DD (tepat 10 karakter)!");
        }
        
        // kita akan pastikan bahwa inputan sesuai
        String waktu;
        while (true) {
            System.out.print("Waktu (HH:MM): ");
            waktu = scanner.nextLine();
            if (waktu.length() == 5) break;
            System.out.println("[ERROR] Format waktu harus HH:MM (tepat 5 karakter)!");
        }
        
        // membuat film
        buatTiketDariFilm(selectedFilm, bioskop, studio, harga, row, seat, tgl, waktu);
        System.out.println(">> Tiket berhasil dibuat dengan ID Tiket: " + (nextTiketId - 1) + " untuk film " + selectedFilm.getJudul());
        // dan menampilkan tiket yang sudah di tampilkan
        tampilkanTabelTiketDinamis();
    }

    // menampilkan tiket yang dinamis dengan tabel
    private static void tampilkanTabelTiketDinamis() {
        if (listTiket.isEmpty()) {
            System.out.println("Belum ada data tiket.");
            return;
        }

        int wId = 8, wJudul = 5, wTahun = 5, wGenre = 5, wBioskop = 7, wStudio = 6, wKursi = 5, wHarga = 5, wJadwal = 13;

        for (Tiket t : listTiket) {
            String studioOut = "Studio " + t.getStudio(); // Menggunakan penggabungan String
            
            wId = Math.max(wId, String.valueOf(t.getId()).length());
            wJudul = Math.max(wJudul, t.getJudul().length());
            wTahun = Math.max(wTahun, String.valueOf(t.getTahun()).length());
            wGenre = Math.max(wGenre, t.getGenre().length());
            wBioskop = Math.max(wBioskop, t.getNamaTempat().length());
            wStudio = Math.max(wStudio, studioOut.length());
            wHarga = Math.max(wHarga, String.format("Rp %,d", t.getHarga()).length());
            wJadwal = Math.max(wJadwal, (t.getTanggal() + " " + t.getWaktu()).length());
        }

        String formatHeader = "| %-" + wId + "s | %-" + wJudul + "s | %-" + wTahun + "s | %-" + wGenre + "s | %-" + wBioskop + "s | %-" + wStudio + "s | %-" + wKursi + "s | %-" + wHarga + "s | %-" + wJadwal + "s |\n";
        String lineSeparator = "+" + "-".repeat(wId + 2) + "+" + "-".repeat(wJudul + 2) + "+" + "-".repeat(wTahun + 2) + "+" + "-".repeat(wGenre + 2) + "+" + "-".repeat(wBioskop + 2) + "+" + "-".repeat(wStudio + 2) + "+" + "-".repeat(wKursi + 2) + "+" + "-".repeat(wHarga + 2) + "+" + "-".repeat(wJadwal + 2) + "+";

        System.out.println("\n--- DAFTAR TIKET TERSEDIA ---");
        System.out.println(lineSeparator);
        System.out.printf(formatHeader, "ID Tiket", "Judul Film", "Tahun", "Genre", "Bioskop", "Studio", "Kursi", "Harga", "Jadwal");
        System.out.println(lineSeparator);

        for (Tiket t : listTiket) {
            String studioOut = "Studio " + t.getStudio();
            String kursi = t.getRow() + String.valueOf(t.getSeat());
            String jadwal = t.getTanggal() + " " + t.getWaktu();
            String hargaFormatted = String.format("Rp %,d", t.getHarga());

            System.out.printf(formatHeader, t.getId(), t.getJudul(), t.getTahun(), t.getGenre(), t.getNamaTempat(), studioOut, kursi, hargaFormatted, jadwal);
        }
        System.out.println(lineSeparator);
    }

    // menampilkan semua data
    private static void tampilkanSemuaData(){
        tampilkanTabelTiketDinamis();
        tampilkanMasterFilmDinamis();
    }
}