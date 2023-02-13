#include<iostream>
#include<time.h>
#include<vector>

using namespace std;

int bubblesort(vector<int> &arr, int n)
{
    for(int i=0; i<n-1;i++)
    {
        for(int j=0; j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return 0;
}

void insertionSort(vector<int> &arr, int n)
{
	int i, j,k;
	for (i = 1; i < n; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}

void selectionSort(vector<int> &arr, int n)
{
	int i, j, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
        {
		if (arr[j] < arr[min])
			min = j;

		if(min!=i)
			swap(arr[min], arr[i]);
        }
	}
}
void merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int part(vector<int> &arr, int low, int high) {
    int p = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(vector<int> &arr, int n, int i) {
    int max =i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if (l<n && arr[l]>arr[max])
        max = l;
    
    if (r<n && arr[r]>arr[max])
        max = r;
    
    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(vector<int> &arr, int n) {

    for (int i = n / 2 ; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    clock_t s1,s2,s3,e1,e2,e3,s4,e4,s5,e5,s6,e6;
    int n = 100;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
    s1 = clock();
    bubblesort(arr,n);
    e1 = clock();
    s2 = clock();
    insertionSort(arr,n);
    e2 = clock();
    s3 = clock();
    selectionSort(arr,n);
    e3 = clock();
    s4 = clock();
    mergeSort(arr,0,n);
    e4 = clock();
    s5 = clock();
    quickSort(arr,0,n);
    e5 = clock();
    s6 = clock();
    heapSort(arr,n);
    e6 = clock();
    for(int i=0; i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<"\n";
    double exec1,exec2,exec3,exec4,exec5,exec6;
    exec1 = ((double)(e1-s1))/CLOCKS_PER_SEC;
    cout<<"Time for Bubble Sort : "<<exec1<<endl;
    exec2 = ((double)(e2-s2))/CLOCKS_PER_SEC;
    cout<<"Time for Insertion Sort : "<<exec2<<endl;
    exec3 = ((double)(e3-s3))/CLOCKS_PER_SEC;
    cout<<"Time for Selection Sort : "<<exec3<<endl;
    exec4 = ((double)(e4-s4))/CLOCKS_PER_SEC;
    cout<<"Time for Merge Sort : "<<exec4<<endl;
    exec5 = ((double)(e5-s5))/CLOCKS_PER_SEC;
    cout<<"Time for Quick Sort : "<<exec5<<endl;
    exec6 = ((double)(e6-s6))/CLOCKS_PER_SEC;
    cout<<"Time for Heap Sort : "<<exec6<<endl;
    return 0;
}