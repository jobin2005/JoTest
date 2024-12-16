#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    char surname[50];
    float height;
    float weight;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}


int partition(struct Student arr[], int low, int high) {
    float pivot = arr[high].height;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].height < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(struct Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    struct Student L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].height <= R[j].height) {
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

void mergeSort(struct Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void readDataFromFile(struct Student arr[], int* n) {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    *n = 0;
    while (fscanf(file, "%s %s %f %f", arr[*n].name, arr[*n].surname, &arr[*n].height, &arr[*n].weight) != EOF) {
        (*n)++;
    }
    fclose(file);
}

void writeDataToFile(const char* filename, struct Student arr[], int n, double timeTaken) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Sorted Data:\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %.2f %.2f\n", arr[i].name, arr[i].surname, arr[i].height, arr[i].weight);
    }
    fprintf(file, "Time taken: %.6f seconds\n", timeTaken);
    fclose(file);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;
    clock_t t; 
    t = clock();
    clock_t q; 
    q = clock();
    
    readDataFromFile(students, &n);
    
    struct Student quickSorted[MAX_STUDENTS];
    struct Student mergeSorted[MAX_STUDENTS];
    
    for (int i = 0; i < n; i++) {
        quickSorted[i] = students[i];
        mergeSorted[i] = students[i];
    }

  
    quickSort(quickSorted, 0, n - 1);
	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    writeDataToFile("quick_sorted.txt", quickSorted, n, time_taken);
    

    mergeSort(mergeSorted, 0, n - 1);
	q= clock() - q; 
	float r=q-t;
    double mergeSortTime = ((double)r) / CLOCKS_PER_SEC;
    writeDataToFile("merge_sorted.txt", mergeSorted, n, mergeSortTime);

    printf("Sorting completed. Results saved in 'quick_sorted.txt' and 'merge_sorted.txt'.\n");
    return 0;
}
