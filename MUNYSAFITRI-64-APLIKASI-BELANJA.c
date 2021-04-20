#include<stdio.h>
#include<string.h>
#include<ctype.h>

int Kembalian(char ,int , int ,int, int );//prototype
void tabel (); //prototype
int pilih (int);
void tabel(){//fungsi menampilkan daftar menu
	printf("\n--------------------------------------------\n");
	printf("+\t|\t\t\t\t   +\n");
	printf("|  No   |   Menu \t\t Harga\t   |\n");
	printf("+\t|\t\t\t\t   + \n");
	printf("--------------------------------------------\n");
	
}

int Kembalian(char jawab,int tot,int money,int back,int back1){//fungsi  menghitung uang sisa dan kembalian
	if(tolower(jawab)=='n'){
		printf("Total belanjaan \t:Rp.%d\n",tot);
		printf("Masukkan uang anda \t:Rp.");
		scanf("%d",&money);
		
		if(money<tot){//Syarat jika uang dompet kurang dari total belanjaan
			
			do{	
				back=tot-money;
				printf("uang anda kurang \t:Rp.%d\n",back);	
				printf("Masukkan uang tambahan  :Rp.");
				scanf("%d",&back1);
				if(back1<back){
					tot=back;
					money=back1;	
				}
			}
			while(back1<back);//terus looping jika uang tambahan kurang dari uang yang diminta
			
			int kembalian=back1-back;
			back=kembalian;	
		}
		else if(tot<money){//syarat jika total belanja kurang dari uang di dompet
			back=money-tot;
		}
		
		printf("Kembalian anda\t\t:Rp.%d",back);			
		getchar();
		getchar();
	}	
}


typedef struct y{//perintah memberikan nama alias dari tipe data
	char *urutan1;
	int cost;
	}belanja;
	
int main(){
	int pilihan,i,pesan,jumlah,total=0,uang,sisa=0,sisa1,kembalian;
	char jawab,jawab1,jawaban;
	char *urutan[7]={"Burger","Miso Ayam","Spagetti","Sate","Kari Ayam","Martabak"};
	int harga[7]={10000,20000,25000,15000,25000,10000};
	
	belanja struk[7];
	for(i=0;i<6;i++){
	
		struk[i].urutan1=urutan[i];
		struk[i].cost=harga[i];
	}
	
	printf("\nSelamat Datang di Restaumumun\n");

	printf("1.Daftar Menu\n2.Belanja\n3.Keluar\n");//menampilkan pilihan
	
	printf("\nPilihan Anda: ");
	scanf("%d",&pilihan);
	
	while(pilihan>3 || pilihan<1){//ketika inputan pilihan>3 atau <1
		printf("\nMaaf, input Anda tidak sesuai!\n");
		printf("Pilihan Anda: ");
		scanf("%d",&pilihan);
	}
	
	switch(pilihan){//percabangan switch
		case 1://jika inputan memilih angka 1, maka akan ditmpilan daftar menu
			tabel();

			for(i=0;i<6;i++){
				printf("|  %i.   |   %s \t\t %d\t   |\n",i+1,struk[i].urutan1,struk[i].cost);//menampilkan daftar menu
			}
			
			printf("--------------------------------------------\n");
			getchar();
			
			printf("Tekan Enter untuk lanjut...\n ");
			getchar();
			do{
			printf("\nApakah anda ingin belanja?(y/n)\n=> ");
			scanf("%c",&jawab);
	
			jawaban=tolower(jawab);
		
			if(jawaban == 'n'){//syarat jika inputan memberi input 'n'
				printf("\nTerima kasih telah berkunjung di toko kami!");
				break;
			}else if(jawab>=0&&jawab<=9){
				printf("\ninput anda salah\n");
				getchar();
				continue;
			}else if((tolower(jawaban)>='a'&& tolower(jawaban)<='z')&&jawaban!='y'){
				printf("\ninput anda salah\n");
				getchar();
				}
			}
			while(jawaban!='n'&& jawaban!='y');
			if(jawaban == 'n'){
				break;
			}
		case 2://jika menginput 2 , maka dijalankan program belanja
			do{
				do{
				printf("\nAnda pesan no berapa:");
				getchar();
				scanf("%d",&pesan);
			
				if(pesan>=7||pesan<=0){
					printf("inputan anda salah\n");
				}else if(pesan>='A'&&pesan <='z'){
					printf("inputan anda salah\n");
				}
				
				}while((pesan<=0||pesan>=7)||(pesan>='A'&&pesan <='z'));//melakukan looping jika pesan <0 atau >7
				
				printf("\nanda ingin pesan berapa jumlah(harus angka): ");
				scanf("%d",&jumlah);
				
				total= total+struk[pesan-1].cost*jumlah;
			
				printf("\nAnda telah memesan %s sebanyak %d \n",struk[pesan-1].urutan1,jumlah);
				getchar();
				
				printf("\ntotal pesanan anda adalah %d\n",total);
				printf("\nKlik Enter untuk lanjut...");
				getchar();
			
				printf("\nApakah anda ingin belanja lagi?(y/n)\n=>");
				scanf("%c",&jawab1);
			
				while(tolower(jawab1)!='n'&&tolower(jawab1)!='y'){
				
					printf("\ninput anda salah\n");
					printf("\nApakah anda ingin belanja lagi?(y/n)\n=>");
					getchar();
					scanf("%c",&jawab1);
				}
			}while(tolower(jawab1)=='y');
			
			Kembalian(jawab1,total,uang,sisa,sisa1);
				
		case 3://program berakhir saat user menginput 3
			printf("\nTerima Kasih telah berkunjung ke toko kami!\n");
		}
	return 0;
	}
