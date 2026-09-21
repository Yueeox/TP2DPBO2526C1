from media import Media

class Film(Media):
    def __init__(self, media_id=0, judul="", tahun=0, hak_cipta="", genre="", durasi_menit=0, rumah_produksi=""):
        super().__init__(media_id, judul, tahun, hak_cipta)
        self._genre = genre
        self.set_durasi_menit(durasi_menit)
        self._rumah_produksi = rumah_produksi

    def get_genre(self): return self._genre
    def set_genre(self, genre): self._genre = genre

    def get_durasi_menit(self): return self._durasi_menit
    def set_durasi_menit(self, durasi_menit): self._durasi_menit = max(durasi_menit, 0)

    def get_rumah_produksi(self): return self._rumah_produksi
    def set_rumah_produksi(self, rumah_produksi): self._rumah_produksi = rumah_produksi