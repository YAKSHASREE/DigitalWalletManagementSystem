#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int users;
    cin >> users;
    vector<array<int, 2>> arr(users);

    for (int i = 0; i < users; i++) {
        int val1, val2;
        cin >> val1 >> val2;
        arr[i][0] = val1;
        arr[i][1] = val2;
    }

    int transactions;
    cin >> transactions;

    for (int i = 0; i < transactions; i++) {
        int from, to, money;
        cin >> from >> to >> money;
        for (int j = 0; j < users; j++) {
            int user = arr[j][0];
            int amount = arr[j][1];
            if (user == from) {
                if (amount >= money) {
                    arr[j][1] = amount - money;
                    for (int l = 0; l < users; l++) {
                        int user1 = arr[l][0];
                        int amount1 = arr[l][1];
                        if (user1 == to) {
                            arr[l][1] = amount1 + money;
                            break;
                        }
                    }
                    cout << "Success" << "\n";
                    break;
                } else {
                    cout << "Failure" << "\n";
                    break;
                }
            }
        }
    }
    cout << "\n";

    
    sort(arr.begin(), arr.end(), [](const array<int, 2>& a, const array<int, 2>& b) {
        return a[1] < b[1];
    });

    for (int j = 0; j < users; j++) {
        cout << arr[j][0] << " " << arr[j][1] << "\n";
    }

    return 0;
}