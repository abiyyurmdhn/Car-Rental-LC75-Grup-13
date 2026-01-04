// Bagian Priji
#include <stdio.h>
#include <string.h>

struct Mobil {
    int id;
    char nama[50];
    int harga;
};

void menu_awal();
void menu_owner();
void menu_penyewa();

void tambah_mobil(struct Mobil data[], int *jumlah);
void tampil_mobil(struct Mobil data[], int jumlah);
void urutkan_harga(struct Mobil data[], int jumlah);
void simpan_file(struct Mobil data[], int jumlah);
void baca_file(struct Mobil data[], int *jumlah);

void sewa_mobil(struct Mobil data[], int jumlah);

int main() {
    struct Mobil data_mobil[100];
    int jumlah = 0;
    int pilihan;

    baca_file(data_mobil, &jumlah);

    do {
        menu_awal();
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 1) {
            int kode;
            printf("Masukkan Kode Owner: ");
            scanf("%d", &kode);
            getchar();

            if (kode == 12345) {
                int pilih_owner;
                do {
                    menu_owner();
                    printf("Pilih menu: ");
                    scanf("%d", &pilih_owner);
                    getchar();

                    if (pilih_owner == 1)
                        tambah_mobil(data_mobil, &jumlah);
                    else if (pilih_owner == 2)
                        tampil_mobil(data_mobil, jumlah);
                    else if (pilih_owner == 3)
                        urutkan_harga(data_mobil, jumlah);
                    else if (pilih_owner == 4)
                        simpan_file(data_mobil, jumlah);
                } while (pilih_owner != 5);
            } else {
                printf("Kode owner salah!\n");
            }
        }

// Bagian Nabil
 else if (pilihan == 2) {
            int pilih_penyewa;
            do {
                menu_penyewa();
                printf("Pilih menu: ");
                scanf("%d", &pilih_penyewa);
                getchar();

                if (pilih_penyewa == 1)
                    tampil_mobil(data_mobil, jumlah);
                else if (pilih_penyewa == 2)
                    sewa_mobil(data_mobil, jumlah);

            } while (pilih_penyewa != 3);
        }

    } while (pilihan != 3);

    return 0;
}

void menu_awal() {
    printf("\n===== SISTEM RENTAL MOBIL =====\n");
    printf("1. Owner\n");
    printf("2. Penyewa\n");
    printf("3. Keluar\n");
}

void menu_owner() {
    printf("\n--- MENU OWNER ---\n");
    printf("1. Tambah Data Mobil\n");
    printf("2. Tampilkan Data Mobil\n");
    printf("3. Urutkan Harga Sewa\n");
    printf("4. Simpan Data ke File\n");
    printf("5. Kembali\n");
}

void menu_penyewa() {
    printf("\n--- MENU PENYEWA ---\n");
    printf("1. Lihat Daftar Mobil\n");
    printf("2. Sewa Mobil\n");
    printf("3. Kembali\n");
}

void tambah_mobil(struct Mobil data[], int *jumlah) {
    printf("Masukkan ID Mobil: ");
    scanf("%d", &data[*jumlah].id);
    getchar();

    printf("Masukkan Nama Mobil: ");
    fgets(data[*jumlah].nama, sizeof(data[*jumlah].nama), stdin);
    data[*jumlah].nama[strcspn(data[*jumlah].nama, "\n")] = '\0';

    printf("Masukkan Harga Sewa per Hari: ");
    scanf("%d", &data[*jumlah].harga);
    getchar();

    (*jumlah)++;
    printf("Data mobil berhasil ditambahkan.\n");
}

// Bagian Abiyyu
void tampil_mobil(struct Mobil data[], int jumlah) {
    printf("\n--- DAFTAR MOBIL ---\n");
    for (int i = 0; i < jumlah; i++) {
        printf("ID: %d | Nama: %s | Harga: %d\n",
               data[i].id, data[i].nama, data[i].harga);
    }
}

void urutkan_harga(struct Mobil data[], int jumlah) {
    struct Mobil temp;
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (data[i].harga > data[j].harga) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan.\n");
}

void simpan_file(struct Mobil data[], int jumlah) {
    FILE *file = fopen("rental_mobil.txt", "w");
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%d;%s;%d\n",
                data[i].id, data[i].nama, data[i].harga);
    }
    fclose(file);
    printf("Data disimpan ke file.\n");
}

void baca_file(struct Mobil data[], int *jumlah) {
    FILE *file = fopen("rental_mobil.txt", "r");
    if (file == NULL) return;

    *jumlah = 0;
    while (fscanf(file, "%d;%49[^;];%d\n",
                  &data[*jumlah].id,
                  data[*jumlah].nama,
                  &data[*jumlah].harga) != EOF) {
        (*jumlah)++;
    }
    fclose(file);
}

void sewa_mobil(struct Mobil data[], int jumlah) {
    int id, hari, total;
    printf("Masukkan ID Mobil yang disewa: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlah; i++) {
        if (data[i].id == id) {
            printf("Nama Mobil: %s\n", data[i].nama);
            printf("Harga per Hari: %d\n", data[i].harga);
            printf("Masukkan jumlah hari sewa: ");
            scanf("%d", &hari);
            total = hari * data[i].harga;
            printf("Total Harga Sewa: %d\n", total);
            return;
        }
    }
    printf("Mobil tidak ditemukan.\n");
}
