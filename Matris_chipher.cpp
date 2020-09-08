//Matris satýr, sütun iþlemleri kullanarak þifreleme örneði ve dosya iþlemleri (anahtarsýz)
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

char secim;
bool sonuc;



//					CRYPTO CLASS'I					//
class Crypto{
	private:
		string metin;
		int kelimeS,uzunK; //kelime sayýsý ve en uzun kelimenin sahip olduðu karakter sayýsý.
		 
	public:
		void encrypt();
		void decrypt();
		int kelimeSayisi(string metin);
		int uzunKelime(string metin);

};

//					ENCRYPT FONKSÝYONU.				//
void Crypto::encrypt(){
	cout<<"Sifrelemek istediginiz metni giriniz: ";
	getline(cin,metin);
		//gerekli deðiþkenler.
	kelimeS=Crypto::kelimeSayisi(metin);
	uzunK=Crypto::uzunKelime(metin);
    istringstream giris(metin);

		//Metindeki her kelimeyi Kelimeler adýnda bir vectore ayýran komut.
    vector<string> kelimeler;
    copy(istream_iterator<string>(giris), istream_iterator<string>(), back_inserter<vector<string> >(kelimeler));

		//Dosyaya Ecrypt edilmiþ þekilde yazýlýr.
	ofstream dosyaYaz("Encrypted.txt");
  if ( dosyaYaz.is_open() ){

   		for(int i=0;i<uzunK;i++)
		{
			for(int j=0;j<kelimeS;j++)
			{
				if(i<kelimeler[j].length())
				dosyaYaz<<kelimeler[j][i];
				else
				dosyaYaz<<":";
			}
		
			dosyaYaz<<endl;
		}
  
    }
    else
    cout<<"\nHATA! Dosya olusturulamadi.";

    dosyaYaz.close();
}

				//Decrypt Fonksiyonu
void Crypto::decrypt(){
	
	ifstream dosyaOku("encrypted.txt");
	char encMetin;
	char enc[100];
	int i=0,bosluk=0,sayac=0;
	if(dosyaOku.is_open()){
	while(dosyaOku.get(encMetin))
	{
		enc[i]=encMetin;
		if(enc[i]=='\n')
		bosluk++;
		
		i++;
	}
	int satirS=(i/bosluk);
	cout<<"\n\nDecrypt edilmis metin : ";
	
	for(int j=0;j<satirS-1;j++)
	{
		for(int k=0;k<bosluk;k++)
		{	
			if(enc[sayac]!=':')
			cout<<enc[sayac];
			sayac+=satirS;
		}
		sayac=j+1;
		cout<<" ";
	}
	
	}	
	else
	cout<<"\nHATA ! Dosya bulunamadi.";	
}


				//Metindeki kelime sayisi bulan fonksiyon.
int Crypto::kelimeSayisi(string metin){
	int sayac=0,i=0;
	
	while(metin[i]!='\0'){
		if(metin[i]==' ' || metin[i+1]=='\0')
		sayac++;
		i++;
	}
	return sayac;	
}

				//Metindeki en uzun kelimeyi bulan fonksiyon.
int Crypto::uzunKelime(string metin){
	int sayac=0,i=0,uzun=0;
	
	while(metin[i]!='\0'){
	sayac++;
		if(metin[i+1]==' ' || metin[i+1]=='\0')
		{
			if(metin[i]!=' '){
				if(sayac>=uzun)
				uzun=sayac;sayac=0;	
			}	
			sayac--;	
		}
	i++;
	}
	return uzun;	
}



											//  MAIN BLOGU  //
int main(){
	Crypto x;
	
	do{
		sonuc=false;
		cout<<"Matris Chipher Sistemine Hosgeldiniz.\nLutfen Yapmak istediginiz islemi seciniz.\n1)Encode\n2)Decode\n=";
		cin>>secim;cin.ignore();
		switch(secim){
		case '1' : x.encrypt();break;
		case '2' : x.decrypt();break;
		default :cout<<"Hatali islem yaptiniz! Lutfen tekrar deneyiniz.\n"<<endl;sonuc=true;break;	
		}
	}while(sonuc);
	
	
	return 0;
}
