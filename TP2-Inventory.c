#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Items_t items;

struct Items_t{
  char* nom;
  int prix;
  int quantite;
};

//typedef struct Inventaires_t inventaires;
//
//struct Inventaires_t{
//  char* items;
//  int prix;
//  int quantite;
//
//};



int main() {

  items epee = {"Epee", 50, 10};
  items bouclier = {"Bouclier", 75, 10};
  items chapeau = {"Chapeau", 100, 10};
  items armure = {"Armure", 150, 10};
  items sandales = {"Sandales", 200, 10};

  items shop[5];
  shop[0] = epee;
  shop[1] = bouclier;
  shop[2] = chapeau;
  shop[3] = armure;
  shop[4] = sandales;


  char choix[10];
          printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |\n");
          printf("--------------------------------------------------------------------\n");
          printf("   %s       |            %d          |     x%d       |\n", shop[0]);
          printf("   %s   |            %d          |     x%d       |\n", shop[1]);
          printf("   %s    |            %d         |     x%d       |\n", shop[2]);
          printf("   %s     |            %d         |     x%d       |\n", shop[3]);
          printf("   %s   |            %d         |     x%d       |\n", shop[4]);


      printf("Que voulez-vous acheter ?\n");
        scanf("%s", &choix);
            if (choix == "epee") {
              epee.quantite = epee.quantite-1;
            }

            printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |\n");
            printf("--------------------------------------------------------------------\n");
            printf("   %s       |            %d          |     x%d       |\n", shop[0]);
            printf("   %s   |            %d          |     x%d       |\n", shop[1]);
            printf("   %s    |            %d         |     x%d       |\n", shop[2]);
            printf("   %s     |            %d         |     x%d       |\n", shop[3]);
            printf("   %s   |            %d         |     x%d       |\n", shop[4]);
printf("%d\n", epee.quantite);

  items inventaires[20];













  return 0;
}
