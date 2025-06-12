#include <stdio.h>

void heapfy(int array[],int n, int i){
    int maior = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && array[left]>array[maior]){
        maior = left; //raiz recebe esquerda
    }
    if(right < n && array[right] > array[maior]){
        maior = right;
    }
    if(maior != i){
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;
        heapfy(array,n,maior);
    }
}

void heapsort(int array[], int n){
    //criando o heapsort apartir do heapfy e usando a funcao recursiva
    for(int i = n / 2 - 1 ;  i >=0 ; i--){
        heapfy(array, n,i);
    }
    for(int i = n - 1 ; i>0; i-- ){
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapfy(array,i,0);
    }
}

void print(int array[], int n){
    for(int i = 0; i < n ; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {8,9,4,5,2, 3, 7,6,1};
    int n = sizeof(array) / sizeof(array[1]);
    heapsort(array,n);
    printf("O array a ser ordenado é: ");
    print(array,n);
    return 0;
}