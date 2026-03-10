#include <stdio.h>
#include <string.h>
#include <ctype.h> // Diperlukan untuk fungsi tolower

// Fungsi untuk mengonversi string menjadi huruf kecil (case-insensitive comparison)
void toLowerStr(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char type_input[20];
    int seat_number;
    char departure_time_input[20];
    char destination_input[20];
    
    int ticket_price = 0;
    int max_seats = 0;
    char kbt_type_display[20]; // Untuk menyimpan jenis KBT yang akan ditampilkan

    printf("Selamat datang di Sistem Pemesanan Tiket KBT\n");
    
    // Input jenis KBT
    printf("Masukkan jenis KBT (Executive/Ekonomi): ");
    if (scanf("%19s", type_input) != 1) {
        printf("Error: Gagal membaca jenis KBT.\n");
        return 1;
    }
    // Bersihkan buffer input
    while (getchar() != '\n'); 

    // Input tujuan
    printf("Masukkan tujuan perjalanan (contoh: Medan): ");
    if (scanf("%19s", destination_input) != 1) {
        printf("Error: Gagal membaca tujuan.\n");
        return 1;
    }
    // Bersihkan buffer input
    while (getchar() != '\n');

    // Input nomor kursi
    printf("Masukkan nomor kursi: ");
    if (scanf("%d", &seat_number) != 1) {
        printf("Error: Gagal membaca nomor kursi.\n");
        return 1;
    }
    // Bersihkan buffer input
    while (getchar() != '\n');

    // Input jam keberangkatan
    printf("Masukkan jam keberangkatan (contoh: 08.00wib): ");
    if (scanf("%19s", departure_time_input) != 1) {
        printf("Error: Gagal membaca jam keberangkatan.\n");
        return 1;
    }
    // Bersihkan buffer input
    while (getchar() != '\n');
    
    // Normalisasi input (mengubah ke huruf kecil) untuk perbandingan yang fleksibel
    toLowerStr(type_input);
    toLowerStr(destination_input);

    // Menentukan jenis KBT dan validasi nomor kursi
    if (strcmp(type_input, "executive") == 0) {
        strcpy(kbt_type_display, "Executive");
        max_seats = 11;
        if (seat_number < 1 || seat_number > max_seats) {
            printf("Error: Nomor kursi %d tidak valid untuk KBT Executive. Pilihan kursi antara 1 dan %d.\n", seat_number, max_seats);
            return 1;
        }
    } else if (strcmp(type_input, "ekonomi") == 0) {
        strcpy(kbt_type_display, "Ekonomi");
        max_seats = 15;
        if (seat_number < 1 || seat_number > max_seats) {
            printf("Error: Nomor kursi %d tidak valid untuk KBT Ekonomi. Pilihan kursi antara 1 dan %d.\n", seat_number, max_seats);
            return 1;
        }
    } else {
        printf("Error: Jenis KBT tidak valid. Pilihan yang tersedia: Executive atau Ekonomi.\n");
        return 1;
    }

    // Menentukan harga tiket berdasarkan tujuan (asumsi "Laguboti-Medan" untuk harga ini, dan user menginput "Medan")
    if (strcmp(destination_input, "medan") == 0) {
        if (strcmp(kbt_type_display, "Executive") == 0) {
            ticket_price = 125000;
        } else { // Ekonomi
            ticket_price = 85000;
        }
    } else {
        // Jika tujuan bukan "medan", harga tidak ditentukan dalam spesifikasi
        ticket_price = 0; 
    }

    // Menampilkan output berupa tiket
    printf("\n--- TICKET KOPERASI BINTANG TAPANULI ---\n");
    printf("Jenis KBT        : %s\n", kbt_type_display);
    printf("Nomor Kursi      : %d\n", seat_number);
    printf("Jam Keberangkatan: %s\n", departure_time_input);
    printf("Tujuan           : %s\n", destination_input);
    if (ticket_price > 0) {
        printf("Harga Tiket      : Rp. %d\n", ticket_price);
    } else {
        printf("Harga Tiket      : Belum ditentukan untuk tujuan ini.\n");
    }
    printf("----------------------------------------\n");

    return 0;
}