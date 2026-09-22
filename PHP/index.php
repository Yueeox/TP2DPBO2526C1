<?php
// Impor file class
require_once 'tiket.php';

session_start();

// ==========================================
// INISIALISASI SESSION DATA (5 FILM & 5 TIKET)
// ==========================================

if (!isset($_SESSION['listFilm'])) {
    $_SESSION['nextFilmId'] = 1;
    $_SESSION['listFilm'] = [
        new Film($_SESSION['nextFilmId']++, "Inception", 2010, "Warner Bros", "Sci-Fi", 148, "Syncopy"),
        new Film($_SESSION['nextFilmId']++, "Interstellar", 2014, "Paramount", "Sci-Fi", 169, "Lynda Obst"),
        new Film($_SESSION['nextFilmId']++, "The Dark Knight", 2008, "Warner Bros", "Action", 152, "DC Comics"),
        new Film($_SESSION['nextFilmId']++, "Avatar: Way of Water", 2022, "20th Century", "Sci-Fi", 192, "Lightstorm"),
        new Film($_SESSION['nextFilmId']++, "Spirited Away", 2001, "Studio Ghibli", "Anime", 125, "Studio Ghibli")
    ];
}

if (!isset($_SESSION['listTiket'])) {
    $_SESSION['nextTiketId'] = 101;
    $_SESSION['listTiket'] = [];
    
    $f0 = $_SESSION['listFilm'][0];
    $f1 = $_SESSION['listFilm'][1];
    $f2 = $_SESSION['listFilm'][2];
    $f3 = $_SESSION['listFilm'][3];
    $f4 = $_SESSION['listFilm'][4];
    
    // 5 Dummy Tiket
    $_SESSION['listTiket'][] = new Tiket($_SESSION['nextTiketId']++, $f0->getJudul(), $f0->getTahun(), $f0->getHakCipta(), $f0->getGenre(), $f0->getDurasiMenit(), $f0->getRumahProduksi(), "CGV Grand Indonesia", "1", 50000, 'A', 12, "2026-03-25", "14:00");
    $_SESSION['listTiket'][] = new Tiket($_SESSION['nextTiketId']++, $f1->getJudul(), $f1->getTahun(), $f1->getHakCipta(), $f1->getGenre(), $f1->getDurasiMenit(), $f1->getRumahProduksi(), "XXI Botani Square", "2", 60000, 'B', 5, "2026-03-25", "17:30");
    $_SESSION['listTiket'][] = new Tiket($_SESSION['nextTiketId']++, $f2->getJudul(), $f2->getTahun(), $f2->getHakCipta(), $f2->getGenre(), $f2->getDurasiMenit(), $f2->getRumahProduksi(), "Cinepolis Plaza", "3", 45000, 'C', 10, "2026-03-26", "19:00");
    $_SESSION['listTiket'][] = new Tiket($_SESSION['nextTiketId']++, $f3->getJudul(), $f3->getTahun(), $f3->getHakCipta(), $f3->getGenre(), $f3->getDurasiMenit(), $f3->getRumahProduksi(), "IMAX Gandaria", "1", 75000, 'D', 14, "2026-03-26", "20:15");
    $_SESSION['listTiket'][] = new Tiket($_SESSION['nextTiketId']++, $f4->getJudul(), $f4->getTahun(), $f4->getHakCipta(), $f4->getGenre(), $f4->getDurasiMenit(), $f4->getRumahProduksi(), "CGV Paris Van Java", "4", 40000, 'E', 8, "2026-03-27", "13:00");
}

// Map Gambar berdasarkan ID Film (ID 1-5)
$daftarGambar = [
    1 => 'images/inception.jfif',
    2 => 'images/interstellar.jfif',
    3 => 'images/thedarkknight.jfif',
    4 => 'images/avatar.jfif',
    5 => 'images/spiritedaway.jfif'
];

// Handle Form Submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['action']) && $_POST['action'] === 'tambah_film') {
        $filmBaru = new Film(
            $_SESSION['nextFilmId']++,
            $_POST['judul'],
            (int)$_POST['tahun'],
            $_POST['hakCipta'],
            $_POST['genre'],
            (int)$_POST['durasi'],
            $_POST['rumahProduksi']
        );
        $_SESSION['listFilm'][] = $filmBaru;
    } elseif (isset($_POST['action']) && $_POST['action'] === 'tambah_tiket') {
        $selectedFilm = null;
        foreach ($_SESSION['listFilm'] as $f) {
            if ($f->getId() == $_POST['film_id']) {
                $selectedFilm = $f;
                break;
            }
        }
        if ($selectedFilm) {
            $tiketBaru = new Tiket(
                $_SESSION['nextTiketId']++,
                $selectedFilm->getJudul(),
                $selectedFilm->getTahun(),
                $selectedFilm->getHakCipta(),
                $selectedFilm->getGenre(),
                $selectedFilm->getDurasiMenit(),
                $selectedFilm->getRumahProduksi(),
                $_POST['bioskop'],
                $_POST['studio'],
                (int)$_POST['harga'],
                $_POST['row'],
                (int)$_POST['seat'],
                $_POST['tanggal'],
                $_POST['waktu']
            );
            $_SESSION['listTiket'][] = $tiketBaru;
        }
    }
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Sistem Manajemen Tiket Film</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; background-color: #f4f6f9; }
        h1, h2 { color: #333; }
        .container { display: flex; gap: 20px; margin-bottom: 25px; }
        .card { background: white; padding: 20px; border-radius: 8px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); flex: 1; }
        
        .film-card { display: flex; align-items: flex-start; gap: 15px; background: white; padding: 15px; border-radius: 8px; margin-bottom: 15px; box-shadow: 0 2px 4px rgba(0,0,0,0.05); }
        .film-poster { width: 100px; height: 140px; object-fit: cover; border-radius: 8px; border: 1px solid #ddd; }
        .film-info { flex: 1; }
        .film-info h3 { margin: 0 0 8px 0; color: #007bff; }
        .film-info p { margin: 3px 0; font-size: 14px; color: #555; }
        
        table { width: 100%; border-collapse: collapse; margin-top: 10px; background: white; }
        th, td { border: 1px solid #ddd; padding: 10px 12px; text-align: left; }
        th { background-color: #007bff; color: white; }
        tr:nth-child(even) { background-color: #f9f9f9; }
        
        .form-group { margin-bottom: 10px; }
        label { display: block; margin-bottom: 3px; font-weight: bold; }
        input, select { width: 100%; padding: 6px; box-sizing: border-box; }
        button { background-color: #28a745; color: white; border: none; padding: 8px 15px; cursor: pointer; border-radius: 4px; }
        button:hover { background-color: #218838; }
    </style>
</head>
<body>

    <h1>Sistem Manajemen Tiket Film</h1>

    <div class="container">
        <!-- Form Tambah Film -->
        <div class="card">
            <h2>Tambah Master Film</h2>
            <form method="POST">
                <input type="hidden" name="action" value="tambah_film">
                <div class="form-group"><label>Judul Film</label><input type="text" name="judul" required></div>
                <div class="form-group"><label>Tahun Rilis</label><input type="number" name="tahun" min="1" required></div>
                <div class="form-group"><label>Hak Cipta</label><input type="text" name="hakCipta" required></div>
                <div class="form-group"><label>Genre</label><input type="text" name="genre" required></div>
                <div class="form-group"><label>Durasi (Menit)</label><input type="number" name="durasi" min="1" required></div>
                <div class="form-group"><label>Rumah Produksi</label><input type="text" name="rumahProduksi" required></div>
                <button type="submit">Tambah Film</button>
            </form>
        </div>

        <!-- Form Tambah Tiket -->
        <div class="card">
            <h2>Tambah Tiket Baru</h2>
            <form method="POST">
                <input type="hidden" name="action" value="tambah_tiket">
                <div class="form-group">
                    <label>Pilih Film</label>
                    <select name="film_id" required>
                        <?php foreach ($_SESSION['listFilm'] as $f): ?>
                            <option value="<?= $f->getId() ?>"><?= $f->getJudul() ?> (<?= $f->getTahun() ?>)</option>
                        <?php endforeach; ?>
                    </select>
                </div>
                <div class="form-group"><label>Nama Bioskop</label><input type="text" name="bioskop" required></div>
                <div class="form-group"><label>Studio (1-9)</label><input type="number" name="studio" min="1" max="9" required></div>
                <div class="form-group"><label>Harga (Rp)</label><input type="number" name="harga" min="1" required></div>
                <div class="form-group"><label>Baris (A-J)</label><input type="text" name="row" maxlength="1" pattern="[A-Ja-j]" required></div>
                <div class="form-group"><label>Nomor Kursi (1-14)</label><input type="number" name="seat" min="1" max="14" required></div>
                <div class="form-group"><label>Tanggal</label><input type="date" name="tanggal" required></div>
                <div class="form-group"><label>Waktu</label><input type="time" name="waktu" required></div>
                <button type="submit">Buat Tiket</button>
            </form>
        </div>
    </div>

    <!-- DAFTAR FILM BESERTA POSTER GAMBAR -->
    <h2>Daftar Master Film</h2>
    <?php if (empty($_SESSION['listFilm'])): ?>
        <p>Tidak ada data film.</p>
    <?php else: ?>
        <?php foreach ($_SESSION['listFilm'] as $film): ?>
            <?php 
                $id = $film->getId();
                $pathGambar = isset($daftarGambar[$id]) ? $daftarGambar[$id] : '';
                $adaGambar = !empty($pathGambar) && file_exists($pathGambar);
            ?>
            <div class="film-card">
                <?php if ($adaGambar): ?>
                    <div style="flex-shrink: 0;">
                        <img src="<?= $pathGambar ?>" alt="Poster Film" class="film-poster">
                    </div>
                <?php endif; ?>

                <div class="film-info">
                    <h3>[ID: <?= $film->getId() ?>] <?= htmlspecialchars($film->getJudul()) ?> (<?= $film->getTahun() ?>)</h3>
                    <p><strong>Genre:</strong> <?= htmlspecialchars($film->getGenre()) ?></p>
                    <p><strong>Durasi:</strong> <?= $film->getDurasiMenit() ?> Menit</p>
                    <p><strong>Rumah Produksi:</strong> <?= htmlspecialchars($film->getRumahProduksi()) ?></p>
                    <p><strong>Hak Cipta:</strong> <?= htmlspecialchars($film->getHakCipta()) ?></p>
                </div>
            </div>
        <?php endforeach; ?>
    <?php endif; ?>

    <!-- TABEL TIKET -->
    <h2>Daftar Tiket Tersedia</h2>
    <table>
        <thead>
            <tr>
                <th>ID Tiket</th><th>Judul Film</th><th>Tahun</th><th>Genre</th><th>Bioskop</th><th>Studio</th><th>Kursi</th><th>Harga</th><th>Jadwal</th>
            </tr>
        </thead>
        <tbody>
            <?php if (empty($_SESSION['listTiket'])): ?>
                <tr><td colspan="9" style="text-align:center;">Belum ada tiket tersedia.</td></tr>
            <?php else: ?>
                <?php foreach ($_SESSION['listTiket'] as $t): ?>
                <tr>
                    <td><?= $t->getId() ?></td>
                    <td><?= htmlspecialchars($t->getJudul()) ?></td>
                    <td><?= $t->getTahun() ?></td>
                    <td><?= htmlspecialchars($t->getGenre()) ?></td>
                    <td><?= htmlspecialchars($t->getNamaTempat()) ?></td>
                    <td>Studio <?= htmlspecialchars($t->getStudio()) ?></td>
                    <td><?= strtoupper($t->getRow() . $t->getSeat()) ?></td>
                    <td>Rp <?= number_format($t->getHarga(), 0, ',', '.') ?></td>
                    <td><?= $t->getTanggal() . ' ' . $t->getWaktu() ?></td>
                </tr>
                <?php endforeach; ?>
            <?php endif; ?>
        </tbody>
    </table>

</body>
</html>