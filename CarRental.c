// Bagian Priji

// Bagian Nabil

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
