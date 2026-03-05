#include <iostream>

void RechercheMoins(){
    size_t taille = 1;
    size_t plus, moins;
    bool quitter = false;
    while(!quitter){
        try
        {
            char* tab = new char[taille];     //Création d'un tableau
            delete[] tab;                   
            plus = taille;                    //On sauvegarde l'ancienne taille
            taille*=2;                        //On double la taille pour le prochain teste
        }
        catch(const std::bad_alloc& e){
            moins = taille;                   //On sauvegarde la taille provoquant une erreur
            quitter = true;
        }
    }
}


size_t plus_grand_bloc_allouable(){
    size_t moyenne, plus, moins;
    while(plus+1!=moins){
        try
        {
            moyenne = (moins+plus)/2;
            char* tab = new char[moyenne];
            delete[] tab;
            plus = moyenne;
        }
        catch(const std::bad_alloc& e)
        {
            moins = moyenne;
        }
    }
    std::cout<<moyenne;
}


int main() {
    RechercheMoins();
    plus_grand_bloc_allouable();
}
