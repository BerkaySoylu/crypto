#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char secim[1];
bool hata;
	
void encrypt(){												// ENCRYPT FONKSIYONU  //
	string metin;
	char harf,encMetin[100];
	int key,metinBoyutu;
	bool hata;
	
	do{
		hata=false;
		cout<<"\n\nSifrelemek istediginiz metni giriniz :";
		getline(cin,metin);
		cout<<"Keyi giriniz =";
		cin>>key;cin.ignore();
	
		metinBoyutu= metin.length();
	
		for(int i=0;i<metinBoyutu;i++)
		{
			harf=metin[i];
			if(harf>=65 && harf<=90)
			{
				
				encMetin[i]=(((harf - 65) + key ) %26 + 65);		//BÜYÜK HARFLER ÝÇÝN CAESAR ENCRYPT
			
			}
			else if(harf>=97 && harf<=122)
			{
				
				encMetin[i]=(((harf - 97) + key ) %26 + 97);		//KÜÇÜK HARFLER ÝÇÝN CAESAR ENCRYPT
				
			}
			else if(harf==' ')
			{
				encMetin[i]=' ';
	
			}
			else
			{
				cout<<"\nHata! Metniniz yalnizca Ingiliz alfabesi karakterleri icermelidir."<<endl;
				hata=true;break;
			}	
		}
	}while(hata);
	
	ofstream dosyaYaz("Encrypted.txt");   //dosya açýlýr
  	if ( dosyaYaz.is_open() ){
		for(int j=0;j<metinBoyutu;j++){
		dosyaYaz<<encMetin[j];				//dosyaya yazdýrýlýr
		}
	cout<<"\nMetin Basari ile Sifrelendi!"<<endl;
	}
    else
    cout<<"\nHATA! Dosya olusturulamadi.";

    dosyaYaz.close();						// dosya kapanýr
}

void decrypt(){												// DECRYPT FONSIYONU  //
	
	char encHarf,harf;
	char encMetin[100];
	int key,i=0,j;
	
	cout<<"Lutfen Keyi giriniz =";
	cin>>key;cin.ignore();
	
	ifstream dosyaOku("encrypted.txt");
	if(dosyaOku.is_open()){
		while(dosyaOku.get(encHarf))
		{
			encMetin[i]=encHarf;
			i++;
		}
		
		for(int j=0;j<i;j++)
		{
			harf=encMetin[j];
			if(harf>=65 && harf<=90)
			{
				
				encMetin[j]=(((harf - 65) - key ) %26 + 65);		//BÜYÜK HARFLER ÝÇÝN CAESAR DECRYPT
			
			}
			else if(harf>=97 && harf<=122)
			{
				
				encMetin[j]=(((harf - 97) - key ) %26 + 97);		//KÜÇÜK HARFLER ÝÇÝN CAESAR DECRYPT
				
			}
			else if(harf==' ')
			{
				encMetin[j]=' ';
	
			}
			
			cout<<encMetin[j];	
		}
	cout<<"\nMetin Basari ile Desifre edildi!"<<endl;
	}	
	else
		cout<<"\nHATA ! Dosya bulunamadi.";		
}

int main(){										// MAIN BLOGU //
	
do{
	hata= false;
	cout<<"Yapmak istediginiz islemi seciniz :\n1-Encrypt.\n2-Decrypt\nSecim=";
	cin>>secim;cin.ignore();
	switch(secim[0]){
		case '1': encrypt(); break;
		case '2': decrypt(); break;
		default: cout<<"\nHatali islem yapatiniz.\n\n" ;hata= true;
	}	
}while(hata);

return 0;
}
