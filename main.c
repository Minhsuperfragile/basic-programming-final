#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct studentInfo
{
    char name[30];
    char ID[9];
    char birthdate[11];
    float linearAlgebra;
    float calculus;
    float basicProgramming;
    float GPA;
};

int main (){
//get number of student:
    int numberOfStudent;
    printf("enter number of student: ");
    scanf("%d",&numberOfStudent);
//get student info:
    struct studentInfo *studentArray = calloc(numberOfStudent,sizeof(struct studentInfo));
    for (int i=0;i<numberOfStudent;i++){
        printf("Type in student's name: ");
        scanf("%[^\n]%*c", studentArray[i].name);
        printf("Type in student's ID");
        scanf("%s", studentArray[i].ID);
        printf("Type in student's birthdate: ");
        scanf("%s", studentArray[i].birthdate);
        printf("Type in student's linear grade: ");
        scanf("%f", &studentArray[i].linearAlgebra);
        printf("Type in student's calculus grade: ");
        scanf("%f", &studentArray[i].calculus);
        printf("Type in student's basic programming grade: ");
        scanf("%f", &studentArray[i].basicProgramming);
        studentArray[i].GPA = (studentArray[i].linearAlgebra + studentArray[i].calculus + studentArray[i].basicProgramming)/3;
    }
//display student info
    printf("%50s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    printf("=================================================================================================================\n");
    for(int i=0;i<numberOfStudent;i++){
        printf("%50s|%15s|%15s|%10f|%10f|%20f|%10f\n",            
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);
    }
//write to file
    FILE *filePointer;
    filePointer = fopen("dataBase.txt","w");

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
    }        

    fprintf(filePointer,"%50s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    fprintf(filePointer,"=================================================================================================================\n");
    for(int i=0;i<numberOfStudent;i++){
        fprintf(filePointer,"%50s|%15s|%15s|%10f|%10f|%20f|%10f\n",            
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);       
    }
    return 0;
}