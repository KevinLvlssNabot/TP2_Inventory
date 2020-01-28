#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Items_t items;

struct Items_t{
  char* nom;
  int prix;
  int quantite;
};

typedef struct Shop_t shop;

struct Shop_t{
  items **items_list;

};



int main() {

  items epee = {"Epee", 50, 10};
  items bouclier = {"Bouclier", 75, 10};
  items chapeau = {"Chapeau", 100, 10};
  items armure = {"Armure", 150, 10};
  items sandales = {"Sandales", 200, 10};

shop magasin = {{NULL}};
magasin.items_list = malloc(5* sizeof(items*));

magasin.items_list[0]= &epee;
magasin.items_list[1]= &bouclier;
magasin.items_list[2]= &chapeau;
magasin.items_list[3]= &armure;
magasin.items_list[4]= &sandales;



  int continuer = 1;
while (continuer == 1) {

  int choix;
          printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |\n");
          printf("--------------------------------------------------------------------\n");
          printf("   %s       |            %d          |     x%d       |\n", magasin.items_list[0]->nom, magasin.items_list[0]->prix, magasin.items_list[0]->quantite);
          printf("   %s   |            %d          |     x%d       |\n", magasin.items_list[1]->nom, magasin.items_list[1]->prix, magasin.items_list[1]->quantite);
          printf("   %s    |            %d         |     x%d       |\n", magasin.items_list[2]->nom, magasin.items_list[2]->prix, magasin.items_list[2]->quantite);
          printf("   %s     |            %d         |     x%d       |\n", magasin.items_list[3]->nom, magasin.items_list[3]->prix, magasin.items_list[3]->quantite);
          printf("   %s   |            %d         |     x%d       |\n", magasin.items_list[4]->nom, magasin.items_list[4]->prix, magasin.items_list[4]->quantite);


      printf("Que voulez-vous acheter ?\n");
        scanf("%d", &choix);
            if (choix == 0) {
              epee.quantite = epee.quantite-1;
            }


            printf("      Nom     |   Prix (mambas d'or)   |   Quantites   |\n");
            printf("--------------------------------------------------------------------\n");
            printf("   %s       |            %d          |     x%d       |\n", magasin.items_list[0]->nom, magasin.items_list[0]->prix, magasin.items_list[0]->quantite);
            printf("   %s   |            %d          |     x%d       |\n", magasin.items_list[1]->nom, magasin.items_list[1]->prix, magasin.items_list[1]->quantite);
            printf("   %s    |            %d         |     x%d       |\n", magasin.items_list[2]->nom, magasin.items_list[2]->prix, magasin.items_list[2]->quantite);
            printf("   %s     |            %d         |     x%d       |\n", magasin.items_list[3]->nom, magasin.items_list[3]->prix, magasin.items_list[3]->quantite);
            printf("   %s   |            %d         |     x%d       |\n", magasin.items_list[4]->nom, magasin.items_list[4]->prix, magasin.items_list[4]->quantite);
printf("%d\n", epee.quantite);

}
  items inventaires[20];













  return 0;
}
