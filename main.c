#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

//swap for student info structures
void swap(struct studentInfo *a, struct studentInfo *b) {
    struct studentInfo t = *a;
    *a = *b;
    *b = t;
}

//start quick sort gpa
int partitionGPA(struct studentInfo *studentArray, int start, int end, bool ascending){
    float pivot = studentArray[end].GPA;
    int i = start - 1;

    for (int j = start; j <= end-1; j++){
        if (studentArray[j].GPA <= pivot && ascending){
            i++;
            swap(&studentArray[i],&studentArray[j]);
        }
        if (studentArray[j].GPA > pivot && !ascending){
            i++;
            swap(&studentArray[i],&studentArray[j]);
        }
    }
    i++;
    swap(&studentArray[i],&studentArray[end]);
    return i;
}

void sortGPA(struct studentInfo *studentArray, int start, int end,bool ascending){
    if (end <= start) {return;}
    
    float pivot = partitionGPA(studentArray,start,end,ascending);
    sortGPA(studentArray, 0, pivot - 1,ascending);
    sortGPA(studentArray, pivot + 1, end,ascending);
}
//end quick sort gpa

//start bubble sort basic programming score
void bubbleSort(){
    
}

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

void highestGPA(int n, struct studentInfo *studentArray){
    sortGPA(studentArray,0,n-1,false);
    printf("%s has the highest GPA\n",studentArray[0].name);
}

void lowestGPA(int n, struct studentInfo *studentArray){
    sortGPA(studentArray,0,n-1,true);
    printf("%s has the lowest GPA\n",studentArray[0].name);
}

void highestBP(){
    printf("%s has the highest basic programming score\n");
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
    lowestGPA(numberOfStudent,studentArray);
//display student info
    displayStudentInfo(numberOfStudent,studentArray);
//write to file
    // writeToFile(numberOfStudent,studentArray);
    return 0;
}