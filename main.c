#include <stdio.h>
#include <stdlib.h>
#include "Partie 1.h"
#include "Partie 2.h"

int main(int argc, char *argv[])
{

    Element* l;
    traduire();
    l = creer_liste_lettres();

   print_list(l);
   printf("\n");

    Tree a = NULL;
    a = tree_huffman(l);

    print_tree(a);

    l = creer_liste_lettres();
    dico_huffman(a, l);


    free(a);
    free(l);

    return 0;
}

