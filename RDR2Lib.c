#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bool int
#define false 0
#define true 1
int maxNameSize = 100;


/*struct subspecies {
    char name[20];
    bool isComplete;

};*/


/*typedef struct species {
    char name[10];
    //struct subspecies subspecies[];

} species; */


int main()
{

    //species speciesTable[80];
    
    
    /*
    for(int i = 0; i < 80; i++)
    {
        speciesTable[0].name = 
    } 
    
    */

   char names[80][10];

   FILE *filepoint;

   char row[maxNameSize];

   filepoint = fopen("AnimalsRDR2CSV.csv", "r");

   if(filepoint == NULL) //Error openining file, make sure its opening correctly or in place.
   {
    printf("Error opening file.\n");
    return 1;
   }

    int index = 0;

   while(!feof(filepoint)) //While it is not the end of the csv file, it will keep reading until it is
   {
        if(fgets(names[index], maxNameSize, filepoint) != NULL)
        {
            printf("Row %d: %s\n", index, names[index]);
            index++;
        }
   }

  










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