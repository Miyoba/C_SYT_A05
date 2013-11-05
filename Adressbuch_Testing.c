#include <stdio.h>
#include <stdlib.h>

void hinzufuegen(char* namet[], char* adresset[]);
void ausgeben (int stelle, person* p, adress* a);

typedef struct
{
	char n[100];
	char* name;
	int anz;
	name = n;
	name = mailloc(sizeof(*name));
	free(name);
}person;

typedef struct{
	char a[100];
	char* adresse;
	int anz;
	adresse = a;
	name = malloc(sizeof(*adresse));
	free(adresse);																																																		
}adress;

int main (int argc , char* argv[])
{
	person* p;
	adress* a;

	int stelle = 0;
	char textn[100];
	char texta[100];
	int anzN;
	int anzA;
	
	printf("Geben sie einen Personennamen ein");
	anzN = scanf("%s",textn);
	printf("Geben sie einen Adresse ein");
	anzA = scanf("%s",texta);
	  
	  
}

void hinzufuegen (char* namet[],char* adresset[]){
	p = realloc(p,1+sizeof(person));
	int i;
	size_t ln;
	ln = strlen(namet);
	size_t la;
	la = strlen(adresset);
	for(i=0;i<ln;i++){
		p[stelle].name[i] = namet[i] ;
		p[stelle].name = malloc(1+sizeof(*name));
	}
	for(i=0;i<la;i++){
		a[stelle].adresse[i]  = adresset[i];
		a[stelle].adresse = malloc(1+sizeof(*adresse);
	}
	stelle++;
}

void ausgeben (int stelle, person* p, adress* a){
	
	int i,z;
	for(i=0; i<stelle; i++){
		for(z=0; z<p[i].anz;z++){
			printf("%c",p[i].name[z]);
		}
		for(z=0; z<p[i].anz;z++){
			printf("%c",a[i].adresse[z]);
		}
		printf("\n");
	}
}