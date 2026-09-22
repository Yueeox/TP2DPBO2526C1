<?php

require_once 'Media.php';

class Film extends Media {
    protected string $genre;
    protected int $durasiMenit;
    protected string $rumahProduksi;

    public function __construct(
        int $id = 0, 
        string $judul = "", 
        int $tahun = 0, 
        string $hakCipta = "", 
        string $genre = "", 
        int $durasiMenit = 0, 
        string $rumahProduksi = ""
    ) {
        parent::__construct($id, $judul, $tahun, $hakCipta);
        $this->genre = $genre;
        $this->setDurasiMenit($durasiMenit);
        $this->rumahProduksi = $rumahProduksi;
    }

    public function getGenre(): string { return $this->genre; }
    public function setGenre(string $genre): void { $this->genre = $genre; }

    public function getDurasiMenit(): int { return $this->durasiMenit; }
    public function setDurasiMenit(int $durasiMenit): void { $this->durasiMenit = max($durasiMenit, 0); }

    public function getRumahProduksi(): string { return $this->rumahProduksi; }
    public function setRumahProduksi(string $rumahProduksi): void { $this->rumahProduksi = $rumahProduksi; }
}