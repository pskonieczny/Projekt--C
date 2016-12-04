#include "Przeszkody.h"
#include "config.h"

Przeszkoda::Przeszkoda()
{
    setName("AddPipe");
    dl = 0;
}

void Przeszkoda::update(float delta)
{
    parent = (HelloWorld*)getOwner();
    if (parent == NULL) return;
    
    dl+= delta;
    if (dl >= TimePrzeszkody )
    {
        dl = 0;
        parent->DPrzeszkoda();
    }
}
