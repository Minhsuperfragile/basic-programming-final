#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct studentInfo
{
    char name[20];
    char ID[9];
    char birthdate[11];
    float linearAlgebra;
    float calculus;
    float basicProgramming;
    float GPA;
};

void displayStudentInfo(int n,struct studentInfo *studentArray){
    printf("%20s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    printf("===============================================================================================================\n");
    for(int i=0;i<n;i++){
        printf("%20s|%15s|%15s|%10f|%10f|%20f|%10f\n",            
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);
    }
}

void writeToFile(int n,struct studentInfo *studentArray){
    FILE *filePointer;
    filePointer = fopen("dataBase.txt","w");

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
    }        

    fprintf(filePointer,"%20s|%15s|%15s|%10s|%10s|%20s|%10s\n","Name","ID","Date of Birth","Linear","Calculus","Basic Programming","GPA");
    fprintf(filePointer,"===============================================================================================================\n");
    for(int i=0;i<n;i++){
        fprintf(filePointer,"%20s|%15s|%15s|%10f|%10f|%20f|%10f\n",            
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);       
    }
    fclose(filePointer);
}

char highestGPA(int n, struct studentInfo *studentArray){
    float *gpaPointer = (int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        gpaPointer[i] = studentArray[i].GPA;
    }

    free(gpaPointer);
    return;
}

char lowestGPA(int n, struct studentInfo *studentArray){
    float *gpaPointer = (int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        gpaPointer[i] = studentArray[i].GPA;
    }

    free(gpaPointer);
    return;
}

char highestBP(int n, struct studentInfo *studentArray){
    float *bpPointer = (int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        bpPointer[i] = studentArray[i].GPA;
    }

    free(bpPointer);
    return;
}
int main (){
//get number of student:
    int numberOfStudent,c;
    printf("enter number of student: ");
    scanf("%d",&numberOfStudent);
//get student info:
    char *p;
    struct studentInfo studentArray[numberOfStudent];
    for (int i=0;i<numberOfStudent;i++){
        while ( (c = getchar()) != '\n' && c != EOF ); // remove \n from stream
        printf("Type in student's name: ");
        fgets(studentArray[i].name,20,stdin);
        if ((p=strchr(studentArray[i].name, '\n')) != NULL)
            *p = '\0'; // remove \n from name

        printf("Type in student's ID: ");
        fgets(studentArray[i].ID,9,stdin);
        if ((p=strchr(studentArray[i].ID, '\n')) != NULL)
            *p = '\0'; // remove \n from ID
        while ( (c = getchar()) != '\n' && c != EOF ); // remove \n from stream

        printf("Type in student's birthdate: ");
        fgets(studentArray[i].birthdate,11,stdin);
        if ((p=strchr(studentArray[i].birthdate, '\n')) != NULL)
            *p = '\0'; // remove \n from birthdate
        while ( (c = getchar()) != '\n' && c != EOF ); // remove \n from stream
        
        printf("Type in student's linear grade: ");
        scanf("%f", &studentArray[i].linearAlgebra);

        printf("Type in student's calculus grade: ");
        scanf("%f", &studentArray[i].calculus);

        printf("Type in student's basic programming grade: ");
        scanf("%f", &studentArray[i].basicProgramming);     

        studentArray[i].GPA = (studentArray[i].linearAlgebra + studentArray[i].calculus + studentArray[i].basicProgramming)/3;
    }

//display student info
    displayStudentInfo(numberOfStudent,studentArray);
//write to file
    writeToFile(numberOfStudent,studentArray);

    return 0;
}