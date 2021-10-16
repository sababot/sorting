#pragma once

void swap(int* a, int* b);

int partion(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);

extern int p_step;
int partion_step(int arr[], int low, int high);
void quick_sort_step(int arr[], int low, int high);
