#include <iostream>
#include <vector>
#include "TP_1.h"

int input_int()
{
    int N;
    for (;;) {
        if ((std::cin >> N).good())
            return N;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Error: Invalid value. Please, try again\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<int> input_nums(int length) {
    std::vector<int> input_numbers;
    std::vector<int>::iterator iter;
    int input_number;
    bool enter = true;
    for (auto iter = 0; iter < length; iter++) {
        std::cout << "num" << iter+1 << ">";
        input_number = input_int();
        //std::cin >> input_number;
        input_numbers.push_back(input_number);
    }
    return input_numbers;
}

void print_result(std::vector<int>* values) {
    for (auto x : *values) {
        std::cout << x << " ";
    }
}

int main()
{
    std::cout << "Hello!\nInput the array of ints to find the most common number\nTo confirm a number, press Enter\nEnter the length of a array\n>";
    int length_of_array;
    length_of_array = input_int();
    //std::cin >> length_of_array;
    std::vector<int> numbers = input_nums(length_of_array);
    std::vector<int> *most_common_value = array_counting(&numbers);
    std::cout << "\nThe result> ";
    print_result(most_common_value);
    delete most_common_value;
    return 0;
}