//  gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o liste-chaine-main 

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e) {
	printf("%s",(char*)e);
}

void detruireElement(Element e) {
	free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
  bool b = true;
  int i = 0;
  while (b && e1[i]!='\0')
  {
    b = e1[i]==e2[i];
    i++;
  }
	return b && e2[i]=='\0';
}

char* creerString(char valeur, int nombre){
  char *c = (char*) malloc((nombre+1)*sizeof(char));
  for (int i = 0; i < nombre; i++)
  {
    c[i]=valeur;
  }
  c[nombre]='\0';
  return c;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    l = ajoutTete("!!",l);
    l = ajoutTete("brocolis",l);
    l = ajoutTete("les",l);
    l = ajoutTete("J'aime",l);
    

	afficheListe_i(l);

	ajoutFin_i("Et toi",l);
	afficheListe_i(l);

	ajoutFin_r("?",l);
	afficheListe_i(l);

	printf("\nliste a l'envers : ");
	afficheEnvers_r(l);

	p = cherche_i("les",l);
	printf("\ncherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	detruire_r(l);
	return EXIT_SUCCESS;
}