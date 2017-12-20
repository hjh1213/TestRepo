#include <stdio.h>
#define N 10000  //这是数组最大长度

int count = 0;  //用于记录quick_sort的调用次数

//整数变量交换函数
void swap(int *a, int *b){
  if(a != b){
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);
  }
}

//重排函数：quick_sort()的helper function
int patition(int *A, int p, int r){
  int i, j = p - 1; //i是循环变量, j记录在i之前比x小的最后一个数的下标
  int x = A[r];
  
  //遍历数组, 将比x小的放在前面、比x大的留在后面
  for(i = p; i < r; i++){
    if(A[i] < x){
      swap(A[j++], A[i]);
    }
  }

  //最后把x插到中间, 返回它所在的位置(此时整个数组以x为分界点, 在x前面的比x小, 在x后面的不小于x, 这是快速排序的核心)
  swap(A[j++], A[r]);
  return j;
}

//快速排序函数
void quick_sort(int *A, int p, int r){
  int q; //记录分界下标
  count++; //调用计次

  //快速排序
  if(p < r){
    q = patition(A, p, r); //重排并获得分界下标
    quick_sort(A, p, q - 1); //递归对前半个子数组排序
    quick_sort(A, q + 1, r); //递归对后半个子数组排序
  }
}

//主函数
int main(){
  int A[N], n, i;
  scanf("%d", &n); //输入要排序的数列长度

  //输入数列
  for(i = 0; i < n; i++){
    scanf("%d", A[i]);
  }

  //调用快速排序函数
  quick_sort(A, 0, n - 1);

  //输出数列
  for(i = 0; i < n; i++){
    printf("%d ", A[i]);
  }

  //输出quick_sort()的总调用次数
  printf("\ntotal count: %d\n", count);
  return 0;
}
