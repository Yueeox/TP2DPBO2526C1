<?php

class Media {
    protected int $id;
    protected string $judul;
    protected int $tahun;
    protected string $hakCipta;

    public function __construct(int $id = 0, string $judul = "", int $tahun = 0, string $hakCipta = "") {
        $this->id = $id;
        $this->judul = $judul;
        $this->setTahun($tahun);
        $this->hakCipta = $hakCipta;
    }

    public function getId(): int { return $this->id; }
    public function setId(int $id): void { $this->id = $id; }

    public function getJudul(): string { return $this->judul; }
    public function setJudul(string $judul): void { $this->judul = $judul; }

    public function getTahun(): int { return $this->tahun; }
    public function setTahun(int $tahun): void { $this->tahun = max($tahun, 0); }

    public function getHakCipta(): string { return $this->hakCipta; }
    public function setHakCipta(string $hakCipta): void { $this->hakCipta = $hakCipta; }
}