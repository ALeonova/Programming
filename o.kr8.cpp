#include <stdio.h>

struct Note
{
	char lastname[20];
	char otdel[20];
	int birthday[3];
	char pol;
};


void pens()
{
	int curyear = 2017;
	int w=curyear-55;
	int m=curyear-60;
	int k=0;
	
	FILE* pf = fopen("note.txt", "r");
	
	while (!feof(pf)) 
	{
		Note n;
		fscanf(pf,"%s", n.lastname);
		
		if(feof(pf))
			break;
		
		fscanf(pf, "%s %d %d %d %c", n.otdel, &n.birthday[0], &n.birthday[1], &n.birthday[2], &n.pol);
			
		if (n.pol=='w' || n.pol=='W')
		{
			if (n.birthday[2]!=w)
				continue;
		}
		else
		{
			if (n.birthday[2]!=m)
				continue;
		}
		k++;
		printf("%s %s %d %d %d %c\n", n.lastname, n.otdel, n.birthday[0], n.birthday[1], n.birthday[2], n.pol);
	}
	if (k==0)
		printf("Doesn't exist");
	
	fclose(pf);
}

int main() 
{	
	pens();
	return 0;
}

