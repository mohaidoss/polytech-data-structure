#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "abr.h"

#define VRAI 1
#define FAUX 0
static int max(int a,int b){
  if (a>b)
    return a;
  return b;
}
static struct abr* new_feuille(wstring c,wstring s ){
  struct abr *F;
  F = malloc(sizeof(struct abr));
  F->gauche = NIL;
  F->droite = NIL;
  wcscpy(F->valeur.clef,c);
  wcscpy(F->valeur.satellite,s);
  return F;
}
struct abr* ajout_abr(struct abr* racine,wstring c,wstring s){
  struct abr* f_courant;
  struct abr* f_pere;
  struct abr* f_new;
  f_new = new_feuille(c,s);
  if(racine == NIL)
    return f_new;
  else{
    f_pere = NIL;
    f_courant = racine;
    while(f_courant != NIL){
        f_pere = f_courant;
        assert(wcscmp(f_courant->valeur.clef,c)!=0);
        if(wcscmp(f_courant->valeur.clef,c)<0){
            f_courant = f_courant->droite;
        }
        else{
        f_courant = f_courant->gauche;
        }
  }
  if(wcscmp(f_pere->valeur.clef,c)>0) 
    f_pere->gauche = f_new;
  else f_pere->droite  = f_new;
    return racine; 
  }
}

void clear_abr(struct abr* racine){
    if(racine != NIL){
    clear_abr(racine->gauche);
    clear_abr(racine->droite);
    free(racine);
    }
}

void afficher_abr(struct abr* racine){
    if(racine != NIL)
    {
    afficher_abr(racine->gauche);
    wprintf(L"%ls : %ls\n",racine->valeur.clef,racine->valeur.satellite);
    afficher_abr(racine->droite);
    }
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

wchar_t* recherche_abr(struct abr* racine,wstring clef){
    struct abr* R;
    wchar_t* found = (wchar_t*)0;
    R = racine;
    while (R != NIL && found == (wchar_t*)0){
        if (wcscmp(R->valeur.clef,clef) == 0) 
	    found = racine->valeur.satellite;
        else if (wcscmp(R->valeur.clef,clef) < 0) 
            R = R->droite;
        else 
            R = R->gauche;
    }
    return found;
}
