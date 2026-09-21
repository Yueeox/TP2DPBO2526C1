from film import Film

class Tiket(Film):
    def __init__(self, media_id=0, judul="", tahun=0, hak_cipta="", genre="", durasi_menit=0,
                 rumah_produksi="", nama_tempat="", studio="", harga=0, row='', seat=0, tanggal="", waktu=""):
        super().__init__(media_id, judul, tahun, hak_cipta, genre, durasi_menit, rumah_produksi)
        self._nama_tempat = nama_tempat
        self._studio = studio
        self.set_harga(harga)
        self._row = row
        self._seat = seat
        self._tanggal = tanggal
        self._waktu = waktu

    def get_nama_tempat(self): return self._nama_tempat
    def set_nama_tempat(self, nama_tempat): self._nama_tempat = nama_tempat

    def get_studio(self): return self._studio
    def set_studio(self, studio): self._studio = studio

    def get_harga(self): return self._harga
    def set_harga(self, harga): self._harga = max(harga, 0)

    def get_row(self): return self._row
    def set_row(self, row): self._row = row

    def get_seat(self): return self._seat
    def set_seat(self, seat): self._seat = seat

    def get_tanggal(self): return self._tanggal
    def set_tanggal(self, tanggal): self._tanggal = tanggal

    def get_waktu(self): return self._waktu
    def set_waktu(self, waktu): self._waktu = waktu