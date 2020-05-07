#include "abr.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
static struct abr* new_feuille(int x){
  struct abr* F;
  F = malloc(sizeof(struct abr));
  F->gauche = NIL;
  F->droite = NIL;
  F->valeur = x;
  return F;
}

struct abr* ajouter_abr(int x, struct abr* racine){
  struct abr* f_courant;
  struct abr* f_pere;
  struct abr*f_new;

  f_new = new_feuille(x);

  if (racine == NIL)
    return f_new;
  else  {
    f_pere = NIL;
    f_courant = racine;
    while (f_courant != NIL){
      assert (f_courant->valeur != x);
      f_pere = f_courant;
      if (f_courant->valeur < x)
        f_courant = f_courant->droite;
      else
        f_courant = f_courant->gauche;
    }

    if (f_pere->valeur < x)
      f_pere->droite = f_new;
    else
      f_pere->gauche = f_new;
    return racine;
  }
}

void clear_abr(struct abr* racine){
}

void afficher_abr(struct abr* racine){
 if (racine != NIL){
   afficher_abr(racine->gauche);
   printf("%d ", racine->valeur);
   afficher_abr(racine->droite);
 }
}

static int max(int a,int b){
  if (a>b)
    return a;
  return b;
}

int hauteur_abr(struct abr* racine){
 if (racine == NIL)
   return 0;
 else {
   int fg,fd;
   fg = hauteur_abr(racine->gauche);
   fd = hauteur_abr(racine->droite);
   return 1 + max(fg,fd);
 }
}

int nombre_noeuds_abr(struct abr* racine){
  if (racine == NIL)
    return 0;
  return (1 + nombre_noeuds_abr(racine->droite) + nombre_noeuds_abr(racine->gauche));
}
