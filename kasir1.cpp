#include <iostream>
#include <string>
#include <windows.h>
#include <unistd.h>

//Ini Untuk Menetapkan harga masing-masing buah, beserta diskonnya

//Harga Mangga
#define harga_mangga 20000
//Diskon Mangga Ketika Beli 10 atau Lebih
#define m10 0.1
//Diskon Mangga Ketika Beli 20 atau Lebih
#define m20 0.2

//Harga Melon
#define harga_melon 45000
//Diskon Melon Ketika Beli 10 atau Lebih
#define me10 0.2
//Diskon Melon Ketika Beli 20 atau Lebih
#define me20 0.3

//Harga Pepaya
#define harga_pepaya 65000
//Diskon Pepaya Ketika Beli 5 atau Lebih
#define p5 0.3
//Diskon Pepaya Ketika Beli 7 atau Lebih
#define p7 0.4

//Harga Semangka
#define harga_semangka 70000
//Diskon Semangka Ketika Beli 3 atau Lebih
#define s3 0.3
//Diskon Semangka Ketika Beli 3 atau Lebih
#define s5 0.4

using namespace std;

//Untuk gotoxy ini hanya untuk tampilan saja tidak usah dihiraukan
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
	//Deklarasi dari codingan
	//Variable Untuk Memilih Jenis Buah = int nomor_buah
	int nomor_buah;

	//Variable Untuk Menentukan Berapa Banyak Jenis Buahnya = int jumlah_item
	int jumlah_item;

	//Variable Untuk Menentukan Berapa Banyak Buah Dari Masing-Masing Jenisnya = int jumlah_masing
	int jumlah_masing;

	//Variable Untuk Menyimpan Harga Sebelum Di Diskon, Total Harga Diskonnya, Harga sesudah di diskon, Dan Total Semua Harga Buah dan Sudah Di Diskon
	float harga_sebelum = 0.0, total_diskon = 0.0, harga_sesudah = 0.0, total_semua;

	cout << "===================================== Toko Buah =====================================" << endl;
	cout << " " << endl;
	//Input Jumlah Jenis Buah ke Variable Jumlah_Item
	cout << "Inputkan Jumlah dari Jenis Buah : ";cin >> jumlah_item;
	//Perulangan Mengisi Buah dan Jumlah Masing-masingnya sebanyak Jumlah Item
	for (int i = 0; i < jumlah_item; i++)
	{
		//Tampilan Daftar Buah
		gotoxy(0, 3);cout << "Pilih Buah Di List ini" << endl;
		gotoxy(0, 4);cout << "=====================================================================================" << endl;
		gotoxy(5, 5); cout << "No";
		gotoxy(17, 5); cout << "Nama Buah";
		gotoxy(41, 5); cout << "Harga Buah/Satuan";
		gotoxy(64, 5); cout << "Keterangan" << endl;
		cout << "=====================================================================================" << endl;
		gotoxy(5, 7); cout << "1";
		gotoxy(17, 7); cout << "Mangga";
		gotoxy(41, 7); cout << "20.000";
		gotoxy(64, 7); cout << "Keterangan" << endl;
		gotoxy(5, 8); cout << "2";
		gotoxy(17, 8); cout << "Melon";
		gotoxy(41, 8); cout << "45.000";
		gotoxy(64, 8); cout << "Keterangan" << endl;
		gotoxy(5, 9); cout << "3";
		gotoxy(17, 9); cout << "Pepaya";
		gotoxy(41, 9); cout << "65.000";
		gotoxy(64, 9); cout << "Keterangan" << endl;
		gotoxy(5, 10); cout << "4";
		gotoxy(17, 10); cout << "Semangka";
		gotoxy(41, 10); cout << "70.000";
		gotoxy(64, 10); cout << "Keterangan" << endl;
		cout << "=====================================================================================" << endl;
		//Masukkan Nomor Buah Untuk Memilih Buah
		cout << "Masukkan Nomor Buah : "; cin >> nomor_buah;
		//Kondisi Jika Buah Yang Dipilih Adalah Mangga	
		if (nomor_buah == 1)
		{
			//Masukkan Jumlah buah ke Variable jumlah_masing
			cout << "Masukkan Jumlah : "; cin >> jumlah_masing;
			//Harga total sebelum di diskon
			harga_sebelum = harga_mangga * jumlah_masing;
			//Kondisi Diskon Jika buah sama dengan 10 dan Lebih dari 10 dan kurang dari 20
			if (jumlah_masing >= 10 && jumlah_masing < 20)
			{
				//total diskon
				total_diskon = harga_sebelum * m10;
			}
			//Kondisi Diskon Jika buah sama dengan 20 dan lebih dari 20
			else if (jumlah_masing >= 20)
			{
				//total diskon
				total_diskon = harga_sebelum * m20;
			}
			//harga sesudah di kurangi diskon
			harga_sesudah = harga_sebelum - total_diskon;
			//Menampilkan harga total sebelum, total diskon, dan harga sesudah di diskon
			cout << "=====================================================================================" << endl;
			cout << "Harga Sebelum              :   " << harga_sebelum << endl;
			cout << "Total Diskon               :   " << total_diskon << endl;
			cout << "Harga Sesudah Di Diskon    :   " << harga_sesudah << endl;
			cout << "=====================================================================================" << endl;
			//untuk kondisi seterusnya berlanjut
		}
		else if (nomor_buah == 2)
		{
			cout << "Masukkan Jumlah : "; cin >> jumlah_masing;
			harga_sebelum = harga_melon * jumlah_masing;
			if (jumlah_masing >= 10 && jumlah_masing < 20)
			{
				total_diskon = harga_sebelum * m10;
			}
			else if (jumlah_masing >= 20)
			{
				total_diskon = harga_sebelum * m20;
			}
			harga_sesudah = harga_sebelum - total_diskon;
			cout << "=====================================================================================" << endl;
			cout << "Harga Sebelum              :   " << harga_sebelum << endl;
			cout << "Total Diskon               :   " << total_diskon << endl;
			cout << "Harga Sesudah Di Diskon    :   " << harga_sesudah << endl;
			cout << "=====================================================================================" << endl;
		}
		else if (nomor_buah == 3)
		{
			cout << "Masukkan Jumlah : "; cin >> jumlah_masing;
			harga_sebelum = harga_pepaya * jumlah_masing;
			if (jumlah_masing >= 5 && jumlah_masing < 7)
			{
				total_diskon = harga_sebelum * p5;
			}
			else if (jumlah_masing >= 7)
			{
				total_diskon = harga_sebelum * p7;
			}
			harga_sesudah = harga_sebelum - total_diskon;
			cout << "=====================================================================================" << endl;
			cout << "Harga Sebelum              :   " << harga_sebelum << endl;
			cout << "Total Diskon               :   " << total_diskon << endl;
			cout << "Harga Sesudah Di Diskon    :   " << harga_sesudah << endl;
			cout << "=====================================================================================" << endl;
		}
		else if (nomor_buah == 4)
		{
			cout << "Masukkan Jumlah : "; cin >> jumlah_masing;
			harga_sebelum = harga_semangka * jumlah_masing;
			if (jumlah_masing >= 3 && jumlah_masing < 5)
			{
				total_diskon = harga_sebelum * s3;
			}
			else if (jumlah_masing >= 5)
			{
				total_diskon = harga_sebelum * s5;
			}
			harga_sesudah = harga_sebelum - total_diskon;
			cout << "=====================================================================================" << endl;
			cout << "Harga Sebelum              :   " << harga_sebelum << endl;
			cout << "Total Diskon               :   " << total_diskon << endl;
			cout << "Harga Sesudah Di Diskon    :   " << harga_sesudah << endl;
			cout << "=====================================================================================" << endl;
		}
		total_semua += harga_sesudah;

		cout << "Tunggu 5 Detik....";
		Sleep(5);
		system("cls");
	}
	//Total Harga Belanjaan
	cout << "==================================================" << endl;
	cout << "Total Harga Belanjaan Anda Adalah :  " << total_semua << endl;
	cout << "==================================================" << endl;


	return 0;
}
