#include "Disease.h"


Disease::Disease()
{

}

Disease::Disease(int disease)
{
    switch(disease)
    {
        case 1:         // For Dengue

                symptoms = "";
                break;

        case 2:         // For Malaria

            symptoms = "";
            break;

        case 3:         // For Chikengunya

            symptoms = "";
            break;

        default:       // For no disease

            symptoms = "";
    }
}
