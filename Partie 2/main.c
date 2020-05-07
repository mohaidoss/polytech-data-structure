/* main-eofr-abr.c */

#include <locale.h>
#include <wctype.h>
#include <assert.h>
#include <stdio.h>
#include "abr.h"

int main ()
{   struct abr* racine;
    wstring clef;
    wstring satellite;
    wint_t c;
    FILE* f;

    assert (setlocale (LC_ALL, "fr_FR.UTF-8") != NULL);
    f = fopen ("Esperanto-Francais.utf8", "r");
    assert (f != (FILE*)0);

    racine = NIL;
    c = fgetwc (f);
    while (c != WEOF)
    {   int i = 0;
        while (c != L':')
        {   clef [i] = c;
            i += 1;
            c = fgetwc (f);
        }
        clef [i] = L'\0';
        c = fgetwc (f);
        i = 0;
        while (c != L'\n')
        {   satellite [i] = c;
            i += 1;
            c = fgetwc (f);
        }
        satellite [i] = L'\0';
        racine = ajout_abr (racine, clef, satellite);
        c = fgetwc (f);
    }
    fclose (f);
    afficher_abr (racine);
    {   wchar_t* p;
        wprintf(L"recherche...\n");
        p = recherche_abr (racine, L"abateja");
        wprintf(L"traduction de: abateja = %ls\n", p);
    }
    wprintf (L"le hauteur est %d\n",hauteur_abr(racine) );
    clear_abr (racine);
    return 0;
}

