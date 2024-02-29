#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define bool int
#define false 0
#define true 1

const int maxNameSize = 100;
const int numOfAnimals = 156;
char filenameZoologist[] = "ZoologistAnimalsRDR2.csv";

typedef struct animal {

    
    bool isStudied;
    bool isSkinned;
    char* name;

} animal;


FILE* openReadFile(char filename[]); //Opens the file I may need to open (i.e. Zoologist & Skinnable lists)

int numOfEntries(char filename[]); //Finds the number of entries in a list

animal** createAnimalList(int numEntries, char filename[]); 
/*Dynamically allocates memory to make an array of structs with strings in them


 Pointer to an array of pointers which points to a struct. The struct contains a pointer to a string array.
   ptr -> [ nameptr ][ nameptr ][ nameptr ][ nameptr ][ nameptr ]
              |        |           |          |          |   
           [][][][]  [][][]      [][][]     [][][]     [][][]
*/


void freeAnimalList(int numEntries, animal** animalList); 
//Frees the string, then the struct, then the ptr to the array of structs

int nameLength(char animalName[]); //Returns the length of a name when called

int main()
{    
    FILE *filepointZoologist = NULL;

    int numZooEntries = numOfEntries(filenameZoologist);

    filepointZoologist = openReadFile(filenameZoologist);

    animal** animalListZoologist = NULL; //Points to a pointer (the)
    
    animalListZoologist = createAnimalList(numZooEntries, filenameZoologist);



    int index = 0;
    
    char tempName[maxNameSize] ;
    char* fileAnimalName = NULL;
   

   while(!feof(filepointZoologist)) //While it is not the end of the csv file, it will keep reading until it is
   {
     
        if(fgets(tempName, maxNameSize, filepointZoologist) != NULL)
        {

            strcpy(animalListZoologist[index]->name, tempName);

            printf("Row %d: %s\n", index + 1, animalListZoologist[index]->name);
            
            index++;          
            
        }
   }

   fclose(filepointZoologist);

   /*for(int i = 0; i < numOfAnimals; i++)
   {
    


   }




   
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

    freeAnimalList(numOfAnimals, animalListZoologist);
 
    return 0;
}


FILE* openReadFile(char filename[])
{
    FILE *filepoint = NULL;

   filepoint = fopen(filename, "r");

   if(filepoint == NULL) //Error openining file, make sure its opening correctly or in place.
   {
    perror("Error opening file.\n");
    exit(1);
   }
    
    

    return filepoint;

}

int numOfEntries(char filename[])
{

    FILE* filepoint = openReadFile(filename);

    int i = 0;

   while(!feof(filepoint)) //While it is not the end of the csv file, it will keep reading until it is
   {
       

    char tempName[100];

        if(fgets(tempName, maxNameSize, filepoint) != NULL)  
        {
            i++;
        }

   }

    fclose(filepoint);

    return i;

}


animal** createAnimalList(int numEntries, char filename[])
{
    animal** animalListPtr = NULL;

    animalListPtr = (animal**)malloc(numEntries * sizeof(animal*));

    for(int i = 0; i < numEntries; i++)
    {
        animalListPtr[i] = malloc(sizeof(animal));
        animalListPtr[i]->isSkinned = 0;
        animalListPtr[i]->isStudied = 0;
       animalListPtr[i]->name = malloc(sizeof(nameLength(filename) + 1)); 
    }

    return animalListPtr;
}

void freeAnimalList(int numEntries, animal** animalList)
{
    animal* animallistptr;
    for(int i = numEntries; i > -1; i--)
    {
         printf("hey\n");
        free(animalList[i]->name);
        animallistptr = animalList[i];
        printf("%s", animallistptr);
    
        free(animalList[i]);
         
    }

    free(animalList);

}

int nameLength(char animalName[])
{
    return (strlen(animalName));
}