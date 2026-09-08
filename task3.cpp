#include <iostream>
#include <vector>
using namespace std;

//This function will find the indices

vector<int> findIndices(int arr[], int size, int key) {
    vector<int> indices;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}
void Result(vector<int> result) {
    cout << "{ ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "}" << endl;
}

int main() {
    // Test 1: multiple occurrences
    int arr1[] = {2, 5, 2, 8, 2};
    cout << "Test 1 (multiple occurrences): ";
    Result(findIndices(arr1, 5, 2));

    // Test 2: key not present
    int arr2[] = {1, 3, 5, 7};
    cout << "Test 2 (key not present): ";
    Result(findIndices(arr2, 4, 100));

    // Test 3: empty array
    int arr3[] = {};
    cout << "Test 3 (empty array): ";
  Result(findIndices(arr3, 0, 2));

    return 0;
}