#include <iostream>

using namespace std;
// AT BT CT WT TurnR

void swap(int *a, int *b)
{
    int *temp;
    temp =a;
    a =b;
    b = temp;
}
void ArrangeArrival(int arr[][6], int n)
{
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j][1] > arr[j+1][1])
            {
                swap(arr[j][1], arr[j+1][1]);
            }
        }
    }
}
void CompletelyTime(int arr[][6], int n)
{
    int val;
    int tam, low;
    arr[0][3] = arr[0][1] + arr[0][2];
    arr[0][5] = arr[0][3] - arr[0][1];
    arr[0][4] = arr[0][5] - arr[0][2];
    for (int i =0; i < n; i++)
    {
        tam = arr[i-1][3];
        low = arr[i][2];
        for (int j = i; j < n; j++)
        {
            if (tam >= arr[j][1] && low >= arr[j][2])
            {
                low = arr[j][2];
                val = j;
            }

        }
        arr[val][3] = tam + arr[val][2];
        arr[val][5] = arr[val][3] - arr[val][1];
        arr[val][4] = arr[val][5] - arr[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(arr[val][k], arr[i][k])
        }
    }
}
float averageWaitingTime(int arr[][6], int n)
{
    float tong =0;
    for (int i = 0; i < n; i++)
    {
        tong+=arr[i][4];
    }
    return (tong/n);
}
float averageBT(int arr[][6], int n)
{
    float tong = 0;
    for (int i =0; i < n; i++)
    {
        tong +=arr[i][2];
    }
    return (tong\n);
}
int main()
{
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;
    for (int i =0; i < n; i++)
    {
        cout << "Nhap tien trinh thu: " << i+1 <<endl;
        cin >> arr[i][0];
        cout << "Nhap arrival: " << endl;
        cin >> arr[i][1];
        cout << "Nhap Burst Time: " << endl;
        cin >> arr[i][2];
    }

    cout << "-------------------------------------------------";
    cout << "ProcessID\tArrivalTime\tBurstTime\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << "\n";
    }
}
