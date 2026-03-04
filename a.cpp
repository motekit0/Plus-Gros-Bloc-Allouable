#include <iostream>


size_t plus_grand_bloc_allouable(size_t &max, size_t &min){
    size_t max, min, moyenne;
    while(min+1!=max){
        try
        {
            moyenne = (max+min)/2;
            int tab = new int[moyenne];
            delete[] tab;
            min = moyenne;
        }
        catch(const std::bad_alloc& e)
        {
            max = moyenne;
        }
        
    }
    return moyenne;
}

