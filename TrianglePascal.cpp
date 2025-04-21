#include <iostream>
#include <iomanip>

int32_t InputPositiveInteger(int32_t& n);
int32_t** CreatePascalTriangle(int32_t);
void FillPascalTriangle(int32_t** , int32_t );
void PrintPascalTriangle(int32_t** , int32_t);
void DeletePascalTriangle(int32_t** , int32_t);

int main() {
    int32_t n{};
    InputPositiveInteger(n);
    
    int32_t** triangle = CreatePascalTriangle(n);
    FillPascalTriangle(triangle, n);
    PrintPascalTriangle(triangle, n);
    DeletePascalTriangle(triangle, n);

    return 0;
}


int32_t InputPositiveInteger(int32_t& n) {
    
        std::cout << "Enter the number of rows for Pascal's triangle (1-20): ";
        if (!(std::cin >> n)) {
            std::cout << "Invalid input. Please enter a number.\n";
        }
        else if (n < 1 || n > 20) {
            std::cout << "Please enter a number between 1 and 20.\n";
        }
        
    return n;
}


int32_t** CreatePascalTriangle(int32_t n) {
    int32_t** triangle = new int*[n];
    for (size_t i = 0; i < n; ++i) {
        triangle[i] = new int32_t[i+1];
    }
    return triangle;
}


void FillPascalTriangle(int32_t** triangle, int32_t n) {
    for (size_t line = 0; line < n; ++line) {
        for (size_t k = 0; k <= line; ++k) {
            if (k == 0 || k == line) {
                triangle[line][k] = 1;
            } else {
                triangle[line][k] = triangle[line-1][k-1] + triangle[line-1][k];
            }
        }
    }
}


void PrintPascalTriangle(int32_t** triangle, int32_t n) {
    for (size_t line = 0; line < n; ++line) {
        std::cout << std::setw((n - line - 1) * 3) << "";
        for (size_t k = 0; k <= line; ++k) {
            std::cout << std::setw(6) << triangle[line][k];
        }
        std::cout << "\n";
    }
}


void DeletePascalTriangle(int32_t** triangle, int32_t n) {
    for (size_t i = 0; i < n; ++i) {
        delete[] triangle[i];
    }
    delete[] triangle;
}
