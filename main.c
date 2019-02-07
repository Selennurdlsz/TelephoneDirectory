 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*162802016 MINE YAMAN
  162802046 SELENNUR DILSIZ
  162802047 BEYZA NUR ÖZKARA*/

typedef struct
{
    char isim[100];
    long int kod;
    long int numara;
} telephone;
typedef struct
{
    char guncellenenIsim[100];
    long int guncellenenKod;
    long int guncellenenNumara;
} guncelleme;
typedef struct
{
    long int silinenKod;
} silme;

int main()
{
   setlocale(LC_ALL, "Turkish");
   FILE *pdosya;
   telephone kayit,yeniKayit;
   guncelleme g1;
   silme s1;
   int secim,i,sayac=0,arti=0,x=0,arti2=0,x2=0;
   char tercih1,tercih2;
   pdosya=fopen("TelefonRehberi.txt","wb+");
   if(pdosya==NULL)
   {
       printf("TelefonRehberi.txt Dosyasi Acilmadi....\n");
       exit(1);
   }
   do
    {
       printf("\n\t\t******* TELEFON REHBERI *******\n");
       printf("\n\t*** ISLEMLER ***\n");
       printf("\n 1. Kayit Ekle");
       printf("\n 2. Telefonlari Listele");
       printf("\n 3. Kaydi Duzenle");
       printf("\n 4. Numara Ile Kayit Bul");
       printf("\n 5. Isim Ile Kayit Bul");
       printf("\n 6. Kayit Sil");
       printf("\n 0. Cikis");
       printf("\nSECIM:");
       scanf("%d",&secim);
       switch (secim)
       {
           case 0:
               break;
           case 1:
               printf("\nMusterinin Adi :\t");
               scanf("%s",kayit.isim);
               printf("Musterinin Kodu :\t");
               scanf("%ld",&kayit.kod);
               printf("Musterinin Telefon Numarasi :\t");
               scanf("%ld",&kayit.numara);
               if(fwrite(&kayit,sizeof(kayit),1,pdosya)!=1)
               {
                   printf("YAZMA HATASI...");
                   exit(1);
               }
               printf("\nKaydiniz Basariyla Tamamlanmistir...\n");
               sayac++;
               break;
            case 2:
                rewind(pdosya);
                printf("\n--TELEFON LISTELERI----\n");
                for(i=0;i<sayac;i++)
                {
                    while(fread(&kayit,sizeof(kayit),1,pdosya))
                    {
                            if (kayit.kod==s1.silinenKod)
                                break;
                            else if (!strcmp(kayit.isim,g1.guncellenenIsim)) {
                                if (yeniKayit.kod==s1.silinenKod)
                                    break;
                                else
                                printf("\n%ld kodlu musterinin telefon numarasi :\t%ld\n",yeniKayit.kod,yeniKayit.numara);
                            }
                            else
                                printf("\n%ld kodlu musterinin telefon numarasi :\t%ld\n",kayit.kod,kayit.numara);
                    }
                 }
                 break;
             case 3:
                 do
                 {
                 rewind(pdosya);
                 if(x!=0)
                    break;
                 printf("\nGuncellenecek Musterinin Ismi :\t");
                 scanf("%s",&g1.guncellenenIsim);
                 for(i=0;i<sayac;i++)
                 {
                     while(fread(&kayit,sizeof(kayit),1,pdosya))
                     {
                         if (!strcmp (kayit.isim,g1.guncellenenIsim))
                         {
                             if(kayit.kod==s1.silinenKod)
                                 {break;}
                             else
                             {
                               arti++;  x++;
                               printf("\nMusterinin Adi : %s\t",kayit.isim);
                               printf("\nMusterinin Kodu :%ld\t",kayit.kod);
                               printf("\nMusterinin Telefon Numarasi : %ld\t",kayit.numara);
                               printf("\nDUZELTMEK ISTEDIGINIZ KAYIT BU MU? <E\H> ");
                               char tercih=getch();
                               if (tercih=='E'|| tercih =='e')
                               {
                                  g1.guncellenenNumara=kayit.numara;
                                  g1.guncellenenKod=kayit.kod;
                                  g1.guncellenenIsim[100]=kayit.isim[100];
                                  printf("\nYeni Bilgiler:\n");
                                  printf("\nMusterinin Adi :\t");
                                  scanf("%s",&yeniKayit.isim);
                                  printf("Musterinin Kodu :\t");
                                  scanf("%ld",&yeniKayit.kod);
                                  printf("Musterinin Telefon Numarasi :\t");
                                  scanf("%ld",&yeniKayit.numara);
                                  printf("KAYDINIZ GUNCELLENMISTIR!!!");


                               }
                               else
                                   break;
                             }
                         }
                     }
                 }
                 if(arti==0)
                 {
                     printf("\nAradiginiz isimli musteri BULUNAMAMISTIR!!!\nTEKRAR ARAMA YAPMAK ISTIYOR MUSUNUZ? <E\H>");
                     tercih1=getch();
                 }
                 arti=0;
                 }while(tercih1=='e' || tercih1=='E');
                 x=0;
                 break;
             case 4:
                 rewind(pdosya);
                 int bul2;
                 printf("\n Bulunacak musteri numarasi :\t");
                 scanf("%ld",&bul2);
                 for(i=0;i<sayac;i++)
                 {
                     while(fread(&kayit,sizeof(kayit),1,pdosya))
                     {
                         if(g1.guncellenenNumara==bul2)
                         {
                             printf("Aradiginiz numarali musteri BULUNAMAMISTIR!!!");
                                 break;
                         }
                         else if(yeniKayit.numara==bul2)
                         {
                             if(yeniKayit.kod==s1.silinenKod)
                             {
                                 printf("Aradiginiz numarali musteri BULUNAMAMISTIR!!!");
                                 break;
                             }
                             else
                             {
                                  printf("%ld telefon numarali musterinin ismi :\t%s\n",yeniKayit.numara,yeniKayit.isim);
                                  printf("%ld telefon numarali musterinin kodu :\t%ld\n",yeniKayit.numara,yeniKayit.kod);
                                  break;
                             }
                         }
                         else if(kayit.numara==bul2)
                         {
                             if(kayit.kod==s1.silinenKod)
                             {
                                 printf("Aradiginiz numarali musteri BULUNAMAMISTIR!!!");
                                 break;
                             }
                             else
                             {
                                  printf("%ld telefon numarali musterinin ismi :\t%s\n",kayit.numara,kayit.isim);
                                  printf("%ld telefon numarali musterinin kodu :\t%ld\n",kayit.numara,kayit.kod);
                                  break;
                             }
                         }
                     }
                 }
                 break;
             case 5:
                 rewind(pdosya);
                 char bul[100];
                 printf("\nBulunacak musteri ismi :\t");
                 scanf("%s",&bul);
                 for(i=0;i<sayac;i++)
                 {
                     while(fread(&kayit,sizeof(kayit),1,pdosya))
                     {
                         if(!strcmp (bul, g1.guncellenenIsim))
                         {
                             printf("Aradiginiz isim de musteri BULUNAMAMISTIR!!!");
                                 break;
                         }
                         else if(!strcmp (bul, yeniKayit.isim))
                         {
                             if(yeniKayit.kod==s1.silinenKod)
                             {
                                 printf("Aradiginiz isim de musteri BULUNAMAMISTIR!!!");
                                 break;
                             }
                             else
                             {
                                  printf("%s isimli musterinin kodu :\t%ld\n",yeniKayit.isim,yeniKayit.kod);
                                  printf("%s isimli musterinin telefon numarasi :\t%ld\n",yeniKayit.isim,yeniKayit.numara);
                                  break;
                             }
                         }
                         else if(!strcmp (bul, kayit.isim))
                         {
                             if(kayit.kod==s1.silinenKod)
                             {
                                 printf("Aradiginiz isim de musteri BULUNAMAMISTIR!!!");
                                 break;
                             }
                             else
                             {
                                  printf("%s isimli musterinin kodu :\t%ld\n",kayit.isim,kayit.kod);
                                  printf("%s isimli musterinin telefon numarasi :\t%ld\n",kayit.isim,kayit.numara);
                                  break;
                             }
                         }
                     }

                 break;
             case 6:
                 do
                 {
                 rewind(pdosya);
                 if(x2!=0)
                    break;
                 printf("\nSilinecek Musterinin Kodu :\t");
                 scanf("%ld",&s1.silinenKod);
                 for(i=0;i<sayac;i++)
                 {
                     while(fread(&kayit,sizeof(kayit),1,pdosya))
                     {
                         if(s1.silinenKod==g1.guncellenenKod)
                                 break;
                            else if (s1.silinenKod==yeniKayit.kod)
                            {
                             arti2++; x2++;
                             printf("\nMusterinin Adi : %s\t",yeniKayit.isim);
                             printf("\nMusterinin Kodu :%ld\t",yeniKayit.kod);
                             printf("\nMusterinin Telefon Numarasi : %ld\t",yeniKayit.numara);
                             printf("\nSILMEK ISTEDIGINIZ KAYIT BU MU? <E\H> ");
                             char tercih=getch();
                             if(tercih=='E'|| tercih =='e')
                                printf("\nKAYDINIZ SILINMISTIR!!!\n");
                                break;
                            }
                         else if(kayit.kod==s1.silinenKod)
                         {
                             arti2++;  x2++;
                             printf("\nMusterinin Adi : %s\t",kayit.isim);
                             printf("\nMusterinin Kodu :%ld\t",kayit.kod);
                             printf("\nMusterinin Telefon Numarasi : %ld\t",kayit.numara);
                             printf("\nSILMEK ISTEDIGINIZ KAYIT BU MU? <E\H> ");
                             char tercih=getch();
                             if(tercih=='E'|| tercih =='e') {
                                printf("\nKAYDINIZ SILINMISTIR!!!\n");
                                break;
                             }
                             else
                                break;
                         }
                     }
                 }

                 if(arti2==0)
                 {
                     printf("\nAradiginiz isimli musteri BULUNAMAMISTIR!!!\nTEKRAR ARAMA YAPMAK ISTIYOR MUSUNUZ? <E\H>");
                     tercih2=getch();
                 }
                 arti2=0;
                 }while(tercih2=='e' || tercih2=='E');
                 x2=0;
                 break;
             default :
                 printf("HATA!!Yanlis Islem Numarasi Girdiniz...");
                 break;
        }
       }
    }while(secim!=0);

    fclose(pdosya);
    return 0;
}
