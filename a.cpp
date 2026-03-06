#include <iostream>


size_t plus_grand_bloc_allouable(){
    size_t moyenne, plus, moins;
    size_t taille = 1;
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

    while(plus+1!=moins){               
        try
        {
            moyenne = (moins+plus)/2;           //Prendre la valeur entre le plus et le moins
            char* tab = new char[moyenne];
            delete[] tab;
            plus = moyenne;                     //tout a fonctionné alors la valeur du milieu est supérieur.
        }
        catch(const std::bad_alloc& e)          //Si ça catch une erreur
        {
            moins = moyenne;                    //Alors la valeur du milieu est trop grand, on affecte cette valeur au moins.
        }
    }
    std::cout<<moyenne<<'\n';
    return EXIT_SUCCESS;

}

