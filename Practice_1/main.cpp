#include <iostream>

#include "source/Person.h"

int main(){
    DateOfBirth Birth(2000, Months::February, 20);

    Person P("Name", "Surname", Birth);

    std::cout << P.Age();

    return 0;
}