#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

void BFS(int **ydk,int start,int nn);
void bfsdondur(int **ydk,int nn);
int dequeue();
int isEmpty();
void enqueue(int );
void sifirla(int **, int );
void DFS(int **ters,int start,int n);
void influencer(int x, int y, int** ters, int**matrix, int*vstd ,int n);

//void bfsdondur(int**,int);



int main ()
{

	struct Node
	{
		int data;
		struct Node *next;
	}*front=NULL,*rear=NULL;


	char dizi[100][50];
	int i;
	int j;
	char sayi[4]={'0','0','0','\0'};
	int num;
	int M;
	int Y;
	int X;
	int flag=0;
	int count=0;
	int e=0;



	printf("%s", sayi);
	printf("\n");
	printf("\n");

	printf("M degerini giriniz? \n");
	scanf("%d",&M);

	printf("Birinci bolumdeki in-degree X degerini giriniz? \n");
	scanf("%d",&X);

	printf("Ikinci bolumdeki gelen toplam vertice Y degerini giriniz? \n");
	scanf("%d",&Y);


// file read

	FILE *file;

	file= fopen("socialNET.txt","r");

	if (file==NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	int line=0;


	while (!feof(file) && !ferror(file))
	{
		if(fgets(dizi[line],50,file) != NULL)
		{
			line++;
		}
	}

	fclose(file);

	for(i=0;i<line;i++)
	{
		printf("%s",dizi[i]);
	}

	printf("\n");
	printf("\n");

// matrix olustur

int **matrix;

matrix = (int**)(malloc(((line/2)+1)*sizeof(int*)));

for(i=0;i<((line/2)+1);i++)
{
	matrix[i]=(int*)(malloc(((line/2)+1)*sizeof(int)));
}

int n = (line/2)+1;

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		matrix[i][j]= 0;
	}
}

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d", matrix[i][j]);
	}

	printf("\n");
}

printf("\n");


// dizi to matrix

j=0;
i=1;
int k=1;
int x=0;
int z=0;
num=0;

while(i <= line)
{

   	while((dizi[i][j]!='\0')&& (dizi[i][j]!=' ') && (dizi[i][j]!='\n'))
   	{


		while((dizi[i][j]!=',') && (dizi[i][j]!='\0') && (dizi[i][j]!=' ')&& (dizi[i][j]!='\n'))
		{
		sayi[x]	=dizi[i][j];
		x++;
		j++;
		}


		while(x<4)
		{
			sayi[x]='\0';
			x++;
		}

		if(dizi[i][j]!='\n')
		{
			j++;
		}

		//j++;
		x=0;

		z=0;
		while(z<4)
		{
			if((sayi[z] != '\0'))                   // && (sayi[z] != '0'))
			{
				num = num*10 + (sayi[z] - '0');
		    }

			z++;
		}

	    //num	= atoi(sayi);

	    printf("%d \n", num);

		matrix[k][num]=1;
		num=0;

		sayi[0]='0';
		sayi[1]='0';
		sayi[2]='0';
		sayi[3]='\0';


	}

 k++;
 i=i+2;
 j=0;
}


printf("matrix: \n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
	printf("%d", matrix[i][j]);
	}
	printf("\n");
}


// yedekleme

int **yedek;

yedek = (int**)(malloc(((line/2)+1)*sizeof(int*)));

for(i=0;i<((line/2)+1);i++)
{
	yedek[i]=(int*)(malloc(n *sizeof(int)));
}

for(i=0;i<((line/2)+1);i++)
{
	for(j=0;j<((line/2)+1);j++)
	{
		yedek[i][j]=matrix[i][j];
	}
}

printf("\n");
printf("yedek: \n");

for(i=0;i<(line/2)+1;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d",yedek[i][j]);
	}
	printf("\n");
}

printf("\n");
printf("\n");

//ters matrix

int **ters;

ters = (int**)(malloc(((line/2)+1)*sizeof(int*)));

for(i=0;i<((line/2)+1);i++)
{
	ters[i]=(int*)(malloc(n *sizeof(int)));
}


int *kayit;
kayit = (int*)(malloc(((line/2)+1)*sizeof(int)));

for(i=0;i<n;i++)
{
	kayit[i]=1;
}

for(i=0;i<((line/2)+1);i++)
{
	for(j=0;j<((line/2)+1);j++)
	{
		ters[j][i]=yedek[i][j];
	}
}

printf("\n");
printf("\n");
printf("ters: \n");

for(i=0;i<(line/2)+1;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d",ters[i][j]);
	}
	printf("\n");
}

printf("\n");
printf("\n");


int *vstd;
vstd = (int*)(malloc(((line/2)+1)*sizeof(int)));

for(i=0;i<n;i++)
{
	vstd[i]=0;
}





void sifirla(int **ydk, int tmp)
{
	int i;

	for(i=0;i<((line/2)+1);i++)
	{
		ydk[i][tmp]= 0;
	}

	for(i=0;i<((line/2)+1);i++)
	{
		ydk[tmp][i]= 0;
	}

}

void enqueue(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));

	if(t==NULL)
	printf("Queue is FUll\n");
		else
		{
			t->data=x;
			t->next=NULL;
			if(front==NULL)
			front=rear=t;

				else
				{
					rear->next=t;
					rear=t;
				}
		}
}



int dequeue()
{
	int x=-1;
	struct Node* t;

	if(front==NULL)
	{
		printf("Queue is Empty\n");
	}

	else
	{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}

	return x;
}

int isEmpty()
	{
		return front==NULL;
	}




void BFS(int **ydk,int start,int nn)
{
	int i=start,j;
	int temp;
	int k;
	int count=0;

	int visited[7]={0};

	printf("%d ",i);
	visited[i]=1;
	enqueue(i);

	while(!isEmpty())
	{
		i=dequeue();
		temp=i;
		for(j=1;j<nn;j++)
		{

			if(ydk[i][j]==1 && visited[j]==0)
			{
				printf("%d ",j);
				visited[j]=1;
				enqueue(j);
			}
		}


		for(k=1;k<((line/2)+1);k++)
		{
			if(ydk[k][temp]== 1)
			{
				count++;
			}

		}

		if(count<M)
		{
			sifirla(ydk,temp);
			kayit[temp]=0;
		}

		count=0;

	}
}



void bfsdondur(int **ydk,int nn)
{

	for(i=1;i<nn;i++)
	{
		BFS(ydk,i,nn);
	}

}


//BFS gönder

for(i=1;i<n;i++)
{
	BFS(yedek,i,n);
}

count=0;


while(flag==0)
	{

		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(yedek[j][i]==1)
				{
					count++;
				}
			}

			if((count<M)&&(kayit[j]==1))
			{
				bfsdondur(yedek,n);
				flag=1;
			}

			count=0;

	}

	if(flag==1)
	{
		flag=0;
	}
	else
	{
		flag=1;
	}

}


printf("\n");
printf("yedek son hali: \n");

for(i=0;i<(line/2)+1;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d",yedek[i][j]);
	}
	printf("\n");
}

printf("\n");
printf("\n");


for(i=0;i<((line/2)+1);i++)
{
	for(j=0;j<((line/2)+1);j++)
	{
		ters[j][i]=yedek[i][j];
	}
}

int nom;
printf("Kac adet dugumden erisilebilecegini ogrenmek istediginiz dugumun numarasini yaziniz: \n");
scanf("%d",&nom);


void DFS(int **ters,int start,int nn)
{

	int j;

	if(vstd[start]==0)
	{
		printf("%d ",start);

		vstd[start]=1;

			for(j=1;j<nn;j++)
			{
				if((ters[start][j]==1) && (vstd[j]==0))
				{
					DFS(ters,j,nn);
				}

			}
	}
}

DFS(ters,nom,n);



printf("\n");
printf("vstd dizisi: \n");

for(i=0;i<n;i++)
{
	printf("%d ",vstd[i]);
}

int sayac=0;

printf("\n");





for(i=1;i<n;i++)
{
	if((i!=nom) && (vstd[i]==1))
	{
		printf("%d ",i);
		sayac++;
	}

}

printf("\n");

printf("sayac: %d",sayac);

printf("\n");


printf("\n");
printf("Graftaki bütün düðümlerin baþlangýç durumunda in-degree deðerleri");
printf("\n");

e=0;
for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
	   		if(matrix[j][i]==1)
	   		e++;
		}
		printf("%d 'in in-degree degeri: %d\n", i, e);
		e=0;
	}


printf("\n");
printf("Verilen M deðeri için elenmeyen düðümlerin in-degree");
printf(" degerleri ve bu dugumlerdeki kisilerin ad-soyad bilgileri: ");
printf("\n");

  e=0;
for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
	   		if(yedek[j][i]==1)
	   		e++;
		}
		if(e>0)
		{
			printf("%d 'in in-degree degeri: %d\n", i, e);
			switch (i) {
							  case 1:
							    printf("Michael Jordan");
							    break;
							  case 2:
							    printf("Stephen Boyd");
							    break;
							  case 3:
							    printf("Kalyanmoy Deb");
							    break;
							  case 4:
							    printf("David Johnson");
							    break;
							  case 5:
							    printf("Scott Kirkpatrick");
							    break;
							  case 6:
							    printf("Lieven Vandenberghe");
							    break;
							  case 7:
							    printf("Fabian Pedregosa");
							    break;
							   case 8:
							    printf("Jorge Nocedal");
							    break;
							  case 9:
							    printf("Clifford Stein");
							    break;
							  case 10:
							    printf("Stephen Wright");
							    break;
							  case 11:
							    printf("Philippe Salembier");
							    break;
							  case 12:
							    printf("Robert Stevenson");
							    break;
							}
							printf("\n");
		}

		e=0;
	}



	printf("\n");
	printf("\n");


for(i=0;i<n;i++)
{
	vstd[i]=0;
}

void influencer(int x, int y, int** ters, int**matrix, int* vstd, int n)
{

	int i;
	int j;
	int syc=0;
	int sayici=0;

	for(i=1;i<n;i++)
	{
   		syc=0;
   		sayici=0;

		DFS(ters,i,n);

		for(j=1;j<n;j++)
		{
			if((j!=i) && (vstd[j]==1))
			{
				//printf("%d ",i);
				syc++;
			}
		}

		for(j=1;j<n;j++)
		{
	   		if(matrix[j][i]==1)
	   		sayici++;
		}

			if((syc >= y) &&(sayici >= x))
			{
				printf("\n");
				printf("Kisi: %d in degree degeri: %d gelen vertice degeri: %d \n", i, sayici ,syc );

				switch (i) {
							  case 1:
							    printf("Michael Jordan");
							    break;
							  case 2:
							    printf("Stephen Boyd");
							    break;
							  case 3:
							    printf("Kalyanmoy Deb");
							    break;
							  case 4:
							    printf("David Johnson");
							    break;
							  case 5:
							    printf("Scott Kirkpatrick");
							    break;
							  case 6:
							    printf("Lieven Vandenberghe");
							    break;
							  case 7:
							    printf("Fabian Pedregosa");
							    break;
							   case 8:
							    printf("Jorge Nocedal");
							    break;
							  case 9:
							    printf("Clifford Stein");
							    break;
							  case 10:
							    printf("Stephen Wright");
							    break;
							  case 11:
							    printf("Philippe Salembier");
							    break;
							  case 12:
							    printf("Robert Stevenson");
							    break;
							}
							printf("\n");
			}

			for(j=0;j<n;j++)
			{
				vstd[j]=0;
			}
	}
}


influencer(X, Y, ters, matrix, vstd,n);



	return 0;
}
