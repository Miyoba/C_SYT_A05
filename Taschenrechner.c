/*Taschenrechner*/
#include <stdio.h>
#include <stdlib.h>
/*Prototypen*/
int addition(int,int);
int subtraktion(int,int);
int division(int,int);
int multiplikation(int,int);

int(*fup[4])(int,int);
/*
Ein Programm das die Grundfunktionen eines Taschenrechners besitzt
@Author: Wolfgang Mair,Vogt Andreas
@Version: 2013-10-18
*/
int main(int argc, char* argv[])
{
	/*Die Attribute Deklarieren*/
	char zeichen; /* Zeichen das eingegeben wurde ( sollte +,-,/,* sein sonst Fehlermeldung)*/
	int erg = 0; /* Variable in der das erg gespeichert wird */
	int zahl1,zahl2; /*Zahlen die eingeben werden*/
	/* Pointer die auf die Funktionen zeigen*/
	*fup = addition;
	*(fup+1) = subtraktion;
	*(fup+2) = division;
	*(fup+3) = multiplikation;
	
	/*Eine Schleife die überprüft ob die Eingabe akzeptabel war*/
	do
	{
		printf("Geben sie ein wie sie die Zahlen berechnen wollen.\n(+ , - , / , *)");
		scanf("%c",&zeichen);
		
		/* Ein switch der überprüft welches zeichen eingegeben wurde*/
		switch(zeichen)
		{
			/* Bei + werden zahl1 und zahl2 addiert */
			case '+':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				printf("\nAdditions ergebnis = %d\n",(*fup)(zahl1,zahl2));
				break;
			/* Bei - wird zahl2 von zahl1 subdrahiert */
			case '-':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				printf("\nSubtraktions ergebnis = %d\n",(*(fup+1))(zahl1,zahl2));
				break;
			
			/* Bei / dividiert man zahl1 durch zahl2 */
			case '/':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				if(zahl2 == 0)
					printf("\nDivision durch 0!\n");
				else
					printf("\nDivisions ergebnis = %d\n",(*(fup+2))(zahl1,zahl2));
					
				break;
			/* Bei * werden zahl1 und zahl2 multipliziert */
			case '*':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				printf("\nMultiplikations ergebnis = %d\n",(*(fup+3))(zahl1,zahl2));
				break;
					
			default:
				printf("\nFalsche Eingabe! Denken sie nach wollten sie wirklich %c eingeben?\n",zeichen);
				break;	
		}
		/* Falls das Programm erfolgreich war oder durch einen Fehler abgebrochen wurde
		wird gefragt ob man eine weitere Eingabe machen möchte W*/
		printf("Wollen sie eine weitere Eingabe machen? (y/n)\n");
		scanf("%c",&zeichen);
		zeichen = tolower(zeichen);
		
		switch(zeichen)
		{
			/*Falls das eingebene Zeichen ein "y" ist wiederholt er die Schleife*/ 
			case 'y':
				erg = 0;
				break;
			/*Falls das eingebene Zeichen ein "n" ist bricht er die Schleife ab und beendet das Programm*/	
			case 'n':
				erg = 1;
				break;
			/*Falls es etwas anderes ist wird eine Fehlermeldung ausgegeben die Schleife abgebrochen und das Programm beendet*/
			default:
				printf("Fehler beenden des Programmes");
				return EXIT_FAILURE;
				break;
		}
	}
	while(erg == 0);
	
	return EXIT_SUCCESS;
}

/*Definierung der Methoden*/
/*Die Methode addition addiert parameter1 mit parameter 2*/
int addition(int nr1,int nr2)
{
	return nr1+nr2;
}
/*Die Methode subtraktion subtrahiert parameter1 mit parameter 2*/
int subtraktion(int nr1,int nr2)
{
	return nr1-nr2;
}
/*Die Methode division dividiert parameter1 mit parameter 2*/
int division(int nr1,int nr2)
{
	return nr1/nr2;
}
/*Die Methode multiplikation multipliziert parameter1 mit parameter 2*/
int multiplikation(int nr1,int nr2)
{
	return nr1*nr2;
}
	