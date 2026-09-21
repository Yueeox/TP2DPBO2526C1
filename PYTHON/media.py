class Media:
    def __init__(self, media_id=0, judul="", tahun=0, hak_cipta=""):
        self._id = media_id
        self._judul = judul
        self.set_tahun(tahun)
        self._hak_cipta = hak_cipta

    def get_id(self): return self._id
    def set_id(self, media_id): self._id = media_id

    def get_judul(self): return self._judul
    def set_judul(self, judul): self._judul = judul

    def get_tahun(self): return self._tahun
    def set_tahun(self, tahun): self._tahun = max(tahun, 0)

    def get_hak_cipta(self): return self._hak_cipta
    def set_hak_cipta(self, hak_cipta): self._hak_cipta = hak_cipta