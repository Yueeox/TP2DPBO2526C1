from film import Film
from tiket import Tiket

list_film = []
list_tiket = []
next_film_id = 1
next_tiket_id = 101


def format_rupiah(harga):
    return f"Rp {harga:,}".replace(",", ".")


def buat_tiket_dari_film(f, bioskop, studio, harga, row, seat, tgl, waktu):
    global next_tiket_id
    list_tiket.append(Tiket(
        next_tiket_id, f.get_judul(), f.get_tahun(), f.get_hak_cipta(),
        f.get_genre(), f.get_durasi_menit(), f.get_rumah_produksi(),
        bioskop, studio, harga, row, seat, tgl, waktu
    ))
    next_tiket_id += 1


def init_dummy_data():
    global next_film_id
    list_film.append(Film(next_film_id, "Inception", 2010, "Warner Bros", "Sci-Fi", 148, "Syncopy")); next_film_id += 1
    list_film.append(Film(next_film_id, "Interstellar", 2014, "Paramount", "Sci-Fi", 169, "Lynda Obst")); next_film_id += 1
    list_film.append(Film(next_film_id, "The Dark Knight", 2008, "Warner Bros", "Action", 152, "DC Comics")); next_film_id += 1
    list_film.append(Film(next_film_id, "Avatar: Way of Water", 2022, "20th Century", "Sci-Fi", 192, "Lightstorm")); next_film_id += 1
    list_film.append(Film(next_film_id, "Spirited Away", 2001, "Studio Ghibli", "Anime", 125, "Studio Ghibli")); next_film_id += 1

    buat_tiket_dari_film(list_film[0], "CGV Grand Indonesia", "1", 50000, 'A', 12, "2026-03-25", "14:00")
    buat_tiket_dari_film(list_film[1], "XXI Botani Square", "2", 60000, 'B', 5, "2026-03-25", "17:30")
    buat_tiket_dari_film(list_film[2], "Cinepolis Plaza", "3", 45000, 'C', 10, "2026-03-26", "19:00")
    buat_tiket_dari_film(list_film[3], "IMAX Gandaria", "1", 75000, 'D', 14, "2026-03-26", "20:15")
    buat_tiket_dari_film(list_film[4], "CGV Paris Van Java", "4", 40000, 'E', 8, "2026-03-27", "13:00")


def tampilkan_master_film_dinamis():
    if not list_film:
        print("Belum ada data master film.")
        return

    w_id, w_judul, w_tahun, w_hak, w_genre, w_durasi, w_studio = 2, 10, 5, 9, 5, 6, 14

    for f in list_film:
        w_id = max(w_id, len(str(f.get_id())))
        w_judul = max(w_judul, len(f.get_judul()))
        w_tahun = max(w_tahun, len(str(f.get_tahun())))
        w_hak = max(w_hak, len(f.get_hak_cipta()))
        w_genre = max(w_genre, len(f.get_genre()))
        w_durasi = max(w_durasi, len(f"{f.get_durasi_menit()} Menit"))
        w_studio = max(w_studio, len(f.get_rumah_produksi()))

    line_sep = f"+{'-' * (w_id + 2)}+{'-' * (w_judul + 2)}+{'-' * (w_tahun + 2)}+{'-' * (w_hak + 2)}+{'-' * (w_genre + 2)}+{'-' * (w_durasi + 2)}+{'-' * (w_studio + 2)}+"

    print("\n--- DAFTAR MASTER FILM ---")
    print(line_sep)
    print(f"| {'ID':<{w_id}} | {'Judul Film':<{w_judul}} | {'Tahun':<{w_tahun}} | {'Hak Cipta':<{w_hak}} | {'Genre':<{w_genre}} | {'Durasi':<{w_durasi}} | {'Rumah Produksi':<{w_studio}} |")
    print(line_sep)

    for f in list_film:
        durasi_str = f"{f.get_durasi_menit()} Menit"
        print(f"| {f.get_id():<{w_id}} | {f.get_judul():<{w_judul}} | {f.get_tahun():<{w_tahun}} | {f.get_hak_cipta():<{w_hak}} | {f.get_genre():<{w_genre}} | {durasi_str:<{w_durasi}} | {f.get_rumah_produksi():<{w_studio}} |")
    print(line_sep)


def tambah_master_film():
    global next_film_id
    print("\n--- TAMBAH MASTER FILM BARU ---")
    print(f"ID Film: {next_film_id}")

    judul = input("Judul Film: ")

    while True:
        try:
            tahun = int(input("Tahun Rilis: "))
            if tahun > 0: break
            print("[ERROR] Tahun rilis harus lebih besar dari 0!")
        except ValueError:
            print("Error: Anda harus memasukkan angka! Coba lagi.")

    hak_cipta = input("Hak Cipta: ")
    genre = input("Genre: ")

    while True:
        try:
            durasi = int(input("Durasi (menit): "))
            if durasi > 0: break
            print("[ERROR] Durasi film harus lebih besar dari 0 menit!")
        except ValueError:
            print("Error: Anda harus memasukkan angka! Coba lagi.")

    studio_prod = input("Rumah Produksi: ")

    list_film.append(Film(next_film_id, judul, tahun, hak_cipta, genre, durasi, studio_prod))
    print(f">> Master Film berhasil ditambahkan dengan ID: {next_film_id}")
    next_film_id += 1
    tampilkan_master_film_dinamis()


def tampilkan_tabel_tiket_dinamis():
    if not list_tiket:
        print("Belum ada data tiket.")
        return

    w_id, w_judul, w_tahun, w_genre, w_bioskop, w_studio, w_kursi, w_harga, w_jadwal = 8, 5, 5, 5, 7, 6, 5, 5, 13

    for t in list_tiket:
        studio_out = f"Studio {t.get_studio()}"
        w_id = max(w_id, len(str(t.get_id())))
        w_judul = max(w_judul, len(t.get_judul()))
        w_tahun = max(w_tahun, len(str(t.get_tahun())))
        w_genre = max(w_genre, len(t.get_genre()))
        w_bioskop = max(w_bioskop, len(t.get_nama_tempat()))
        w_studio = max(w_studio, len(studio_out))
        w_harga = max(w_harga, len(format_rupiah(t.get_harga())))
        w_jadwal = max(w_jadwal, len(f"{t.get_tanggal()} {t.get_waktu()}"))

    line_sep = f"+{'-' * (w_id + 2)}+{'-' * (w_judul + 2)}+{'-' * (w_tahun + 2)}+{'-' * (w_genre + 2)}+{'-' * (w_bioskop + 2)}+{'-' * (w_studio + 2)}+{'-' * (w_kursi + 2)}+{'-' * (w_harga + 2)}+{'-' * (w_jadwal + 2)}+"

    print("\n--- DAFTAR TIKET TERSEDIA ---")
    print(line_sep)
    print(f"| {'ID Tiket':<{w_id}} | {'Judul Film':<{w_judul}} | {'Tahun':<{w_tahun}} | {'Genre':<{w_genre}} | {'Bioskop':<{w_bioskop}} | {'Studio':<{w_studio}} | {'Kursi':<{w_kursi}} | {'Harga':<{w_harga}} | {'Jadwal':<{w_jadwal}} |")
    print(line_sep)

    for t in list_tiket:
        studio_out = f"Studio {t.get_studio()}"
        kursi = f"{t.get_row()}{t.get_seat()}"
        jadwal = f"{t.get_tanggal()} {t.get_waktu()}"
        harga_formatted = format_rupiah(t.get_harga())

        print(f"| {t.get_id():<{w_id}} | {t.get_judul():<{w_judul}} | {t.get_tahun():<{w_tahun}} | {t.get_genre():<{w_genre}} | {t.get_nama_tempat():<{w_bioskop}} | {studio_out:<{w_studio}} | {kursi:<{w_kursi}} | {harga_formatted:<{w_harga}} | {jadwal:<{w_jadwal}} |")
    print(line_sep)


def tambah_tiket_baru():
    if not list_film:
        print("Belum ada master film! Tambahkan film terlebih dahulu.")
        return

    tampilkan_master_film_dinamis()

    try:
        id_pilihan = int(input("\nPilih ID Film yang ingin dibeli tiketnya: "))
    except ValueError:
        print("ID Film tidak valid!")
        return

    selected_film = next((f for f in list_film if f.get_id() == id_pilihan), None)

    if not selected_film:
        print("ID Film tidak ditemukan!")
        return

    print(f"\n--- INPUT DETAIL TIKET UNTUK FILM: {selected_film.get_judul()} ---")
    print(f"ID Tiket: {next_tiket_id}")

    bioskop = input("Nama Bioskop: ")

    while True:
        studio = input("Studio(1-9): ")
        if len(studio) == 1 and studio != "0" and "1" <= studio <= "9":
            break
        print("[ERROR] Studi tersedia dari 1-9!")

    while True:
        try:
            harga = int(input("Harga (Rp): "))
            if harga > 0: break
            print("[ERROR] Harga tiket harus lebih besar dari 0!")
        except ValueError:
            print("Error: Anda harus memasukkan angka! Coba lagi.")

    while True:
        row_str = input("Baris Kursi (A-J): ").strip().upper()
        if len(row_str) > 0 and 'A' <= row_str[0] <= 'J':
            row = row_str[0]
            break
        print("[ERROR] Baris kursi tidak valid! Hanya diperbolehkan huruf A sampai J.")

    while True:
        try:
            seat = int(input("Nomor Kursi (1-14): "))
            if 1 <= seat <= 14: break
            print("[ERROR] Nomor kursi tidak valid! Hanya diperbolehkan angka 1 sampai 14.")
        except ValueError:
            print("Error: Anda harus memasukkan angka! Coba lagi.")

    while True:
        tgl = input("Tanggal (YYYY-MM-DD): ")
        if len(tgl) == 10: break
        print("[ERROR] Format tanggal harus YYYY-MM-DD (tepat 10 karakter)!")

    while True:
        waktu = input("Waktu (HH:MM): ")
        if len(waktu) == 5: break
        print("[ERROR] Format waktu harus HH:MM (tepat 5 karakter)!")

    buat_tiket_dari_film(selected_film, bioskop, studio, harga, row, seat, tgl, waktu)
    print(f">> Tiket berhasil dibuat dengan ID Tiket: {next_tiket_id - 1} untuk film {selected_film.get_judul()}")
    tampilkan_tabel_tiket_dinamis()


# FUNGSI UTAMA: MENAMPILKAN SELURUH DATA DARI 3 CLASS DALAM SATU TABEL DINAMIS TUNGGAL
def tampilkan_semua_data():
    if not list_tiket:
        print("Belum ada data tiket untuk ditampilkan.")
        return

    headers = [
        "ID Tiket", "Judul Film", "Tahun", "Hak Cipta", "Genre",
        "Durasi", "Rumah Produksi", "Bioskop", "Studio", "Kursi", "Harga", "Jadwal"
    ]

    widths = [len(h) for h in headers]
    rows = []

    # Format data dan hitung lebar kolom maksimal secara dinamis
    for t in list_tiket:
        row_data = [
            str(t.get_id()),
            t.get_judul(),
            str(t.get_tahun()),
            t.get_hak_cipta(),
            t.get_genre(),
            f"{t.get_durasi_menit()} Menit",
            t.get_rumah_produksi(),
            t.get_nama_tempat(),
            f"Studio {t.get_studio()}",
            f"{t.get_row()}{t.get_seat()}",
            format_rupiah(t.get_harga()),
            f"{t.get_tanggal()} {t.get_waktu()}"
        ]
        rows.append(row_data)

        for i, val in enumerate(row_data):
            widths[i] = max(widths[i], len(val))

    line_sep = "+" + "+".join(["-" * (w + 2) for w in widths]) + "+"

    print("\n--- DATA SELURUH CLASS (MEDIA, FILM, TIKET) DALAM SATU TABEL ---")
    print(line_sep)

    header_str = "| " + " | ".join([f"{headers[i]:<{widths[i]}}" for i in range(len(headers))]) + " |"
    print(header_str)
    print(line_sep)

    for row in rows:
        row_str = "| " + " | ".join([f"{row[i]:<{widths[i]}}" for i in range(len(row))]) + " |"
        print(row_str)

    print(line_sep)


def main():
    init_dummy_data()

    running = True
    while running:
        print("\n=============================================")
        print("     SISTEM MANAJEMEN TIKET FILM (OOP)       ")
        print("=============================================")
        print("| 0. Tampilkan Semua Data                   |")
        print("| 1. Tampilkan Master Film                  |")
        print("| 2. Tampilkan Semua Tiket                  |")
        print("| 3. Tambah Master Film Baru                |")
        print("| 4. Tambah Tiket Baru                      |")
        print("| 5. Keluar                                 |")
        print("=============================================")

        try:
            pilihan_str = input("Pilih menu (0-5): ").strip()
            if not pilihan_str:
                continue
            pilihan = int(pilihan_str)
        except (ValueError, EOFError):
            print("Error: Anda harus memasukkan angka! Coba lagi.\n")
            continue

        if pilihan == 0:
            tampilkan_semua_data()
        elif pilihan == 1:
            tampilkan_master_film_dinamis()
        elif pilihan == 2:
            tampilkan_tabel_tiket_dinamis()
        elif pilihan == 3:
            tambah_master_film()
        elif pilihan == 4:
            tambah_tiket_baru()
        elif pilihan == 5:
            running = False
            print("Terima kasih! Program selesai.")
        else:
            print("Pilihan tidak valid!")


if __name__ == "__main__":
    main()