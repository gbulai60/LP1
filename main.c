#include <stdio.h>
#include <math.h>
#include <malloc.h>

void printEvenNumbers(int limit){
    printf("Even numbers: \n");
    for(int i=2;i<limit;i=i+2)
        printf("%i ",i);

}
void printOdd(int limit){
    int i=1;
    printf("\nOdd numbers: \n");
    while(i<limit){

        printf("%i ",i);
        i=i+2;
    }
}
int factorial(int n){
    if(n==0 || n==1) return 1;
    else return n* factorial(n-1);
}
float triangleArea(int a,int b,int c){
    if (a<b+c && b<a+c && c < a+b ) {
        float p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    else return 0;
}
void printMaxPosition(int array[],int n){
    int max=array[0];
    for(int i=0;i<n;i++){
        if(array[i]>max) max=array[i];
    }
    for (int i = 0; i < n; i++) {
        if(array[i]==max) printf("%i ",i);
    }
}
int check(int n){
    return (n==65 || n==69 || n==73 || n==79 || n==85 || n==97 || n==101 || n==105 || n==111 || n==117) ? 1:0;
}
int numbersVowels(char sequence[],int lenght){
    int number=0;
    for (int i = 0; i < lenght; i++) {
        if(check(sequence[i])) number++;
    }
    return number;
}
void sortArray(int array[],int n,int pivot,int i){
    if(i<=n) {
        int num = 0;
        for (int j = i; j < n; j++)
            if (array[j] < pivot) num++;
        if (num == 0) sortArray(array, n, array[i + 1], i + 1);
        else {
            if(array[num+i]==pivot){
                int temp = array[num + i+1];
                array[num + i+1] = pivot;
                array[i] = temp;
                sortArray(array, n, array[i+1], i+1);
            }
            else {
                int temp = array[num + i];
                array[num + i] = pivot;
                array[i] = temp;
                sortArray(array, n, array[i], i);
            }
        }
    }
}
void print(int *array,int n){
    printf("\nElementele tabloului:");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}
void insertEnd(int *array,int n){
    array=(int*)realloc(array, n+1*sizeof(int));
    int newElement;
    printf("\n Introduceti elementul pe care doriti sa il inserati: \n");
    scanf("%d",&newElement);
    array[n]=newElement;
    print(array,n+1);
}
void insertStart(int *array,int n){
    array=(int*)realloc(array, n+1*sizeof(int));
    int newElement;
    printf("\n Introduceti elementul pe care doriti sa il inserati: \n");
    scanf("%d",&newElement);
    for(int i=n;i>0;i--)
        array[i]=array[i-1];
    array[0]=newElement;
    print(array,n+1);
}
void revereseString(char *sequence,int lenght){
    char reverse[lenght];
    int j=0;
    for(int i=lenght-1;i>=0;i--)
        reverse[j++]=sequence[i];
    printf("%s",reverse);

}
void sevenTask(){
    int n;
    printf("\nIntroduceti numarul de elemente a tabloului: ");
    scanf("%d",&n);
    int *array= malloc(n * sizeof(int));
    printf("\nIntroduceti elementele de la tastatura:\n");
    for(int i=0;i<n;i++){
        printf("array[%i]=",i);
        scanf("%d",&array[i]);
    }
    print(array,n);
    insertEnd(array,n);n++;
    insertStart(array,n);n++;
    getchar();
}
int main() {
    printEvenNumbers(100);
    printOdd(100);
    printf("\nFactorialul numarului 4! = %i ", factorial(4));
    printf("\nNumarul de vocale din secventa 'Salut' este %i ", numbersVowels("Salut",5));
    printf("\nAria triunghiului cu laturile 3,4,5 este %.2f", triangleArea(3,4,5));
    int array[]={4,6,2,1,3,8,13,20,334,18,14,0,2};
    printf("\nPozitiile elementului maxim:");
    printMaxPosition(array,5);
    sortArray(array,13,array[0],0);
    printf("\n Array-ul sortat:");
    for(int i=0;i<13;i++)
        printf("%i ",array[i]);
    printf("\n Inversul cuvantului 'Salut' :");
    revereseString("Salut",5);
    sevenTask();

    getchar();
    return 0;
}
