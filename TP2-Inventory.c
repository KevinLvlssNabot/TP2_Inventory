#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAILLE_MAX 15

typedef struct Items_t items;

struct Items_t{
  char nom[15];
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


int main() {

  items epee = {"Epee", 50, 10};
  items bouclier = {"Bouclier", 75, 10};
  items chapeau = {"Chapeau", 100, 10};
  items armure = {"Armure", 150, 10};
  items sandales = {"Sandales", 200, 10};
  items objetCree = {};
  char nomTemp[TAILLE_MAX];

shop magasin = {NULL};


magasin.items_list = malloc(6* sizeof(items*));

magasin.items_list[0]= &epee;
magasin.items_list[1]= &bouclier;
magasin.items_list[2]= &chapeau;
magasin.items_list[3]= &armure;
magasin.items_list[4]= &sandales;
magasin.items_list[5]= &objetCree;


  int objetPerso = 0;
  int choix;
  int confirmation = 5;



  int continuer = 1;
  int mambas = 1000;

while (mambas > epee.prix) {


  Color(15,0);        printf("-----------------------Marchand-------------------------     \n");
  Color(15,0);        printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |     \n");
  Color(15,0);        printf("--------------------------------------------------------     \n");
  Color(15,0);        printf("   %s       |            %d          |     x%d       |     \n", magasin.items_list[0]->nom, magasin.items_list[0]->prix, magasin.items_list[0]->quantite);
  Color(15,0);        printf("   %s   |            %d          |     x%d       |     \n", magasin.items_list[1]->nom, magasin.items_list[1]->prix, magasin.items_list[1]->quantite);
  Color(15,0);        printf("   %s    |            %d         |     x%d       |     \n", magasin.items_list[2]->nom, magasin.items_list[2]->prix, magasin.items_list[2]->quantite);
  Color(15,0);        printf("   %s     |            %d         |     x%d       |     \n", magasin.items_list[3]->nom, magasin.items_list[3]->prix, magasin.items_list[3]->quantite);
  Color(15,0);        printf("   %s   |            %d         |     x%d       |     \n", magasin.items_list[4]->nom, magasin.items_list[4]->prix, magasin.items_list[4]->quantite);
  Color(15,0);      if (objetPerso  == 1) {printf("   %s   |            %d         |     x%d       |\n", magasin.items_list[5]->nom, magasin.items_list[5]->prix, magasin.items_list[5]->quantite);}                                                                               Color(15,0);

Color(5,0);                                 printf( "                                                                   ------------Joueur---------\n");
Color(5,0);                                  printf( "                                                                         Nom     |   Quantites   |\n");
Color(5,0);                                  printf( "                                                                   ----------------------------\n");
Color(5,0);  if (epee.quantiteJoueur > 0) {  printf( "                                                                      %s       |     x%d       |\n", magasin.items_list[0]->nom,  magasin.items_list[0]->quantiteJoueur);}
Color(5,0);  if (bouclier.quantiteJoueur > 0) {  printf( "                                                                      %s   |     x%d       |\n", magasin.items_list[1]->nom,  magasin.items_list[1]->quantiteJoueur);}
Color(5,0);  if (chapeau.quantiteJoueur > 0) {  printf( "                                                                       %s    |     x%d       |\n", magasin.items_list[2]->nom,  magasin.items_list[2]->quantiteJoueur);}
Color(5,0);  if (armure.quantiteJoueur > 0) {  printf( "                                                                      %s     |     x%d       |\n", magasin.items_list[3]->nom, magasin.items_list[3]->quantiteJoueur);}
Color(5,0);  if (sandales.quantiteJoueur > 0) {  printf( "                                                                      %s   |     x%d       |\n", magasin.items_list[4]->nom, magasin.items_list[4]->quantiteJoueur);}
Color(5,0); if (objetCree.quantiteJoueur > 0)  {  printf( "                                                                      %s   |     x%d       |\n", magasin.items_list[5]->nom, magasin.items_list[5]->quantiteJoueur);}
 printf("                                                                                                                                                                                                         Mambas: %d\n", mambas);

Color(15,0);
      printf("Que voulez-vous acheter ?\n");
      if (objetPerso == 1) {
        printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
      } else {
      printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
    }
        scanf("%d", &choix);

              if (choix == 0) {
                if (epee.quantite > 0) {
                  printf("Voici une %s.\n", epee.nom);
                  epee.quantite = epee.quantite-1;
                  epee.quantiteJoueur = epee.quantiteJoueur+1;
                  mambas = mambas - epee.prix;
                } else if (epee.quantite == 0){
                      printf("Nous ne possedons plus cet objet, veuillez-nous pardonner.\n");
                      printf("Que voulez-vous acheter ?\n");
                      if (objetPerso == 1) {
                        printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                      } else {
                      printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                    }
                        scanf("%d", &choix);
                    }
            }

                if (choix == 1) {
                    if (bouclier.quantite > 0) {
                      printf("Voici un %s.\n", bouclier.nom);
                      bouclier.quantite = bouclier.quantite-1;
                      bouclier.quantiteJoueur = bouclier.quantiteJoueur+1;
                      mambas = mambas - bouclier.prix;
                    } else if (bouclier.quantite == 0){
                          printf("Nous ne possédons plus cet objet, veuillez-nous pardonner.\n");
                          printf("Que voulez-vous acheter ?\n");
                          if (objetPerso == 1) {
                            printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                          } else {
                          printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                        }
                            scanf("%d", &choix);
                        }
            }

              if (choix == 2) {
                if (chapeau.quantite > 0) {
                  printf("Voici un %s.\n", chapeau.nom);
                  chapeau.quantite = chapeau.quantite-1;
                  chapeau.quantiteJoueur = chapeau.quantiteJoueur+1;
                  mambas = mambas - chapeau.prix;
                } else if (chapeau.quantite == 0){
                    printf("Nous ne possédons plus cet objet, veuillez-nous pardonner.\n");
                    printf("Que voulez-vous acheter ?\n");
                    if (objetPerso == 1) {
                      printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                    } else {
                    printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                  }
                      scanf("%d", &choix);
                  }
            }

              if (choix == 3) {
                if (armure.quantite > 0) {
                  printf("Voici une %s.\n", armure.nom);
                  armure.quantite = armure.quantite-1;
                  armure.quantiteJoueur = armure.quantiteJoueur+1;
                  mambas = mambas - armure.prix;
              }  else if (armure.quantite == 0){
                        printf("Nous ne possédons plus cet objet, veuillez-nous pardonner.\n");
                        printf("Que voulez-vous acheter ?\n");
                        if (objetPerso == 1) {
                          printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                        } else {
                        printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                      }
                          scanf("%d", &choix);
                      }
             }

              if (choix == 4) {
                if (sandales.quantite > 0) {
                  printf("Voici des %s.\n", sandales.nom);
                  sandales.quantite = sandales.quantite-1;
                  sandales.quantiteJoueur = sandales.quantiteJoueur+1;
                  mambas = mambas - sandales.prix;
              }  else {
                      printf("Nous ne possédons plus cet objet, veuillez-nous pardonner.\n");
                      printf("Que voulez-vous acheter ?\n");
                      if (objetPerso == 1) {
                        printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                      } else {
                      printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                    }
                        scanf("%d", &choix);
                    }
            }

              if (choix == 5) {
                printf("Vous desirez creer un objet ? Cela vous coutera 500 mambas.\n");
                printf("0 pour oui, 1 pour non.\n");
                scanf("%d", &confirmation);
                  if (confirmation == 0) {
                      objetPerso = objetPerso+1;
                      mambas = mambas - 500;
                      printf("Comment souhaitez-vous appeler votre objet ?\n");
                      scanf("%s", nomTemp);
                      sprintf(magasin.items_list[5]->nom,"%s" ,nomTemp);
                    //  strcpy(objetCree.nom, nomTemp[TAILLE_MAX]);
                      printf("Combien doit-il couter ?\n");
                      scanf("%d", &objetCree.prix);
                      printf("Combien voulez-vous en creer ?\n");
                      scanf("%d", &objetCree.quantite);
                  } else {
                    continue;
                  }
              }
                      if (objetPerso == 1 && choix == 6) {
                        if (objetCree.quantite > 0) {
                          printf("Voici un/une %s.\n", objetCree.nom);
                          objetCree.quantite = objetCree.quantite-1;
                          objetCree.quantiteJoueur = objetCree.quantiteJoueur+1;
                          mambas = mambas - objetCree.prix;
                      }  else if (objetCree.quantite == 0){
                            printf("Nous ne possédons plus cet objet, veuillez-nous pardonner.\n");
                            printf("Que voulez-vous acheter ?\n");
                            if (objetPerso == 1) {
                              printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet, 6 pour acheter votre objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                            } else {
                            printf("0 pour une %s, 1 pour un %s, 2 pour un %s, 3 pour un %s, 4 pour une %s, 5 pour creer un objet.\n", magasin.items_list[0]->nom, magasin.items_list[1]->nom, magasin.items_list[2]->nom, magasin.items_list[3]->nom, magasin.items_list[4]->nom);
                          }
                              scanf("%d", &choix);
                          }
                    }

          //  printf("%d\n", objetCree.quantiteJoueur);

  }
// system("cls");



printf("Desole, vous n'avez plus assez d'argent pour acheter quoi que ce soit.\n");










  return 0;
}
