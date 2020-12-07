#include <stdio.h>
#include <stdlib.h>
#include "Partie 2.h"

Element* create_list(int lettre)
{
    if(lettre == EOF)
    {
        exit(1);
    }
    else
    {
        Element* liste= malloc(sizeof(Element));
        liste->lettre=lettre;
        liste->occurence=1;
        liste->next= NULL;
        return liste;
    }
}

Element* creer_liste_lettres()
{
    FILE* fichier = NULL;
    Element* l = NULL;
    Element* temp = NULL;
    int stock;
    fichier = fopen("entree.txt", "r");

    if(fichier != NULL)
    {
        l = create_list(fgetc(fichier));           //Creer 1er élément séparement des autres
        while((stock = fgetc(fichier)) != EOF)
        {
            if(stock != '\n')                      //On ne comptabilise pas retour à la ligne comme un caratère
            {
                temp = l;
                while( ((temp->next) != NULL) && (stock != (temp->lettre)) )
                    temp = temp->next;
                if(stock == temp->lettre)
                    (temp->occurence)++;
                else
                    temp->next = create_list(stock);
            }
        }
    }
    return l;
}

int maximum_occurence(Element* l)
{

    Element* temp;
    temp=(l);
    int max;
    if((l)==NULL)
    {
        exit(1);
    }
    max=temp->occurence;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        if((temp->occurence) > max)
        {
            max=temp->occurence;
        }
    }

    return max;
}


int maximum_letter(Element* l)
{

    Element* temp;
    temp=(l);
    int max;
    if((l)==NULL)
    {
        exit(1);
    }
    max=temp->occurence;

    while(temp->next!=NULL)
    {
        temp=temp->next;

        if((temp->occurence) > max)
        {
            max=temp->occurence;
        }
    }

    temp=(l);

    while(temp!=NULL)
    {

        if (temp->occurence == max)
        {

            max = temp->lettre;


        }
        temp = temp->next;

    }

    return max;

}




Element* supp_element(Element** l, int maxi)
{

    Element* ancien;
    Element* temporel;
    Element* temp = (*l);

    if ( temp->occurence == maxi)
    {
        (*l)=(*l)->next;
        temp->next = NULL;
        free(temp);
    }


    while(temp->next!=NULL)
    {
        if(temp->next->occurence == maxi)
        {
            ancien=temp->next->next;
            temporel=temp->next;
            temp->next=ancien;
            temporel->next=NULL;

        }
        temp=temp->next;
    }
    return *l;

}



int taille_liste(Element *l)
{

    if (l == NULL)
    {

        return NULL;
    }
    else
    {
        return 1 + taille_liste(l->next);
    }

}

int recup_occurence(Element *l)
{
    if(l==NULL)
    {
        exit(1);
    }
    return l->occurence;
}

Element* create_element(int nouv_info)//Ou Element* creer_el(int nouv_info)
{
    Element* nouv_elem;//Ou Element* nouv_elem ...etc
    nouv_elem = (Element*)malloc(sizeof(Element));
    nouv_elem->occurence = nouv_info;
    nouv_elem->next = NULL;
    return nouv_elem;
}


Node* create_node(int occur, char letter)
{

    Node* n = (Node*)malloc(sizeof(Node));
    n->sad = NULL;
    n->sag = NULL;
    n->occur = occur;
    n->letter = letter;
    return n;

}

Node* tree_huffman(Element* l)
{



    if (taille_liste(l) == 0)
    {
        return NULL;
    }

    if (l->next == NULL)
    {

        return create_node(l->occurence, l->lettre);
    }


    char lettre_max = maximum_letter(l);
    int occurence_max = maximum_occurence(l);


    Node* node = create_node(nbr_occurence(l), 0);
    node->sag = create_node(occurence_max, lettre_max);
    l = supp_element(&l, occurence_max);
    node->sad = tree_huffman(l);

    return node;

}

int nbr_occurence(Element* l)
{

    if (l == NULL)
    {

        return 0;
    }
    else
    {

        return (l->occurence) + nbr_occurence(l->next);
    }



}

void print_list(Element* l)
{

    if (l == NULL)
    {

        return;
    }
    else
    {

        printf("(%d,%c)", l->occurence, l->lettre);
        print_list(l->next);
    }

}

void print_tree(Tree a)
{

    if ( a == NULL)
    {
        return;
    }

    else
    {


        print_tree(a->sad);
        printf("%d,%c\n", a->occur, a->letter);
        print_tree(a->sag);

    }


}


extern void add_1_or_0(char* c, int nbr)
{


    int cmp = 0;

    while( c[cmp] != '\0')
    {
        printf("%d ", cmp);
        cmp++;

    }
    printf("\n");


//printf("%d  ", cmp);

    if (nbr == 0)
    {
        c[cmp] = '0';
    }
    else
    {
        c[cmp] = '1';

    }

     c[cmp+1] = '\0';


}

extern void reset_chain(char* c)
{

    *c = '\0';

}

int fill_chain(char* c, Tree a, Element* l)
{

    int taille = taille_liste(l);

    if (taille == 1)
    {
        add_1_or_0(c, 0);
        return 0;
    }

    if ( a == NULL)
    {
        exit(1);
    }
    else if ( (a->sad == NULL) && (a->sag == NULL)  )
    {
        return 0;
    }

    else if ( a->sag->letter == l->lettre )
    {
        add_1_or_0(c, 0);
        return 0;
    }

    else
    {
        add_1_or_0(c, 1);
        return fill_chain(c, a->sad, l);
    }

}

extern void dico_huffman(Tree a, Element* l)
{

    if ( a == NULL)
    {
        return;
    }


    char chain[60] = "\0";
    FILE* fichier;
    fichier = fopen("dico.txt","r+");

    char h[] = "888888888888888888888";
    fprintf(fichier, "%s", h);

    while ( l != NULL)
    {

        fill_chain(chain, a, l);

        printf("chaine = %s, lettre = %c\n", chain, l->lettre);
        fprintf(fichier, "%c:", l->lettre);
        fprintf(fichier, "%s", chain);
        fputs("\n", fichier);
        reset_chain(chain);
        l = l->next;

    }

    fclose(fichier);

}

