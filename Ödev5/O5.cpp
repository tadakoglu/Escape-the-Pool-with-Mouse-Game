
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void tablo(char havuz[10][10],char havuz2[10][10], int a, int b);
int menu();
void islem(char havuz[10][10],char havuz2[10][10], int a, int b);
void display(char havuz2[10][10], int a, int b);

void main()
{
	int a,b;
	srand(time(NULL));
	char havuz[10][10];
	char havuz2[10][10];
	a=rand()%8+1;
	b=rand()%8+1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			havuz[i][j]=0;
			havuz2[i][j]=0;
		}
	}

	
	for(int i=0;i<10;i++)
	{	
		havuz[i][0]='~';
		havuz[0][i]='~';
		havuz[i][9]='~';
		havuz[9][i]='~';
		havuz2[i][0]='~';
		havuz2[0][i]='~';
		havuz2[i][9]='~';
		havuz2[9][i]='~';
		
	}
	havuz[9][3]=' ';
	havuz[3][9]=' ';
	havuz2[9][3]=' ';
	havuz2[3][9]=' ';
	
	islem(havuz,havuz2,a,b);
}

int menu()
{
	int sec;
	
	printf("1. Saga\n2. Sola\n3. Asagiya\n4. Yukariya\n5. Goruntule\n6. Cikis\n");
	printf("Secenek ?");
	scanf("%d",&sec);
	return sec;
}

void tablo(char havuz[10][10],char havuz2[10][10], int a, int b)
{
	
	char *fare="@";
	
	havuz[a][b]=*fare;
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%c",havuz[i][j]);
		
		}
		printf("\n");
	}
	

}

void islem(char havuz[10][10],char havuz2[10][10], int a, int b)
{
	int sec;
	int c=0;
	int adim;
	
	char fare;
	char fare2;
	for(;;)
	{
		system("CLS");
		tablo(havuz, havuz2, a, b);
		c++;
		sec=menu();
		

		
		if(c==11)
		{
			printf("Yeniden baslatiniz\n\a");
			break;
		}
		if(sec==1)
		{
			printf("Adim sayisini giriniz:");
			scanf("%d",&adim);
			b=b+adim;
			if(b>=9 && a!=3)
			{
				printf("Fare suya dustu\n\a");
				display(havuz2,a,b);
				printf("Yeniden giris yapiniz\n");
				break;
			}
			else if(b>=9 && a==3)
			{
				printf("Fare kurtuldu\n\a");
				display(havuz2,a,b);
				break;
			}
			
			else
			{
				fare=havuz[a][b];
				fare2=havuz2[a][b];
				havuz[a][b-adim]=' ';
				for(int u=b-adim;u<b;u++)
					havuz2[a][u]='*';
			}
			
		}
		else if(sec==2)
		{
			printf("Lutfen adim sayisini giriniz:");
			scanf("%d",&adim);
			b=b-adim;
			if(b<=0)
			{
				printf("Fare suya dustu\n\a");
				display(havuz2,a,b);
				printf("Tekrar oynamak icin yeniden giris yapiniz\n");
				break;
			}
			else
			{
				fare=havuz[a][b];
				fare2=havuz2[a][b];
				havuz[a][b+adim]=' ';
				for(int u=b;u<b+adim;u++)
					havuz2[a][u]='*';
			}
		}
		else if(sec==3)
		{
			printf("Lutfen adim sayisini giriniz:");
			scanf("%d",&adim);
			a=a+adim;
			if(a>=9 && b!=3)
			{
				printf("Fare suya dustu\n\a");
				display(havuz2,a,b);
				printf("Tekrar oynamak icin yeniden giris yapiniz\n");
				break;
			}
			else if(a>=9 && b==3)
			{
				printf("Fare kurtuldu\n\a");
				display(havuz2,a,b);
				printf("Tekrar oynamak icin yeniden giris yapiniz\n");
				break;
			}
			else
			{
				fare=havuz[a][b];
				fare2=havuz2[a][b];
				havuz[a-adim][b]=' ';
				for(int u=a-adim;u<a;u++)
					havuz2[u][b]='*';

			}
			
		}
		else if(sec==4)
		{
			printf("Lutfen adim sayisini giriniz:");
			scanf("%d",&adim);
			a=a-adim;
			if(a<=0)
			{
				printf("Fare suya dustu.\nTekrar oynamak icin yeniden giris yapiniz.\n\a");
				display(havuz2,a,b);
				printf("Tekrar oynamak icin yeniden giris yapiniz!!!\n");
				break;
			}
			else
			{
				fare=havuz[a][b];
				fare2=havuz2[a][b];
				havuz[a+adim][b]=' ';
				for(int u=a;u<a+adim;u++)
					havuz2[u][b]='*';
			}
			
		}
		else if(sec==5)
		{
			display(havuz2,a,b);
		
			
		}
		else if(sec==6)
		{
			printf("Tekrar oynamak icin yeniden giris yapiniz\n\a");
			break;
		}
		else
		{
			printf("Hatali bir secim yaptin tekrar dene\n\n\a");
		}
	}
}

void display(char havuz2[10][10], int a, int b)
{
	char *fare2="@";
	havuz2[a][b]=*fare2;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%c",havuz2[i][j]);
		
		}
		printf("\n");
	}
	printf("Devam etmek icin bir tusa basiniz...\n");
	getch();
	
}