#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Items_t items;

struct Items_t{
  char* nom;
  int prix;
  int quantite;
  int quantiteJoueur;
};

typedef struct Shop_t shop;

struct Shop_t{
  items **items_list;

};

void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

int compare (const void * a, const void * b)
{
  items * pA = (items *) a;
  items * pB = (items *) b;

  return (strcmp(pA->nom, pB->nom));
}

int main() {

  items epee = {"Epee", 50, 10};
  items bouclier = {"Bouclier", 75, 10};
  items chapeau = {"Chapeau", 100, 10};
  items armure = {"Armure", 150, 10};
  items sandales = {"Sandales", 200, 10};

shop magasin = {NULL};


magasin.items_list = malloc(5* sizeof(items*));

magasin.items_list[0]= &epee;
magasin.items_list[1]= &bouclier;
magasin.items_list[2]= &chapeau;
magasin.items_list[3]= &armure;
magasin.items_list[4]= &sandales;



  int continuer = 1;
  int mambas = 1000;

while (mambas > epee.prix) {
qsort (magasin.items_list, 5, sizeof(items), compare);
  int choix;
  Color(15,0);        printf("-----------------------Marchand-------------------------     ");                                                                                                      Color(5,0);    printf("-----------------------Joueur-------------------------\n");
  Color(15,0);        printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |     ");                                                                                                      Color(5,0);    printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |\n");
  Color(15,0);        printf("--------------------------------------------------------     ");                                                                                                      Color(5,0);    printf("-------------------------------------------------------\n");
  Color(15,0);        printf("   %s       |            %d          |     x%d       |     ", magasin.items_list[0]->nom, magasin.items_list[0]->prix, magasin.items_list[0]->quantite);              Color(5,0);    printf("   %s       |            %d          |     x%d       |\n", magasin.items_list[0]->nom, magasin.items_list[0]->prix, magasin.items_list[0]->quantiteJoueur);
  Color(15,0);        printf("   %s   |            %d          |     x%d       |     ", magasin.items_list[1]->nom, magasin.items_list[1]->prix, magasin.items_list[1]->quantite);                  Color(5,0);    printf("   %s   |            %d          |     x%d       |\n", magasin.items_list[1]->nom, magasin.items_list[1]->prix, magasin.items_list[1]->quantiteJoueur);
  Color(15,0);        printf("   %s    |            %d         |     x%d       |     ", magasin.items_list[2]->nom, magasin.items_list[2]->prix, magasin.items_list[2]->quantite);                  Color(5,0);    printf("   %s    |            %d         |     x%d       |\n", magasin.items_list[2]->nom, magasin.items_list[2]->prix, magasin.items_list[2]->quantiteJoueur);
  Color(15,0);        printf("   %s     |            %d         |     x%d       |     ", magasin.items_list[3]->nom, magasin.items_list[3]->prix, magasin.items_list[3]->quantite);                 Color(5,0);    printf("   %s     |            %d         |     x%d       |\n", magasin.items_list[3]->nom, magasin.items_list[3]->prix, magasin.items_list[3]->quantiteJoueur);
  Color(15,0);        printf("   %s   |            %d         |     x%d       |     ", magasin.items_list[4]->nom, magasin.items_list[4]->prix, magasin.items_list[4]->quantite);                   Color(5,0);    printf("   %s   |            %d         |     x%d       |\n", magasin.items_list[4]->nom, magasin.items_list[4]->prix, magasin.items_list[4]->quantiteJoueur);
                                                                                                                                        printf("                                                                                                      Mambas: %d\n", mambas);
Color(15,0);

      printf("Que voulez-vous acheter ?\n");
      printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
        scanf("%d", &choix);

              if (choix == 0) {
                printf("Voici une %s.\n", epee.nom);
                epee.quantite = epee.quantite-1;
                epee.quantiteJoueur = epee.quantiteJoueur+1;
                mambas = mambas - epee.prix;
              } else if (choix == 1) {
                printf("Voici un %s.\n", bouclier.nom);
                bouclier.quantite = bouclier.quantite-1;
                bouclier.quantiteJoueur = bouclier.quantiteJoueur+1;
                mambas = mambas - bouclier.prix;
              } else if (choix == 2) {
                printf("Voici un %s.\n", chapeau.nom);
                chapeau.quantite = chapeau.quantite-1;
                mambas = mambas - chapeau.prix;
                chapeau.quantiteJoueur = chapeau.quantiteJoueur+1;
              } else if (choix == 3) {
                printf("Voici une %s.\n", armure.nom);
                armure.quantite = armure.quantite-1;
                armure.quantiteJoueur = armure.quantiteJoueur+1;
                mambas = mambas - armure.prix;
              } else if (choix == 4) {
                printf("Voici des %s.\n", sandales.nom);
                sandales.quantite = sandales.quantite-1;
                sandales.quantiteJoueur = sandales.quantiteJoueur+1;
                mambas = mambas - sandales.prix;
              }


// system("cls");

}


printf("Desole, vous n'avez plus assez d'argent pour acheter quoi que ce soit.\n");










  return 0;
}
