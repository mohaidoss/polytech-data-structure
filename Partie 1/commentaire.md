23 mai
------

Le dépôt git n'est pas très propre. 
- Il ne devrait contenir que des fichiers 'sources' mais il contient 
    des résultats de compilation. Il est possible de les retirer avec 'git rm'.

Fuite mémoire à l'exécution :
==8884== HEAP SUMMARY:
==8884==     in use at exit: 168 bytes in 7 blocks
==8884==   total heap usage: 9 allocs, 2 frees, 5,288 bytes allocated

L'affichage au format dot n'est pas réalisé.
