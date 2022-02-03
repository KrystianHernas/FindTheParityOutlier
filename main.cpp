#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

std::vector<int> inputArray();
int FindOutlier(std::vector<int>&);

int main()
{
    std::vector<int> input_array = inputArray();
    int a = FindOutlier(input_array);
    std::cout << a<<std::endl;
    return 0;
}

std::vector<int> inputArray() {
    int n = 0, temp = 0; std::vector<int> q;
    std::cout << "Input array size: " << std::endl; std::cin >> n;
    std::cout << "Input expenditure array" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp; q.push_back(temp);
    }
    temp = q.size();
    try {
        if (temp < 1 || temp > 100000 || std::cin.fail()) {
            throw std::invalid_argument("Too large queue");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return q;
};

int FindOutlier(std::vector<int>& arr)
{
    int result = 0, numberOfOddInt = 0, numberOfEvenInt = 0;
    for (int i = 0; i < 3; i++) {
        if (arr[i] % 2 == 0) numberOfEvenInt++;
        else numberOfOddInt++;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (numberOfEvenInt > numberOfOddInt) {
            if (arr[i] % 2 != 0) { result = arr[i]; return result; }
        }else{
            if (arr[i] % 2 == 0) { result = arr[i]; return result; }
        }
    }
}