#include <iostream>
using namespace std;
void arrange_number(int arr[], int n)
{
    int Tone = 0, Ttwo = 0, Tzero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            Tzero++;
        }
        if (arr[i] == 1)
        {
            Tone++;
        }
        if (arr[i] == 2)
        {
            Ttwo++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (Tzero != 0)
        {
            arr[i] = 0;
            Tzero--;
        }
        else if (Tone != 0)
        {
            arr[i] = 1;
            Tone--;
        }
        else if (Ttwo != 0)
        {
            arr[i] = 2;
            Ttwo--;
        }
    }
    cout<<"Output : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "enter total ele : ";
    cin >> n;
    int arr[n];
    cout << "Input : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arrange_number(arr, n);
}