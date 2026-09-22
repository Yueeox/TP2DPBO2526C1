<?php

require_once 'Film.php';

class Tiket extends Film {
    private string $namaTempat;
    private string $studio;
    private int $harga;
    private string $row;
    private int $seat;
    private string $tanggal;
    private string $waktu;

    public function __construct(
        int $id = 0, 
        string $judul = "", 
        int $tahun = 0, 
        string $hakCipta = "", 
        string $genre = "", 
        int $durasiMenit = 0, 
        string $rumahProduksi = "",
        string $namaTempat = "", 
        string $studio = "", 
        int $harga = 0, 
        string $row = "", 
        int $seat = 0, 
        string $tanggal = "", 
        string $waktu = ""
    ) {
        parent::__construct($id, $judul, $tahun, $hakCipta, $genre, $durasiMenit, $rumahProduksi);
        $this->namaTempat = $namaTempat;
        $this->studio = $studio;
        $this->setHarga($harga);
        $this->row = $row;
        $this->seat = $seat;
        $this->tanggal = $tanggal;
        $this->waktu = $waktu;
    }

    public function getNamaTempat(): string { return $this->namaTempat; }
    public function setNamaTempat(string $namaTempat): void { $this->namaTempat = $namaTempat; }

    public function getStudio(): string { return $this->studio; }
    public function setStudio(string $studio): void { $this->studio = $studio; }

    public function getHarga(): int { return $this->harga; }
    public function setHarga(int $harga): void { $this->harga = max($harga, 0); }

    public function getRow(): string { return $this->row; }
    public function setRow(string $row): void { $this->row = $row; }

    public function getSeat(): int { return $this->seat; }
    public function setSeat(int $seat): void { $this->seat = $seat; }

    public function getTanggal(): string { return $this->tanggal; }
    public function setTanggal(string $tanggal): void { $this->tanggal = $tanggal; }

    public function getWaktu(): string { return $this->waktu; }
    public function setWaktu(string $waktu): void { $this->waktu = $waktu; }
}