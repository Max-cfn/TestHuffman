#ifndef PARTIE_2_H_INCLUDED
#define PARTIE_2_H_INCLUDED

typedef struct Element{
    int occurence;
    int lettre;
    struct Element* next;
}Element;

typedef struct Node{
    struct Node* sad;
    struct Node* sag;
    int  occur;
    char letter;
}Node;

typedef Node* Tree;

int nbr_occurence(Element* l);
void print_tree(Tree a);
void print_list(Element* l);
Node* tree_huffman(Element* l);
Node* create_node(int occur, char letter);
int maximum_letter(Element* l);
Element* supp_element(Element** l, int maxi);
Element* create_list(int lettre);
int taille_liste(Element *l);
int recup_occurence(Element *l);
Element* creer_liste_lettres();
int maximum_occurence(Element* l);
Element* create_element(int nouv_info);
extern void dico_huffman(Tree a, Element* l);
int fill_chain(char* c, Tree a, Element* l);
extern void add_1_or_0(char* c, int nbr);
extern void reset_chain(char* c);


#endif // PARTIE_2_H_INCLUDED
