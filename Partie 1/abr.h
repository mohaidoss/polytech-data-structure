#ifndef ABR_H
# define ABR_H

struct abr {
  struct abr* gauche;
  int valeur;
  struct abr* droite;
};

#define NIL (struct abr*)0

extern struct abr* ajouter_abr(int , struct abr*);
extern void afficher_abr(struct abr*);
extern int hauteur_abr(struct abr*);
extern int nombre_noeuds_abr(struct abr*);
extern void clear_abr(struct abr*);

#endif  //ABR_H

