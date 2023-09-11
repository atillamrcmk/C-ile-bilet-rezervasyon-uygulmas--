#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct Bilet{
    int ucus_no;
    char TC_no[12];
    float bilet_fiyat;
 };

struct Ucus {
    int ucus_no;
    char kalkis_yeri[21];
    char varis_yeri[21];
    int kalkis_saati;
    int kalkis_dakikasi;
    int koltuk_kapasitesi;
    int bos_koltuk;
    float baslangic_fiyat;
};
void koltuk_doluluk(){
	float oran;
	float dolulukoran[10],dolulukucusno[10];
	FILE *ucus_dosyasi ;
    ucus_dosyasi = fopen("ucus_2.dat","rb");
    if(!ucus_dosyasi) {
        printf("Hata!");
    } else {
        struct Ucus ucus;
        int bulundu = 0; // uçuþ numarasý bulundu mu kontrolü için
        printf("\nUcus No\t\tKalkis Yeri\tVaris Yeri\tZamani\tKapasite\tBos Koltuk\tDoluluk %%\n");
        printf("-------         -----------     ----------      ------  --------        ----------     ---------\n");
        
        while(fread(&ucus, sizeof(struct Ucus), 1, ucus_dosyasi)==1) {
        	oran=(((ucus.koltuk_kapasitesi - ucus.bos_koltuk)/(float)ucus.koltuk_kapasitesi)*100);
            if (oran>=0 && oran<=50) { // kalkýþ yeri eþleþirse
                
			    printf("%5d\t", ucus.ucus_no);
                printf("\t%s\t     ", ucus.kalkis_yeri);
                printf("   %s\t       ", ucus.varis_yeri);
                printf("%3d:%d\t", ucus.kalkis_saati, ucus.kalkis_dakikasi);
                printf("%4d\t", ucus.koltuk_kapasitesi);
                printf("%12d\t", ucus.bos_koltuk);
                printf("%14.2f\n",((ucus.koltuk_kapasitesi - ucus.bos_koltuk)/(float)ucus.koltuk_kapasitesi)*100);
                bulundu = 1; // kalkýþ yeri bulundu
            }
        }
        if (!bulundu) { // kalkýþ yeri bulunamazsa
            printf("Kalkis yeri  ile eslesen bir ucus bulunamadi.\n");
        }
    }
    fclose(ucus_dosyasi);

}

void ucus_ekle(){
	int ucusnoo,flak=0;
	printf("ucus no giriniz\n");
	scanf("%d",&ucusnoo);
	struct Bilet biletsatis2;
	FILE *bilet_dosyasi;
	FILE *ucus_dosyasi;
    struct Ucus ucus;
	if((bilet_dosyasi=fopen("bilet.txt","r"))==NULL)
	{
		printf("dosya acilamadi\n");
	}
	else
	{
	
	while(!feof(bilet_dosyasi))
	{
		fscanf(bilet_dosyasi,"%d %s %f \n",&biletsatis2.ucus_no,biletsatis2.TC_no,&biletsatis2.bilet_fiyat);
		if(biletsatis2.ucus_no==ucusnoo){
		printf("boyle ucus var\n");
		flak++;
		break;
            
        }
     	
		}
    
    if(flak==0){
    	printf("boyle ucus yok ekle\n");
    	 if((ucus_dosyasi = fopen("ucus_2.dat","ab")) == NULL)
    {
        printf("dosya açilamadi\n");
        
    }
    else{
	
    printf(" eklemek istediginiz ucus no girin:\n");
    scanf("%d",&ucus.ucus_no);
    printf("kalkis yeri giriniz:\n");
    scanf("%s",ucus.kalkis_yeri);
    printf("varis yeri giriniz:\n");
    scanf("%s",ucus.varis_yeri);
    printf("kalkis saati:\n");
    scanf("%d",&ucus.kalkis_saati);
	printf( "kalkis dakikasi:\n");
	scanf("%d",&ucus.kalkis_dakikasi);
	printf("koltuk kapasitesi:\n");
	scanf("%d",&ucus.koltuk_kapasitesi);
	ucus.bos_koltuk=ucus.koltuk_kapasitesi;
	printf("baslangýc fiyat :\n");
	scanf("%.2f",&ucus.baslangic_fiyat);
	fwrite(&ucus, sizeof(struct Ucus), 1, ucus_dosyasi);
	fclose(ucus_dosyasi);
    
  } 
	}
    fclose(bilet_dosyasi);
	
}}
void yeregore_ara(char* kalkis_yerii) {
    FILE *ucus_dosyasi ;
    ucus_dosyasi = fopen("ucus_2.dat","rb");
    if(!ucus_dosyasi) {
        printf("Hata!");
    } else {
        struct Ucus ucus;
        int bulundu = 0; // uçuþ numarasý bulundu mu kontrolü için
        printf("\nUcus No\t\tKalkis Yeri\tVaris Yeri\tZamani\tKapasite\tBos Koltuk\tDoluluk %%\n");
        printf("-------         -----------     ----------      ------  --------        ----------     ---------\n");
        while(fread(&ucus, sizeof(struct Ucus), 1, ucus_dosyasi)==1) {
            if (strcmp(ucus.kalkis_yeri, kalkis_yerii) == 0) { // kalkýþ yeri eþleþirse
               printf("%5d\t", ucus.ucus_no);
                printf("\t%s\t     ", ucus.kalkis_yeri);
                printf("   %s\t       ", ucus.varis_yeri);
                printf("%3d:%d\t", ucus.kalkis_saati, ucus.kalkis_dakikasi);
                printf("%4d\t", ucus.koltuk_kapasitesi);
                printf("%12d\t", ucus.bos_koltuk);
                printf("%14.2f\n",((ucus.koltuk_kapasitesi - ucus.bos_koltuk)/(float)ucus.koltuk_kapasitesi)*100);
                bulundu = 1; // kalkýþ yeri bulundu
            }
        }
        if (!bulundu) { // kalkýþ yeri bulunamazsa
            printf("Kalkis yeri '%s' ile eslesen bir ucus bulunamadi.\n", kalkis_yerii);
        }
    }
    fclose(ucus_dosyasi);
}


int dosya_kontrol(int ucus_no){
    FILE *ucus_dosyasi;
    struct Ucus ucus;
    int sayac = 0;

    if((ucus_dosyasi = fopen("ucus_2.dat","rb")) == NULL)
    {
        printf("dosya açilamadi\n");
        return -1;
    }

    else{
        printf("\nUcus No\t\tKalkis Yeri\tVaris Yeri\tZamani\tKapasite\tBos Koltuk\tDoluluk %%\n");
        printf("-------         -----------     ----------      ------  --------        ----------     ---------\n");
        while(fread(&ucus, sizeof(struct Ucus), 1, ucus_dosyasi) == 1){
            if(ucus.ucus_no == ucus_no){
                sayac++;
                printf("%5d\t", ucus.ucus_no);
                printf("\t%s\t     ", ucus.kalkis_yeri);
                printf("   %s\t       ", ucus.varis_yeri);
                printf("%3d:%d\t", ucus.kalkis_saati, ucus.kalkis_dakikasi);
                printf("%4d\t", ucus.koltuk_kapasitesi);
                printf("%12d\t", ucus.bos_koltuk);
                printf("%14.2f\n",((ucus.koltuk_kapasitesi - ucus.bos_koltuk)/(float)ucus.koltuk_kapasitesi)*100);
            }
        }
        if(sayac == 0){
            printf("Boyle bir kayit bulunamadi\n\n");
        }
    }
    fclose(ucus_dosyasi);
    return 0;
}
void bilet_satis()
{
    struct Bilet biletsatis;
    struct Ucus biletekleme;
    FILE *ucus_dosyasi;
    FILE *bilet_dosyasi;

    if((bilet_dosyasi=fopen("bilet.txt","a"))==NULL)
    {
        printf("dosya olusturulamadi\n");
    }
    else
    {
        printf("dosya olusturuldu, bilgileri giriniz\n");
        printf("ucusno:\n"); scanf("%d",&biletsatis.ucus_no);
        printf("tcno:\n");   scanf("%s",&biletsatis.TC_no);
        printf("biletfiyat:\n"); scanf("%f",&biletsatis.bilet_fiyat);
        fprintf(bilet_dosyasi,"%d %s %.2f\n",biletsatis.ucus_no,biletsatis.TC_no,biletsatis.bilet_fiyat);
        printf("dosyaya yazildi\n");

        if((ucus_dosyasi=fopen("ucus_2.dat","rb+"))==NULL)
        {
            printf("dosya olusturulamadi\n");
        }
        else
        {
            while(fread(&biletekleme, sizeof(struct Ucus), 1, ucus_dosyasi) == 1)
            {
                if(biletekleme.ucus_no == biletsatis.ucus_no)
                {
                    if(biletekleme.bos_koltuk==0)
                    {
                        printf("Bos koltuk kalmamistir.\n");
                    }
                    else
                    {
                        biletekleme.bos_koltuk=biletekleme.bos_koltuk-1;
                        fseek(ucus_dosyasi, -sizeof(struct Ucus), SEEK_CUR);
                        fwrite(&biletekleme, sizeof(struct Ucus), 1, ucus_dosyasi);
                        printf("bos koltuk sayisi 1 azaltildi.\n");
                    }
                }
            }

            fclose(ucus_dosyasi);
        }

        fclose(bilet_dosyasi);
    }
}

	

void satilan_biletler(int ucus_noo)
{
	struct Bilet biletsatis2;
	int satilan_bilet_sayisi=0;
	float toplam_kazanc,ort_bilet_fiyat;
	FILE *bilet_dosyasi;
	if((bilet_dosyasi=fopen("bilet.txt","r"))==NULL)
	{
		printf("dosya acilamadi\n");
	}
	else
	{
	printf("satilan biletler:\n");
	printf("ucusno: tcno: bilet fiyat:\n");
	while(!feof(bilet_dosyasi))
	{
		fscanf(bilet_dosyasi,"%d %s %f \n",&biletsatis2.ucus_no,biletsatis2.TC_no,&biletsatis2.bilet_fiyat);
		if(biletsatis2.ucus_no==ucus_noo){
		
		printf("%d %s %.2f\n",biletsatis2.ucus_no,biletsatis2.TC_no,biletsatis2.bilet_fiyat);
		satilan_bilet_sayisi++;
		toplam_kazanc+=biletsatis2.bilet_fiyat;}
		
	}
	fclose(bilet_dosyasi);	
	printf("satilan bilet sayisi: %d \n",satilan_bilet_sayisi);
	printf("toplam kazanc: %.2f\n",toplam_kazanc);
	ort_bilet_fiyat=toplam_kazanc/(float)satilan_bilet_sayisi;
	printf("ortalama bilet fiyat: %.2f\n",ort_bilet_fiyat);
	}
}
void yolcu_bilet(char* tcnoo){
	struct Bilet biletsatis3;
	FILE *bilet_dosyasi;
	if((bilet_dosyasi=fopen("bilet.txt","r"))==NULL)
	{
		printf("dosya acilamadi\n");
	}
	else
	{
	printf("satilan biletler:\n");
	printf("ucusno: tcno: bilet fiyat:\n");
	while(!feof(bilet_dosyasi))
	{
		fscanf(bilet_dosyasi,"%d %s %f \n",&biletsatis3.ucus_no,biletsatis3.TC_no,&biletsatis3.bilet_fiyat);
		if (strcmp(biletsatis3.TC_no, tcnoo) == 0){
		dosya_kontrol(biletsatis3.ucus_no);
		printf(" \n bilet fiyat: \n------------\n %.2f\n",biletsatis3.bilet_fiyat);
	
}}
}}
void rotar(int ucus_no,int ucus_saat,int ucus_dakika){
	FILE *ucus_dosyasi;
    struct Ucus ucus;
     if((ucus_dosyasi = fopen("ucus_2.dat","rb+")) == NULL)
    {
        printf("dosya açilamadi\n");
        
    }
   else{
   	fwrite(&ucus, sizeof(struct Ucus), 1, ucus_dosyasi);
   	printf("%d",ucus.ucus_no);
   	if(ucus.ucus_no==ucus_no){
	   
   	ucus.kalkis_saati+=ucus_saat;
   	ucus.kalkis_dakikasi+=ucus_dakika;
   	
	   fclose(ucus_dosyasi);}
   }
}







int main(){
    //satilan_biletler();
	char programsecim, aranan_sehir[21],tcno[12];
	int sorgulamasecim,guncellemesecim, ucus_no,ucus_saat,ucus_dakika;
	printf("----------Bilet Satis Programi---------------   \n ");
    
	printf("A: Sorgulama Programi\n");
	printf(" B: Guncelleme Programi\n");
    scanf("%c",&programsecim); 
	while(programsecim!='A'||programsecim!='B' || programsecim!='a' || programsecim!='b')
    {
	if(programsecim=='A'||programsecim=='B' || programsecim=='a'||programsecim=='b')
	break;  //secim islem dogru olmama durumu

	printf("yanlis giris yaptiniz lutfen tekrar giriniz\n");
	scanf("%c",&programsecim);

	}
	if(programsecim=='A' || programsecim=='a')
	{
		printf("-------------Sorgulama programi-----------\n");
		printf("1: Ucus bilgilerini listle\n");
		printf("2:satilan biletlerin listelenmesi\n");
		printf("3:Bir yerden kalkan ucuslarin bilgilerinin listelenmesi\n");
		printf("4:Koltuk doluluk orani % 50 nin altinda olan ucuslarin listelenmesi\n");
		printf("5:Bir yolcunun biletlerinin listelenmesi\n");
		scanf("%d",&sorgulamasecim);
		while(sorgulamasecim<1 || sorgulamasecim>5){
		if(sorgulamasecim<5 && sorgulamasecim>1) // sorgulama secim dogru olmama durumu
		break;
		printf("yanlis giris yaptiniz lutfen tekrar giriniz\n");
	    scanf("%d",&sorgulamasecim);
		}
		switch(sorgulamasecim)
		{
		case 1:
			printf("ucusno girin\n");
			scanf("%d",&ucus_no);
			while(ucus_no<1 || ucus_no>100){
		if(ucus_no<1000 && ucus_no>1) // ucusno dogru olmama durumu
		break;
			printf("yanlis giris yaptiniz lutfen tekrar giriniz\n");
	    scanf("%d",&ucus_no);}
			dosya_kontrol(ucus_no);
			break;
		case 2:
			
		printf("ucusno girin\n");
			scanf("%d",&ucus_no);
			while(ucus_no<1 || ucus_no>100){
		if(ucus_no<1000 && ucus_no>1) // ucusno dogru olmama durumu
		break;
			printf("yanlis giris yaptiniz lutfen tekrar giriniz\n");
	    scanf("%d",&ucus_no);}
	        dosya_kontrol(ucus_no);
			satilan_biletler(ucus_no);
			break;
		case 3:
			
			printf("aranacak sehri giriniz\n");
			scanf("%s",aranan_sehir);
			yeregore_ara(aranan_sehir);
			break;
		case 4:
			koltuk_doluluk();
			break;
		case 5:
			printf("aramak istediginiz yolcunun tc girin\n");
			scanf("%s",tcno);
			yolcu_bilet(tcno);
			break;
		}
	}
	else
    {
		printf("-------------Guncelleme programi-----------\n");
		printf("1: Yeni bir ucus eklenmesi\n");
		printf("2:Bir ucusun kaydini silinmesi\n");
		printf("3:Bir ucusun kalkis zamaninin degistirilmesi\n");
		printf("4:Bir ucusa iliskin bilet satilmasi\n");
		scanf("%d",&guncellemesecim);
		while(guncellemesecim<1 || guncellemesecim>4){
		if(guncellemesecim<4 && guncellemesecim>1) //guncelleme secim dogru olmama durumu
		break;
		printf("yanlis giris yaptiniz lutfen tekrar giriniz\n");
	    scanf("%d",&guncellemesecim);
		}
		switch(guncellemesecim)
		{
		case 1:
			ucus_ekle();
			break;
		case 2:
			break;
		case 3:
			printf("rotar yapacak ucusno girin:\n");
			scanf("%d",&ucus_no);
			printf("ucus ne kadar gecikecek:\n");
			printf("saat:\n");
			scanf("%d",&ucus_saat);
			printf("dakika:\n");
			scanf("%d",&ucus_dakika);
			rotar(ucus_no,ucus_saat,ucus_dakika);
			break;
		case 4:
			bilet_satis();
			break;
		}
		}
	return 0;
}
