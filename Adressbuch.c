#include <stdio.h>
#include <stdlib.h>
#define stellep 0
#define stellea 0

void hinzufuegen(char[] *pointer,char[] *pointer);
void ausgeben();


int main (int argc , char* argv[])
{
	  char textn[30];
	  char *pointern;
	  char texta[30];
	  char *pointera;
	  printf("Geben sie einen Personennamen ein");
	  scanf("%c",textn);
	  printf("Geben sie einen Adresse ein");
	  scanf("%c",texta);
	  
	  
}

typedef struct
{
	char n [];
	char * name ;
	name = n;
	name = mailloc(sizeof(*name));
	free(name);
}person;
typedef struct{
	char a [];
	char * adresse;
	adresse = a;
	name = malloc(sizeof(*adresse));
	free(adresse)																																																		
}adress;

void hinzufuegen (char[] namet,char[] adresset){
	person p1;
	adress a1;
	int i;
	size_t ln;
	ln = strlen(namet);
	size_t la;
	la = strlen(adresset);
	for(i=0;i<la;i++){
		p1.name [stellep] = namet[i] ;
		p1.name = malloc(1+sizeof(*name));
		stellep++;
	}
		a1.adresse [stellea] = adresset[];
		a1.adresse = malloc(1+sizeof(*adresse);
		stellea++;
	}
}

void ausgeben (){
	person p1;
	adress a1;
	int i;
	for(i=0; i<stellep; i++){
		printf("%c",p1.name[i]);
		}
	for(i=0; i<stellep; i++){
		printf("%c",a1.adresse[i]);
	}
}