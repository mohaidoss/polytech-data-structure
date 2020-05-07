#include "abr.h"
#include <stdio.h>
int main(){
  struct abr* racine;
  int x;
  racine = NIL;
  scanf("%d",&x);
  while(x != -1){
    racine = ajouter_abr(x,racine);
    afficher_abr(racine);
    printf("\n");
    scanf("%d",&x);
    printf("\n");
  }
  printf("La hauteur de l'ABR est %d\n", hauteur_abr(racine));
  printf("Le nombre de noeuds de l'ABR est %d\n", nombre_noeuds_abr(racine));
  clear_abr(racine);
  return 0;
}
