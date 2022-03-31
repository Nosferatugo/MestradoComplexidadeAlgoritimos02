#include <iostream>

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] ,std::cout<<" - ";;
}

void merge(int *array, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];
    k--;
    while (k >= 0)
    {
        array[k + low] = temp[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main()
{
	
	int quantidade;
	printf("Digite a quantidade de elementos: ");
	scanf("%d",&quantidade);
	int numeros[quantidade];
	
	printf("Digite %d numeros (separados por ENTER ou a tecla ESPACO):\n",quantidade);
	for(int i = 0; i < quantidade; i++)
        scanf("%d", &numeros[i]);

    
    printf("\n");
	


    std::cout << "Antes da execucao do MergeSort :" << std::endl;
    printArray(numeros, quantidade);
    std::cout << std::endl;
    std::cout << std::endl;

    mergeSort(numeros, 0, quantidade - 1);

    std::cout << "Apos a execucao do Merge Sort :" << std::endl;
    printArray(numeros, quantidade);
    std::cout << std::endl;
    return (0);
}
