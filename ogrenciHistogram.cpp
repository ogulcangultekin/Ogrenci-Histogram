
#include <stdio.h>
#include <math.h> 
//****************************************//
//****************************************//
void giris(int no[], int notu[], int N); 
float ortalama(int notu[], int N); 
void goruntule(int no[], int notu[], int N); 
void otele(int notu[], int no[], int N);
void siralama(int no[],int notu[],int N);
void standartsap(int notu[],int no[],int N);
void histogram(int notu[],int N);
main() 
{ 
int N;  
int OgrNo[BUFSIZ], BNotu[BUFSIZ]; 
float ort;  
printf("Ogrenci sayisini giriniz: ");  
scanf("%d", &N);  
giris(OgrNo, BNotu, N);  
goruntule(OgrNo, BNotu, N);  
ort = ortalama(BNotu, N);  
printf("Not ortalamasi: %5.2f\n", ort); 
otele(BNotu, OgrNo, N);
siralama(OgrNo, BNotu, N);
standartsap(BNotu,OgrNo,N);
histogram(BNotu,N);
return 0;
} 
 
void giris(int no[], int notu[], int N) {   
int i;  
for (i=0; i<N; i++)  
{ printf("Ogrenci no gir: ");   
scanf("%d", &no[i]);  
printf("%d numarali ogrencinin basari notunu gir : ", no[i]);   
scanf("%d", &notu[i]);  
} 
} 
 
void goruntule(int no[], int notu[], int N) {
printf("Ogrenci#\tNotu\n");  
for (int i=0; i<N; i++)   
printf("%8d\t%3d\n", no[i], notu[i]); 
} 
 
float ortalama(int notu[], int N) { 
float t;  
int i;  t = 0;  
for (i=0; i<N; i++)   
t = t + notu[i];  
float ort = t / N;  
return ort; 
} 
//--------------------------------------------
void otele(int notu[], int no[], int N){
int sayac=0;
float top=0;	
float degisen[BUFSIZ];
for(int i=0;i<N;i++)
{
	if(notu[i]>=20){
		top=top+notu[i];  //Notu 20 den b�y�k olanlar�n notlar�n�n toplam�n� ald�m.�f 'in i�ine sayac ekleyip ko�ulu sa�layan ka� ��renci oldu�unu hesaplad�m.
		sayac++;
	}
}	
float orta=top/sayac; //Toplam ve 20 nin �zerinde ka� ��renci varsa  sayac sayesinde bulup ortalamay� ald�m.
if(orta>50){
	printf("Ortalama 50'den buyuk oteleme yapilamaz.\n"); // Ortalama 50 den b�y�k ��karsa �teleme yapt�rmad�m.
}
else{   //E�er ortalama 50 den k���k ��karsa a�a��daki i�lemleri yapt�rd�m.
float islem=50-orta;// Ka� puan �telece�ini anlamak i�in 50 den ��kard�m.
printf("20 den buyuk notlarin ortalamasi: %5.2f\n", orta); //20 den b�y�k notlar�n ortalamas�n� yazd�rd�m.
printf("Yeni Notlar\n");
printf("Ogrenci#\tNotu\n");
for(int j=0;j<N;j++)
{
	if(notu[j]>=30)   // Notu 30 dan b�y�k olanlar�n notlar�na �teleme yapt�ran i�lemi yapt�rd�m.
	{
		notu[j]=islem+notu[j];
	}
	else // e�er notu 30 dan k���kse aynen notunu tekrar yazd�rd�m.
	{
		notu[j]=notu[j];
	}
}
}
for(int k=0;k<N;k++) 
{	
	printf("%d\t\t%d\n", no[k], notu[k]); //�telenmi� ��renci notlar�n� ve numaralar�n� yazd�rd�m.
}
float yeniTop=0;
float yeniOrt=0;
int sayan=0;
for(int h=0;h<N;h++)  // Yeni notlar�n ortalamas�n� hesaplatt�m.
{
	yeniTop=notu[h]+yeniTop;
	sayan++;
}	
yeniOrt=yeniTop/sayan;
printf("Yeni Notlarin Ortalamasi %5.2f\n",yeniOrt);

}
void siralama(int no[],int notu[],int N){
int gecici;
int gecicis;
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++)
	{
		if(notu[i]<=notu[j]) // Notlar� k�c�kten b�y��e yazd�rmas�n� sa�layan ko�ulu yazd�m.
		{
			gecici=notu[i];
			notu[i]=notu[j];
			notu[j]=gecici;
			gecicis=no[i];
			no[i]=no[j];
			no[j]=gecicis;
		}
	}
}
printf("Basari Notlarina Gore Kucukten Buyuge Siralama\n");
for(int k=0;k<N;k++)
{
printf("%d\t%d\n",no[k],notu[k]);//Notlar� k���kten b�y��e yazd�rd�m.
}
int geciciz;
int gecicix;
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++)
	{
		if(no[i]<=no[j])// Numaralar� k�c�kten b�y��e yazd�rmas�n� sa�layan ko�ulu yazd�m.
		{
			geciciz=notu[i];
			notu[i]=notu[j];
			notu[j]=geciciz;
			gecicix=no[i];
			no[i]=no[j];
			no[j]=gecicix;
		}
	}
}
printf("Ogrenci Numaralarina Gore Kucukten Buyuge Siralama\n");
for(int k=0;k<N;k++)
{
printf("%d\t%d\n",no[k],notu[k]);//Numaralar� k���kten b�y��e yazd�rd�m.
}
}
void standartsap(int notu[],int no[],int N){
float ort1=0;
float toplam=0;
 for(int i=0;i<N;i++) // Ortalamay� tekrar hesaplatt�m.
 {
 	toplam=notu[i]+toplam;
 }
 ort1=toplam/N;   
 float std=0;
 for(int j=0;j<N;j++) // Standart Sapmad�n�n form�l�n� yaz�p standar sapmay� hesaplatt�m.
 {
 	std +=pow(ort1-notu[j],2);
 }
 float tamstd=sqrt(std/N);
 
 printf("Otelenmis Basari Notlarinin Standart Sapmasi = %5.2f\n",tamstd); // Standar sapmay� yazd�rd�m.
 }
 
 
 void histogram(int notu[],int N){
 	printf("Histogram\n");
 	
int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,d1=0,d2=0,e=0,f=0; // Sayaclar� tan�mlad�m.
for(int i=0;i<N;i++) // D�ng�n�n i�inde hangi not aral���na ka� ��renci girdi�ini sayaclar sayesinde hesaplad�m.
{
	if(notu[i]>=90)
	{
		a1++;
	}
	if(notu[i]>=80 && notu[i]<90)
	{
		a2++;
	}
	if(notu[i]>=75 && notu[i]<80)
	{
		b1++;
	}
	if(notu[i]>=70 && notu[i]<75)
	{
		b2++;
	}
	if(notu[i]>=65 && notu[i]<70)
	{
		c1++;
	}
	if(notu[i]>=60 && notu[i]<65)
	{
		c2++;
	}
	if(notu[i]>=55 && notu[i]<60)
	{
		d1++;
	}
	if(notu[i]>=50 && notu[i]<55)
	{
		d2++;
	}
	if(notu[i]>=40 && notu[i]<50)
	{
		e++;
	}
	if(notu[i]<=39)
	{
		f++;
	}
	
	}
	//------------------------------------------------------------------
	printf("A1| ");  // Daha sonra d�ng�n�n i�inde i den sayac say�s�na kadar " * " koydurdum.B�ylelikle yatay histogram� tamamlad�m.
	for(int i=0;i<a1;i++)
	{
		printf("* ");
	}
	printf("\n");
	printf("A2| ");
	for(int i=0;i<a2;i++)
	{
		printf("* ");
	}
	printf("\n");
 		printf("B1| ");
	for(int i=0;i<b1;i++)
	{
		printf("* ");
	}
	printf("\n");
		printf("B2| ");
	for(int i=0;i<b2;i++)
	{
		printf("* ");
	}
	printf("\n");
		printf("C1| ");
	for(int i=0;i<c1;i++)
	{
		printf("* ");
	}
	printf("\n");
		printf("C2| ");
	for(int i=0;i<c2;i++)
	{
		printf("* ");
	}
	printf("\n");
 		printf("D1| ");
	for(int i=0;i<d1;i++)
	{
		printf("* ");
	}
	printf("\n");
		printf("D2| ");
	for(int i=0;i<d2;i++)
	{
		printf("* ");
	}
	printf("\n");
		printf(" E| ");
	for(int i=0;i<e;i++)
	{
		printf("* ");
	}
	printf("\n");
 		printf(" F| ");
	for(int i=0;i<f;i++)
	{
		printf("* ");
	}
	printf("\n");
//	------------------------------------------------------------------

	int enyuksek;  // en y�ksek de�eri bulup en y�ksek ��kan sayac kadar histogramda numaralama yapt�rd�m.
	if(a1>=a2 && a2>=b1 && a1>=b2 && a1>=c1 && a1>=c2 && a1>=d1 && a1>=d2 && a1>=e && a1>=f)
	{
		enyuksek=a1;
	}
	else if(a2>=a1 && a2>=b1 && a2>=b2 && a2>=c1 && a2>=c2 && a2>=d1 && a2>=d2 && a2>=e && a2>=f)
	{
		enyuksek=a2;
	}
	else if(b1>=a1 && b1>=a2 && b1>=b2 && b1>=c1 && b1>=c2 && b1>=d1 && b1>=d2 && b1>=e && b1>=f)
	{
		enyuksek=b1;
	}
	else if(b2>=a1 && b2>=a2 && b2>=b1 && b2>=c1 && b2>=c2 && b2>=d1 && b2>=d2 && b2>=e && b2>=f)
	{
		enyuksek=b2;
	}
	else if(c1>=a1 && c1>=a2 && c1>=b1 && c1>=b2 && c1>=c2 && c1>=d1 && c1>=d2 && c1>=e && c1>=f)
	{
		enyuksek=c1;
	}
	else if(c2>=a1 && c2>=a2 && c2>=b1 && c2>=b2 && c2>=c1 && c2>=d1 && c2>=d2 && c2>=e && c2>=f)
	{
		enyuksek=c2;
	}
	else if(d1>=a1 && d1>=a2 && d1>=b1 && d1>=b2 && d1>=c1 && d1>=c2 && d1>=d2 && d1>=e && d1>=f)
	{
		enyuksek=d1;
	}
	else if(d2>=a1 && d2>=a2 && d2>=b1 && d2>=b2 && d2>=c1 && d2>=c2 && d2>=d1 && d2>=e && d2>=f)
	{
		enyuksek=d2;
	}
	else if(e>=a1 && e>=a2 && e>=b1 && e>=b2 && e>=c1 && e>=c2 && e>=d1 && e>=d2 && e>=f)
	{
		enyuksek=e;
	}
	else 
	{
		enyuksek=f;
	}
	for(int m=0;m<enyuksek;m++)
	{
		printf("-----");
	}
	printf("\n");
	printf("   |");
	for(int k=0;k<enyuksek;k++) // En y�ksek ��kan sayac  kadar numaraland�rma
	{
		
		printf("%d ",k);
	
	}
 }
