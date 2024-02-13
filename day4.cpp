#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Two_Sum(int nums[], int n, int target) {
    vector<vector<int>> result;
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) { continue; }
        for (int j = i + 1; j < n - 2; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) { continue; }
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) { ++left; }
                    while (left < right && nums[right] == nums[right - 1]) { --right; }
                    ++left;
                    --right;
                }
                else if (sum < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
    }
    return result;
}

int main() {
    int n, target;
    cout << "Enter total number of elements: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> target;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> ans = Two_Sum(arr, n, target);

    // Print the result
    for (const auto& v : ans) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}