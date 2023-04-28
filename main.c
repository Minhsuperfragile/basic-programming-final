#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "findAge.h"

struct studentInfo //initiate studentInfo structure
{
    char name[20]; // name of student, max 19 char (last space for null char)
    char ID[10]; // ID of student, max 9 char (last space for null char)
    char birthdate[11]; // birthdate in format DD/MM/YYYY (last space for null char)
    float linearAlgebra;
    float calculus;
    float basicProgramming;
    float GPA;
};

//swap for student info structures
void swap(struct studentInfo *a, struct studentInfo *b) {
    struct studentInfo t = *a; //temporary var
    *a = *b;
    *b = t;
} // this function is made for later sort function

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

void quickSortGPA(struct studentInfo *studentArray, int start, int end,bool ascending){
    if (end <= start) {return;}
    
    float pivot = partitionGPA(studentArray,start,end,ascending);
    quickSortGPA(studentArray, 0, pivot - 1,ascending);
    quickSortGPA(studentArray, pivot + 1, end,ascending);
}
//end quick sort gpa

//start bubble sort basic programming score
void bubbleSort(struct studentInfo *studentArray, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (studentArray[j].basicProgramming > studentArray[j + 1].basicProgramming)
                swap(&studentArray[j], &studentArray[j + 1]);
}
//end bubble sort for basic programming score

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
    quickSortGPA(studentArray,0,n-1,false);
    printf("%s has the highest GPA\n",studentArray[0].name);
}

void lowestGPA(int n, struct studentInfo *studentArray){
    quickSortGPA(studentArray,0,n-1,true);
    printf("%s has the lowest GPA\n",studentArray[0].name);
}

void highestBP(int n,struct studentInfo *studentArray){
    struct studentInfo max = studentArray[0];
    for (int i=0;i<n;i++){
        if (max.basicProgramming < studentArray[i].basicProgramming){
            max = studentArray[i];
        }
    }
    printf("%s has the highest BP point",max.name);
}

void getLastName(char *fullName){
    char lastName[10] = "\0";
    int count = 0;
    for(int i=0,j=0;i<strlen(fullName);i++){
        if (fullName[i] == ' '){
            count++;
        }
        if (count == 2){
            lastName[j++] = fullName[i];
        }
    }
    printf("Student's last name is%s",lastName);
}

void getOldest(int n, struct studentInfo *studentArray){
    struct studentInfo max = studentArray[0];
    for (int i=0;i<n;i++){
        if (getAge(max.birthdate) < getAge(studentArray[i].birthdate)){
            max = studentArray[i];
        }
    }
    printf("%s is the oldest",max.name);
}

void getYoungest(int n, struct studentInfo *studentArray){
    struct studentInfo min = studentArray[0];
    for (int i=0;i<n;i++){
        if (getAge(min.birthdate) > getAge(studentArray[i].birthdate)){
            min = studentArray[i];
        }
    }
    printf("%s is the oldest",min.name);
}

struct studentInfo search(struct studentInfo *studentArray,int n){
    int i=0;
    char target[10];

    printf("Enter ID of student you want to find: ");
    getchar();
    fgets(target,10,stdin);

    for (i=0;i<n;i++){
        if (strcasecmp(studentArray[i].ID,target)==0){
            printf("Name: %s\nID: %s\nDate of birth: %s\nLinear Algebra: %f\nCalculus: %f\nBasic Programming: %f\nGPA: %f\n ",
            studentArray[i].name,studentArray[i].ID,studentArray[i].birthdate,
            studentArray[i].linearAlgebra,studentArray[i].calculus,studentArray[i].basicProgramming,studentArray[i].GPA);
            break;
        }
    }
    if (strcasecmp(studentArray[i].ID,target)!=0){
        printf("There is no matched ID");
    }
    return studentArray[i];
}
int main (){
//get number of student:
    int numberOfStudent;
    printf("enter number of student: ");
    scanf("%d",&numberOfStudent);
//get student info:
    struct studentInfo studentArray[numberOfStudent];
    for (int i=0;i<numberOfStudent;i++){
        
        printf("Type in student's name: ");
        getchar();
        fgets(studentArray[i].name,20,stdin);
        studentArray[i].name[strcspn(studentArray[i].name,"\n")] = '\0';

        printf("Type in student's ID: ");
        fgets(studentArray[i].ID,10,stdin);
        getchar();
        studentArray[i].ID[strcspn(studentArray[i].ID,"\n")] = '\0';

        printf("Type in student's birthdate: ");
        fgets(studentArray[i].birthdate,11,stdin);
        studentArray[i].birthdate[strcspn(studentArray[i].birthdate,"\n")] = '\0';

        printf("Type in student's linear grade: ");
        scanf("%f", &studentArray[i].linearAlgebra);

        printf("Type in student's calculus grade: ");
        scanf("%f", &studentArray[i].calculus);

        printf("Type in student's basic programming grade: ");
        scanf("%f", &studentArray[i].basicProgramming);     

        studentArray[i].GPA = (studentArray[i].linearAlgebra + studentArray[i].calculus + studentArray[i].basicProgramming)/3;
    }
    // highestBP(numberOfStudent,studentArray);
//display student info
    // displayStudentInfo(numberOfStudent,studentArray);
//write to file
    // writeToFile(numberOfStudent,studentArray);
    search(studentArray,numberOfStudent);
    return 0;
}