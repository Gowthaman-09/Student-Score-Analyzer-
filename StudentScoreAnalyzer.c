//Index No: AS20240539
//Name    : Gowthaman N

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputmarks(int marksarr[],int *sizepointer);
int sumavg(int marksarr[],int size);
int displayhighlow(int marksarr[],int size);
int displaymedian(int marksarr[],int size);
int displaystandarddev(int marksarr[],int size);
int displaygrades(int marksarr[],int size);
int predictscore(int marksarr[],int size);
void optionselected(int *choice,int marksarr[],int size);
void menu(int size,int marksarr[]);

int totalsum=0;

void main(){
    int size=0; int marksarr[100];int userchoice;
    printf("\t\t-- Student Score Analyzer USJP --\n\n");
    printf("\tWelcome Dear Lecturer!!!,\n");
    printf("\nEnter the marks to start the analysis.\n");
    printf("Enter 1 to continue, 0 to quit: ");
    scanf("%d",&userchoice);
    if(userchoice==1){
        optionselected(&userchoice,marksarr,size);
    }
    else if (userchoice ==0){
        printf("\n\tThank you for using Student Score Analyzer\n\tHave a Good Day :)\n");
        exit(EXIT_SUCCESS);
    }
    else{
        printf("!!Invalid Input\n");
        printf("Enter 1 or 0: ");
        scanf("%d",&userchoice);
        if(userchoice==1){
            optionselected(&userchoice,marksarr,size);
    }
        else{
            printf("\n\tThank you for using Student Score Analyzer\n\tHave a Good Day :)\n");
            exit(EXIT_SUCCESS);
        }
    } optionselected(&userchoice,marksarr,size);
}

//Function to display menu
void menu(int size,int marksarr[]){
    int userchoice;
    printf("\n1.Re-enter Marks\n");
    printf("2.Display total and average\n");
    printf("3.Display highest and lowest scores\n");
    printf("4.Display median\n");
    printf("5.Display standard deviation\n");
    printf("6.Show grades\n");
    printf("7.Predict next score using moving average\n");
    printf("8.Exit\n");
    printf("\nPlease Enter Choice Number: ");
    scanf("%d",&userchoice);
    if(userchoice>9){
        printf("Please enter a number between 1 and 9: \n");
        menu(size,marksarr);
    }
    else{
    optionselected(&userchoice,marksarr,size);

    }
}

//Function to navigate to the function user selects
void optionselected(int *choice,int marksarr[],int size){
    switch(*choice){
        case 1:
            inputmarks(marksarr,&size);
            printf("\n");
            break;
        case 2:
            sumavg(marksarr,size);
            printf("\n");
            menu(size,marksarr);
            break;
        case 3:
            displayhighlow(marksarr,size);
            printf("\n");
            break;
        case 4:
            displaymedian(marksarr,size);
            printf("\n");
            break;
        case 5:
            displaystandarddev(marksarr,size);
            printf("\n");
            break;
        case 6:
            displaygrades(marksarr,size);
            printf("\n");
            break;
        case 7:
            predictscore(marksarr,size);
            printf("\n");
            break;
        case 8:
            printf("\nThank You Have a Good Day :)\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Enter number between 1 - 7\n");
            menu(size,marksarr);
            break;
    }
}

//Function to get input from the user
void inputmarks(int marksarr[],int *sizepointer){
    int i=1; int studentmark; int index = 20240500; *sizepointer=0;
    printf("\n-- Enter -1 to return to the menu.\n");
    printf("-- Values should be between 0 and 100.\n");
    printf("-- Please do not enter non-integer value\n\n");
    printf("Warning : Please note that entering a non-integer value will terminate the program.\n\n");
    while(*sizepointer<100){
            printf("Enter the marks for Index No.AS%d: ",index);
            if(scanf("%d",&studentmark)==1){
                    if(studentmark>100){
                        printf("(!!!Values should be between 0 and 100!!!)  ");
                    }
                    else if((studentmark>=0)&&(studentmark<=100)){
                        marksarr[*sizepointer]=studentmark;
                        (*sizepointer)++;
                        index++;
                    }
                    else{
                        break;
                    }
        }
            else{
                printf("\nTerminating the program\n");
                printf("\n\tThank you for using Student Score Analyzer\n\tHave a Good Day :)\n");
                exit(EXIT_SUCCESS);


            }
            if(*sizepointer==100){
                printf("\nMaximum Number of Inputs Reached\n");
                break;

            }
}
    printf("%d Marks Added Successfully\n\n",*sizepointer);
     for(i=0;i<*sizepointer;i++){
        totalsum+=marksarr[i];
    }
    menu(*sizepointer,marksarr);
    }

//Function to calculate total and average marks
int sumavg(int marksarr[],int size){
    int i; float sum=0; float avg=0;
    avg=((float)totalsum/(size));
    printf("\n");
    if(size>0){
        printf("\tSum of the marks entered: %.2f\n",(float)totalsum);
        printf("\tAverage of the marks entered: %.2f\n",avg);
    }
    else{
        printf("\n\tPlease input the marks of the students.\n");
    }
}

//Function to find the highest and lowest scores
int displayhighlow(int marksarr[],int size){
    int i;
    int highestmark = marksarr[0];
    int lowestmark = marksarr[0];
    for(i=0;i<size;i++){
            if(highestmark<=marksarr[i]){
                highestmark=marksarr[i];
            }
            else if (lowestmark>=marksarr[i]){
                lowestmark=marksarr[i];
            }
    }
    if(size>0){
            printf("\n\tHighest Mark Obtained by a Student: %d\n",highestmark);
            printf("\tLowest Mark Obtained by a Student: %d\n",lowestmark);
    }
    else{
         printf("\n\tPlease input the marks of the students.\n");
    }
    menu(size,marksarr);
}

//Function to calculate median
int displaymedian(int marksarr[],int size){
    int medianpoint; int sorteddata[size]; int i; int j; int z;
    if(size>0){
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if((marksarr[i]<=sorteddata[j])||(sorteddata[j]<0)){
                    for(z=size-1;z>=j;z--){
                        sorteddata[z+1]=sorteddata[z];
                }
                    sorteddata[j]=marksarr[i];
                    break;
            }
        }
    }
        medianpoint = (size+1);
        if(medianpoint%2==0){
            medianpoint=(medianpoint/2);
            printf("\n\tMedian of the marks entered: %d\n",sorteddata[medianpoint-1]);
    }
        else{
            float medianvalue;
            medianvalue = (sorteddata[(size/2)-1])+(sorteddata[size/2]);
            printf("\n\tMedian of the marks: %.2f\n",medianvalue/2.0);

        }
    }
    else{
        printf("\n\tPlease input the marks of the students.\n");
    }
    menu(size,marksarr);

}

//Function to calculate standard deviation
int displaystandarddev(int marksarr[],int size){
    float mean; int i; float stddevtotal=0;
    mean = (float)totalsum/size;
    for(i=0;i<size;i++){
        stddevtotal = stddevtotal+pow((marksarr[i]-mean),2);
    }
    stddevtotal = stddevtotal/(size);
    stddevtotal = sqrtf(stddevtotal);
    if(size>0){
         printf("\n\tStandard Deviation of the marks: %.4f\n",stddevtotal);
    }
    else{
        printf("\n\tPlease input the marks of the students.\n");
    }
   menu(size,marksarr);

}

//Function to display grades
int displaygrades(int marksarr[],int size){
    int i; int aPass=0;int bPass=0;
    int cPass=0; int sPass=0; int wFail = 0;
    int index = 20240500;
    if(size>0){
        printf("\n\tGrades obtained by each student\n\n");
        for(i=0;i<size;i++){
            printf("\tStudent Index No.AS%d-->",index);
            if((marksarr[i]>=75)&&(marksarr[i]<=100)){
                printf("A Grade\n");
                aPass+=1;
        }
            else if((marksarr[i]>=65)&&(marksarr[i]<75)){
                printf("B Grade\n");
                bPass+=1;
        }
            else if((marksarr[i]>=50)&&(marksarr[i]<65)){
                printf("C Grade\n");
                cPass+=1;
        }
            else if((marksarr[i]>=35)&&(marksarr[i])<50){
                printf("S Grade\n");
                sPass+=1;
        }
            else if((marksarr[i]>=0)&&(marksarr[i]<35)){
                printf("W Grade\n");
                wFail+=1;
        }
            index++;
    }
        printf("\n\tNumber of A Grades = %d\n",aPass);
        printf("\tNumber of B Grades = %d\n",bPass);
        printf("\tNumber of C Grades = %d\n",cPass);
        printf("\tNumber of S Grades = %d\n",sPass);
        printf("\tNumber of W Grades = %d\n",wFail);

//Draw an ASCII bar graph of grades

        printf("\n\tASCII bar graph of grades\n");
        printf("\n\tGrades\n");
        printf("\t");
        if(aPass>0){
            printf("A --> ");
            for(i=1;i<=aPass;i++){
                printf("*",i);
        }
            printf(" (%d)\n",aPass);
    }
        if(bPass>0){
            printf("\tB --> ",bPass);
            for(i=1;i<=bPass;i++){
                printf("*",i);
        }
            printf(" (%d)\n",bPass);
    }
        if(cPass>0){
            printf("\tC --> ",cPass);
            for(i=1;i<=cPass;i++){
                printf("*",i);
        }
            printf(" (%d)\n",cPass);
    }
        if(sPass>0){
            printf("\tS --> ",sPass);
            for(i=1;i<=sPass;i++){
                printf("*",i);
        }
            printf(" (%d)\n",sPass);
    }
        if(wFail>0){
            printf("\tW --> ",wFail);
            for(i=1;i<=wFail;i++){
                printf("*",i);
        }
            printf(" (%d)\n",wFail);
        }
    }
    else{
        printf("\n\tPlease input the marks of the students.\n");
    }
     menu(size,marksarr);
}

//Function to predict next score using a moving average.
int predictscore(int marksarr[],int size){
    int i; float movingavg; int index = 20240500;
    if(size<3){
        printf("\n\tNot Enough Data To Predict Scores\n");
    }
    else{
        for(i=0;i<(size-2);i++){
            movingavg = (float)(marksarr[i]+marksarr[i+1]+marksarr[i+2])/3.0;
            printf("\n\tStudent Index No. AS%d predicted score: %.2f\n",index+4,movingavg);
            index++;
    }


}
    menu(size,marksarr);
}
