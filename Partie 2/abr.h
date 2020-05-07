#ifndef ABR_H
# define ABR_H

#include <wchar.h>

#define MAXLEN 80
typedef wchar_t wstring [MAXLEN];

struct val{
    wstring clef;
    wstring satellite;
};

struct abr {
    struct abr* gauche;
    struct val valeur;
    struct abr* droite;
};
#define NIL (struct abr*)0

extern struct abr* ajout_abr( struct abr* ,wstring ,wstring);
extern void clear_abr(struct abr*);
extern void afficher_abr(struct abr*);
extern int hauteur_abr(struct abr*);
extern int nombre_noeuds_abr(struct abr*);
extern wchar_t* recherche_abr(struct abr*,wstring);

#endif  //ABR_H
