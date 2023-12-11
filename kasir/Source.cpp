#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Fungsi untuk mengatur posisi kursor pada jendela konsol
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

int main()
{
    // Deklarasi variabel
    int jumlah_item;
    float harga_sebelum = 0.0, total_diskon = 0.0, harga_sesudah = 0.0, total_semua = 0.0;

    // Menampilkan header
    cout << "===================================== Toko Buah =====================================" << endl;
    cout << " " << endl;

    // Memasukkan jumlah jenis buah
    cout << "Inputkan Jumlah dari Jenis Buah : ";
    cin >> jumlah_item;

    // Loop untuk memproses setiap jenis buah
    for (int i = 0; i < jumlah_item; i++)
    {
        // Menampilkan daftar buah
        gotoxy(0, 3);
        cout << "Pilih Buah Di List ini" << endl;
        cout << "=====================================================================================" << endl;
        cout << "No\tNama Buah\tHarga Buah/Satuan\tKeterangan" << endl;
        cout << "=====================================================================================" << endl;
        cout << "1\tMangga\t\t20.000\t\t\tKeterangan" << endl;
        cout << "2\tMelon\t\t45.000\t\t\tKeterangan" << endl;
        cout << "3\tPepaya\t\t65.000\t\t\tKeterangan" << endl;
        cout << "4\tSemangka\t70.000\t\t\tKeterangan" << endl;
        cout << "=====================================================================================" << endl;

        // Memasukkan nomor buah
        int nomor_buah;
        cout << "Masukkan Nomor Buah : ";
        cin >> nomor_buah;

        // Memasukkan jumlah buah
        int jumlah_masing;
        cout << "Masukkan Jumlah : ";
        cin >> jumlah_masing;

        // Menghitung harga sebelum diskon berdasarkan buah yang dipilih
        switch (nomor_buah)
        {
        case 1:
            harga_sebelum = 20000 * jumlah_masing;
            total_diskon = (jumlah_masing >= 20) ? harga_sebelum * 0.2 : (jumlah_masing >= 10) ? harga_sebelum * 0.1 : 0;
            break;
        case 2:
            harga_sebelum = 45000 * jumlah_masing;
            total_diskon = (jumlah_masing >= 20) ? harga_sebelum * 0.3 : (jumlah_masing >= 10) ? harga_sebelum * 0.2 : 0;
            break;
        case 3:
            harga_sebelum = 65000 * jumlah_masing;
            total_diskon = (jumlah_masing >= 7) ? harga_sebelum * 0.4 : (jumlah_masing >= 5) ? harga_sebelum * 0.3 : 0;
            break;
        case 4:
            harga_sebelum = 70000 * jumlah_masing;
            total_diskon = (jumlah_masing >= 5) ? harga_sebelum * 0.4 : (jumlah_masing >= 3) ? harga_sebelum * 0.3 : 0;
            break;
        default:
            cout << "Nomor buah tidak valid." << endl;
            continue; // Lewati iterasi berikutnya dalam loop
        }

        // Menghitung harga setelah diskon
        harga_sesudah = harga_sebelum - total_diskon;

        // Menampilkan detail transaksi
        cout << "=====================================================================================" << endl;
        cout << "Harga Sebelum              :   " << harga_sebelum << endl;
        cout << "Total Diskon               :   " << total_diskon << endl;
        cout << "Harga Sesudah Di Diskon    :   " << harga_sesudah << endl;
        cout << "=====================================================================================" << endl;

        // Mengakumulasikan total biaya untuk semua transaksi
        total_semua += harga_sesudah;

        // Menampilkan pesan dan menunggu 5 detik sebelum membersihkan layar untuk iterasi berikutnya
        cout << "Tunggu 5 Detik....";
        Sleep(5000); // Tidur selama 5 detik
        system("cls"); // Bersihkan layar konsol
    }

    // Menampilkan total biaya untuk semua transaksi
    cout << "==================================================" << endl;
    cout << "Total Harga Belanjaan Anda Adalah :  " << total_semua << endl;
    cout << "==================================================" << endl;

    return 0;
}
