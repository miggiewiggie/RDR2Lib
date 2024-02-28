#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bool int
#define false 0
#define true 1
const int maxNameSize = 2000;

typedef struct subspecies {

    char name[1000];
    bool isFound;
    bool isSkinned;

} subspecies;


typedef struct species {
    char name[10];
    subspecies subname[]; //Amount of subspecies under a species is dynamic. Implement dynamic array

} species; 

int main()
{
    
   species speciesNames[80];
    
    FILE *filepoint = NULL;

   filepoint = fopen("AllAnimalsRDR2CSV.csv", "r");

   if(filepoint == NULL) //Error openining file, make sure its opening correctly or in place.
   {
    printf("Error opening file.\n");
    exit(1);
   }
    
    int indexSpecies = 0;
    
    char tempName[maxNameSize] ;
    char* fileSpeciesName = NULL;
    char* fileSubspeciesName = NULL;

   while(!feof(filepoint)) //While it is not the end of the csv file, it will keep reading until it is
   {
        int indexSubSp = 0;
     
        if(fgets(tempName, maxNameSize, filepoint) != NULL)
        {
            fileSpeciesName = strtok(tempName, ",");

            strcpy(speciesNames[indexSpecies].name, fileSpeciesName);

            fileSubspeciesName = strtok(NULL, ",");

            while(fileSubspeciesName != NULL){
                printf("hey\n\n");
                strcpy(speciesNames[indexSpecies].subname[indexSubSp].name, fileSubspeciesName);
                printf("%s index- %d \n", speciesNames[indexSpecies].subname[indexSubSp].name, indexSubSp);
                indexSubSp++;
                fileSubspeciesName = strtok(NULL, ",");
            };

            indexSpecies++;
            
        }

     
   }

    
    for(int i = 0; i < 79; i++)
    {
        printf("Row %d: %s\n", i + 1, speciesNames[i].name);
    }


    printf("sizeof ,: %d", sizeof(","));





   /*
    int choice = 3;

    while(choice == 3){

        printf("Menu: \n\n");

        printf("1 - Search Wiki\n");
        printf("2 - Mark Complete/Incomplete\n");
        printf("3 - Exit\n");

        printf("Please select an option: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {

            case 1:
                //wiki()
                printf("Wiki\n\n");
                choice = 3;
                break;
            case 2:
                //mark()
                printf("Mark\n\n");
                choice = 3;
                break;
            case 3:
                printf("Exit\n\n");
                exit(0);
                
            default:
                printf("Default\n\n");
                choice = 3;
                break;
        }

    
    }
    */


    return 0;
}



/* char** createTable(){

    char* speciesNames = malloc(80)

}
*/
