#include <iostream>
#include <cstdio> // printf のために必要

// 可変引数マクロの定義
// ##__VA_ARGS__ は、引数が空の時のコンパイルエラーを防ぐための GCC/Clang 拡張です
#define MY_LOG(fmt, ...) printf("[LOG] " fmt "\n", ##__VA_ARGS__)

int main() {
    // 1. 文字列のみ
    MY_LOG("Hello, World!");

    // 2. 数値を埋め込む
    int value = 42;
    MY_LOG("The value is %d", value);

    // 3. 複数の引数
    MY_LOG("User: %s, ID: %d", "Alice", 101);

    return 0;
}