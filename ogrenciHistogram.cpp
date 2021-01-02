
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
		top=top+notu[i];  //Notu 20 den büyük olanlarýn notlarýnýn toplamýný aldým.Ýf 'in içine sayac ekleyip koþulu saðlayan kaç öðrenci olduðunu hesapladým.
		sayac++;
	}
}	
float orta=top/sayac; //Toplam ve 20 nin üzerinde kaç öðrenci varsa  sayac sayesinde bulup ortalamayý aldým.
if(orta>50){
	printf("Ortalama 50'den buyuk oteleme yapilamaz.\n"); // Ortalama 50 den büyük çýkarsa öteleme yaptýrmadým.
}
else{   //Eðer ortalama 50 den küçük çýkarsa aþaðýdaki iþlemleri yaptýrdým.
float islem=50-orta;// Kaç puan öteleceðini anlamak için 50 den çýkardým.
printf("20 den buyuk notlarin ortalamasi: %5.2f\n", orta); //20 den büyük notlarýn ortalamasýný yazdýrdým.
printf("Yeni Notlar\n");
printf("Ogrenci#\tNotu\n");
for(int j=0;j<N;j++)
{
	if(notu[j]>=30)   // Notu 30 dan büyük olanlarýn notlarýna öteleme yaptýran iþlemi yaptýrdým.
	{
		notu[j]=islem+notu[j];
	}
	else // eðer notu 30 dan küçükse aynen notunu tekrar yazdýrdým.
	{
		notu[j]=notu[j];
	}
}
}
for(int k=0;k<N;k++) 
{	
	printf("%d\t\t%d\n", no[k], notu[k]); //Ötelenmiþ öðrenci notlarýný ve numaralarýný yazdýrdým.
}
float yeniTop=0;
float yeniOrt=0;
int sayan=0;
for(int h=0;h<N;h++)  // Yeni notlarýn ortalamasýný hesaplattým.
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
		if(notu[i]<=notu[j]) // Notlarý kücükten büyüðe yazdýrmasýný saðlayan koþulu yazdým.
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
printf("%d\t%d\n",no[k],notu[k]);//Notlarý küçükten büyüðe yazdýrdým.
}
int geciciz;
int gecicix;
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++)
	{
		if(no[i]<=no[j])// Numaralarý kücükten büyüðe yazdýrmasýný saðlayan koþulu yazdým.
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
printf("%d\t%d\n",no[k],notu[k]);//Numaralarý küçükten büyüðe yazdýrdým.
}
}
void standartsap(int notu[],int no[],int N){
float ort1=0;
float toplam=0;
 for(int i=0;i<N;i++) // Ortalamayý tekrar hesaplattým.
 {
 	toplam=notu[i]+toplam;
 }
 ort1=toplam/N;   
 float std=0;
 for(int j=0;j<N;j++) // Standart Sapmadýnýn formülünü yazýp standar sapmayý hesaplattým.
 {
 	std +=pow(ort1-notu[j],2);
 }
 float tamstd=sqrt(std/N);
 
 printf("Otelenmis Basari Notlarinin Standart Sapmasi = %5.2f\n",tamstd); // Standar sapmayý yazdýrdým.
 }
 
 
 void histogram(int notu[],int N){
 	printf("Histogram\n");
 	
int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,d1=0,d2=0,e=0,f=0; // Sayaclarý tanýmladým.
for(int i=0;i<N;i++) // Döngünün içinde hangi not aralýðýna kaç öðrenci girdiðini sayaclar sayesinde hesapladým.
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
	printf("A1| ");  // Daha sonra döngünün içinde i den sayac sayýsýna kadar " * " koydurdum.Böylelikle yatay histogramý tamamladým.
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

	int enyuksek;  // en yüksek deðeri bulup en yüksek çýkan sayac kadar histogramda numaralama yaptýrdým.
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
	for(int k=0;k<enyuksek;k++) // En yüksek çýkan sayac  kadar numaralandýrma
	{
		
		printf("%d ",k);
	
	}
 }
