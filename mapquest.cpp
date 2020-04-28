//
// Created by Vladimir on 4/26/2020.
//

#include <iostream>
#include "mapquest.h"

class map_quest {

public:

    /**
     * All three functions used to sort an array passed in
     * @param A The array that gets passed to the function
     * @param n the size of the array
     */
    void merge_sort(int A[], int n) {
        int *TA = new int[n + 1];
        msort(A, TA, 1, n);
        print_array(A, 7);
        delete[] TA;
    }

    void msort(int A[], int TA[], int left, int right) {
        int center;
        if (left < right) { // at least 2 numbers
            center = (left + right) / 2;
            msort(A, TA, left, center);
            msort(A, TA, center + 1, right);
            merge(A, TA, left, center + 1, right);
        }
    }

    void merge(int A[], int TA[], int left, int right, int right_end) {

        int left_end = right - 1;
        int temp = left;
        int n = right_end - left + 1;
        while (left <= left_end && right <= right_end) { //both lists have data
            if (A[left] <= A[right]) {
                TA[temp++] = A[left++];
            } else {
                TA[temp++] = A[right++];
            }
        }
        while (left <= left_end) {
            TA[temp++] = A[left++];
        }
        while (right <= right_end) {
            TA[temp++] = A[right++];
        }
        for (int i = 1; i <= n; right_end--, i++) {
            A[right_end] = TA[right_end];
        }
    }

    /* Function to print an array */
    void print_array(int arr[], int size) {

        for (int i = 0; i < size; i++) {
            //std::cout << i << std::endl;
            std::cout << arr[i] << std::endl;
        }
    }

};
