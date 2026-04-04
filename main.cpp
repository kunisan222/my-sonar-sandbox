#include <iostream>
#include <string>

int main() {
    const char* ptr;
    {
        std::string s = "hello";
        ptr = s.c_str(); 
    } // ここでsが消える
    std::cout << ptr << std::endl; // 不正な参照（バグ）
    return 0;
}