#include <stdio.h>
#include <time.h>
#include <stdint.h>

void load(int *a);
int partition(int *a, int p, int r);
void quicksort(int *a, int p, int r);

int main() {
    int arr[8], i;
    load(arr);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    quicksort(arr, 0, 7);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta = (end.tv_sec - start.tv_sec) * 1000000 +
        (end.tv_nsec - start.tv_nsec) / 1000;
    printf("%lu", delta);
    /*
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");*/
}

void load(int *a) {
    *(a)   = 5;
    *(a+1) = 8;
    *(a+2) = 2;
    *(a+3) = 9;
    *(a+4) = 1;
    *(a+5) = 3;
    *(a+6) = 10;
    *(a+7) = 4;
}

int partition(int *a, int p, int r) {
    int x, i, j, tmp1, tmp2, *addr1, *addr2;
    addr1 = a + r;
    x = *(addr1);
    i = p - 1;
    for (j = p; j < r; j++) {
        addr1 = a + j;
        if (*(addr1) <= x) {
            i++;
            addr1 = a + i;
            addr2 = a + j;
            tmp1 = *(addr1);
            tmp2 = *(addr2);
            *(addr1) = tmp2;
            *(addr2) = tmp1;
        }
    }
    addr1 = a + i + 1;
    addr2 = a + r;
    tmp1 = *(addr1);
    tmp2 = *(addr2);
    *(addr1) = tmp2;
    *(addr2) = tmp1;
    return i + 1;
}

void quicksort(int *a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}
