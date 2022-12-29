#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int countnum = 0;
int wantnum;
int* tmp;

//# A[p..q]와 A[q + 1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
//# A[p..q]와 A[q + 1..r]은 이미 오름차순으로 정렬되어 있다.
void mymerge(int* a, int p, int q, int r) {
   
    int  i = p;
   int j = q + 1;
   int t = 0;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) {
            tmp[t++] = a[i++]; //# tmp[t] < -A[i]; t++; i++;
            countnum++;
        }
        else {
            tmp[t++] = a[j++];  //# tmp[t] < -A[j]; t++; j++;
            countnum++;
        }
        if (countnum == wantnum)
            cout << tmp[t - 1];
    }
    while (i <= q) {  //# 왼쪽 배열 부분이 남은 경우
        tmp[t++] = a[i++];
        countnum++;
        if (countnum == wantnum)
            cout << tmp[t - 1];
    }
    while (j <= r) {  //# 오른쪽 배열 부분이 남은 경우
        tmp[t++] = a[j++];
        countnum++;
        if (countnum == wantnum)
            cout << tmp[t - 1];
    }
    i = p; t = 0;
    while (i <= r)  //# 결과를 A[p..r]에 저장
        a[i++] = tmp[t++];
}

void mergesort(int* a, int p, int r) {
    //A[p..r]을 오름차순 정렬한다.
        if (p < r) {
            int q = (p + r) / 2;       //# q는 p, r의 중간 지점
            mergesort(a, p, q);      //# 전반부 정렬
            mergesort(a, q + 1, r);  //# 후반부 정렬
            mymerge(a, p, q, r);        //# 병합
        }
}



int main() {
    int sizeofarr;
    cin >> sizeofarr >> wantnum;
    int* a;
    a = new int[sizeofarr];
    tmp = new int[sizeofarr];
    for (int i = 0; i < sizeofarr; i++) {
        int thisnum;
        cin >> thisnum;
        a[i] = thisnum;
    }

    mergesort(a, 0, sizeofarr - 1);
    if (countnum < wantnum)
        cout << -1;
}