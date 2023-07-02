/*Nama	= Khoerul Anam
Nim		= 22040134
Kelas	= 2B*/

#include <iostream>
#include <stdlib.h> //system
#include <windows.h> //gotoxy
#include <conio.h>
using namespace std;

struct Produk{
	int kode;
	string nama;
	int harga;
	int byk;
	int diskon;
	int hardis;
	struct Jual{
		int total;
		int jumlah;
		int hd;
	}jual[7];
}barang[7];


void gotoxy(int x, int y){
	
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void kurang(int a,int b){
	int diskon=a-b;
	cout<<"Maaf Uangnya Kurang : "<<diskon;
}
void kemb(int c,int d){
	int k=c-d;
	gotoxy(53,14);cout<<k<<endl;
}
void sisa(int e, int f){
	int s=e-f;
	cout<<"Kembaliannya adalah : "<<s<<endl;
}

int tampilan(int n){
		gotoxy(25,0);cout<<"| Daftar Harga Barang Di Toko Material |"<<endl;
			gotoxy(3,1);cout<<"==========================================================================="<<endl;
			gotoxy(3,2);cout<<"| NO |       NAMA BARANG       |   KODE BARANG   |   HARGA   |   DISKON   |"<<endl;
			gotoxy(3,3);cout<<"==========================================================================="<<endl;
			for(int i=0;i<8;i++){
			gotoxy(3,4+i);cout<<"|    |                         |                 |           |            |"<<endl;
			}
			gotoxy(3,12);cout<<"==========================================================================="<<endl;
		
//			nomer
				for(int i=0;i<n;++i){
					gotoxy(5,4+i);cout<<i+1<<endl;
					gotoxy(10,4+i);cout<<barang[i].nama<<endl;
					gotoxy(40,4+i);cout<<barang[i].kode<<endl;
  				  	gotoxy(56,4+i);cout<<barang[i].harga<<endl;
  					gotoxy(68,4+i);cout<<barang[i].diskon<<endl;

				}
			//gotoxy(3,30);system("Pause");
}
void sorting(Produk x[],int y){
	for(int i=0;i<y;i++){
		for(int j=0;j<y-i-1;j++){
			if(x[j].kode<x[j+1].kode){
				Produk temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
	for(int i=0;i<y;i++){
			gotoxy(25,14);cout<<"| Daftar Harga Barang Yang Disorting |"<<endl;
			gotoxy(3,15);cout<<"==========================================================================="<<endl;
			gotoxy(3,16);cout<<"| NO |       NAMA BARANG       |   KODE BARANG   |   HARGA   |   DISKON   |"<<endl;
			gotoxy(3,17);cout<<"==========================================================================="<<endl;
			for(int i=0;i<8;i++){
			gotoxy(3,18+i);cout<<"|    |                         |                 |           |            |"<<endl;
			}
			gotoxy(3,26);cout<<"==========================================================================="<<endl;
			
//			nomer
				for(int i=0;i<y;++i){
					gotoxy(5,18+i);cout<<i+1<<endl;
					gotoxy(10,18+i);cout<<barang[i].nama<<endl;
					gotoxy(40,18+i);cout<<barang[i].kode<<endl;
  				  	gotoxy(56,18+i);cout<<barang[i].harga<<endl;
  					gotoxy(68,18+i);cout<<barang[i].diskon<<endl;

				}
			
	}
	
}
//kode warna teks
void merah(){
	cout<<"\033[31m";
}
void hijau(){
	cout<<"\033[32m";
}
void kuning(){
	cout<<"\033[33m";
}
void biru(){
	cout<<"\033[34m";
}
void cyan(){
	cout<<"\033[36m";
}
//closescreen
void reset(){
	cout<<"\033[0m";
}
void cls(){
	system("cls");
}


int main(){
	string nm,nim,kls;
	int sort,n,i,jwb,t=0,kode,d,u,p=0,hd;
	bool ktm=false;
	char sd,lg;
	cout<<"Masukan NIM	: ";getline(cin,nim);
	cout<<"Masukan Nama	: ";getline(cin,nm);
	cout<<"Masukan Kelas	: ";getline(cin,kls);	
	hijau();
	cout<<"Enter Untuk Menu"<<endl;
	system("pause");
	cls();
	reset();

do{
	biru();
	cout<<"\t\t              ----Selamat Datang Di Toko Material----"      <<endl;
	cout<<"\t\t                    ====Menu Toko material==== "            <<endl;
	reset();
	cout<<"\nMenu Kasir"<<endl;
	cout<<"1.Input barang"<<endl;
	cout<<"2.Cek barang"<<endl;
	cout<<"3.Input Belanja"<<endl;
	cout<<"4.cetak nota"<<endl;
	cout<<"Masukan Pilihan Menu = ";cin>>jwb;
	switch (jwb){
		case 1:{
		
			cout<<"Berapa Banyak Barang Yang Akan Diinput (maksimal 7)= ";cin>>n;
			for(i=0 ; i<n ; ++i){
				cout<<"======================="<<endl;
				hijau();
				cout<<"Barang Ke- "<<i+1<<endl;
				reset();
				cout<<"======================="<<endl;
				cout<<"Kode barang = ";cin>>barang[i].kode;
				cin.ignore();
				cout<<"Nama Barang = ";getline(cin,barang[i].nama);

				cout<<"Harga Barang = ";cin>>barang[i].harga;

				cout<<"Diskon = ";cin>>barang[i].diskon;
		
			
			} 
		system("pause");
		system("cls");
			break;
		}
		case 2:{
			//Menampilkan tabel biasa
			cls();
			tampilan(n);
//			menampilkan tabel sorting
			gotoxy(0,13);cout<<" "<<endl;
			sorting(barang,n);	
				gotoxy(3,29);system("pause");
			cls();	
			
			break;
		}
		
		case 3:{
			system("cls");
			cyan();
			cout<<"================="<<endl;
			reset();
			cout<<"KASIR Toko Material"<<endl;

			merah();
			gotoxy(17,1);cout<<"|"<<endl;
			reset();
			cyan();
			cout<<"-----------------"<<endl;
			reset();		
			do{
			
			cout<<"\nINPUT KODE = ";cin>>kode;
			for(i=0;i<n;i++){
				if(kode==barang[i].kode){
					cout<<"Nama Barang : "<<barang[i].nama<<endl;
					cout<<"Harga Barang : "<<barang[i].harga<<endl;
					cout<<"Diskon = "<<barang[i].diskon<<endl;
					barang[i].hardis=barang[i].harga-barang[i].diskon;
					cout<<"Berapa Banyak =";cin>>barang[i].byk;
					barang[i].jual[i].jumlah=barang[i].hardis * barang[i].byk;
					cout<<"Total = "<<barang[i].jual[i].jumlah<<endl;
					t=t+barang[i].jual[i].jumlah;
					hd=barang[i].diskon*barang[i].byk;
					d=d+hd;
				}
			}
			if(t == 0){
				merah();
				cout<<"Kode Tidak Ada"<<endl;
				reset();		
			}else{
				hijau();
				cout<<"Kode Ada"<<endl;
				reset();
			}
		//	getch();
			cin.ignore();
			cout<<"Apa Ada Barang Belanja Lagi ?Y/T ";cin>>lg;
			if(lg=='N'||lg=='n'){ktm==true;}
		}while(lg=='Y'||lg=='y');
			cout<<"Totalnya adalah = "<<t<<endl;
			cout<<"Anda Hemat Sebesar ="<<d<<endl;
			cin.ignore();
			cout<<"INPUT UANG TUNAI = ";cin>>u;
			while(u<t){
				kurang(t,u);
				cout<<"\nMasukan Uang Lagi = ";cin>>u;
					
			}
			sisa(u,t);
			system("pause");
			cls();
			break;
		}
		case 4:{
			system("cls");
			kemb(u,t);
			merah();
			gotoxy(23,0);cout<<" NOTA BELANJA"<<endl;
			biru();
			gotoxy(25,1);cout<<"Toko Material"<<endl;
			reset();
			gotoxy(2,2);cout<<"=============================================================="<<endl;
			gotoxy(2,3);cout<<"| NO |       NAMA BARANG           |   BANYAK   |    HARGA   |"<<endl;
			gotoxy(2,4);cout<<"=============================================================="<<endl;
			for(i=0;i<8;i++){
			gotoxy(2,5+i);cout<<"|    |                             |            |            |"<<endl;
			}
			gotoxy(2,12);cout<<"=============================================================="<<endl;
			gotoxy(2,13);cout<<"|                                  TOTAL HARGA  |            |"<<endl;
			gotoxy(2,14);cout<<"|                                    KEMBALIAN  |            |"<<endl;
			gotoxy(2,15);cout<<"|                                   UANG TUNAI  |            |"<<endl;
			gotoxy(2,16);cout<<"|                                       DISKON  |            |"<<endl;
			gotoxy(2,17);cout<<"=============================================================="<<endl;
			gotoxy(53,13);cout<<t<<endl;
			kemb(u,t);
			gotoxy(53,15);cout<<u;
			gotoxy(53,16);cout<<d<<endl;		
			

				for(i=0;i<n;++i){
					if(barang[i].byk != 0){
				//	gotoxy(4,5+i);cout<<i+1<<endl;
					gotoxy(10,5+i);cout<<barang[i].nama<<endl;
					gotoxy(40,5+i);cout<<barang[i].byk<<endl;
  				  	gotoxy(55,5+i);cout<<barang[i].harga<<endl;
					}
			
				}
			gotoxy(0,19);system("pause");
		ktm=true;
			break;
		}
		default:ktm=true;
	}

}while(ktm==false);
merah();
cout<<"TERIMA KASIH"<<endl;
reset();
cout<<"Nim		: "<<nim<<endl;
cout<<"Nama		: "<<nm<<endl;
cout<<"Kelas		: "<<kls<<endl;

}
