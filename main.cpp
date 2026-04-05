#include <iostream>
#include <vector>
#include <memory>   // std::unique_ptr のために必要
#include <string>

int main() {
    // 1. Cスタイル配列ではなく std::vector か std::array を使う
    // std::vector ならサイズ管理が自動で、境界チェック（.at()）も使えます
    std::vector<int> vec = {1, 2, 3};

    // 安全にアクセス（index 5 は存在しないので、本来はアクセスしないロジックにする）
    if (vec.size() > 0) {
        int x = vec[0]; 
        std::cout << "First element: " << x << std::endl;
    }

    // 2. raw pointer (new/delete) ではなくスマートポインタを使う
    // これにより、関数を抜ける際に自動的にメモリが解放され、リークしません
    auto safe_ptr = std::make_unique<int[]>(100);
    safe_ptr[0] = 42;
    // delete[] は不要です（自動で処理されます）

    // 3. 一時オブジェクトのポインタを保持しない
    // std::string の .c_str() を直接使うか、stringオブジェクト自体の寿命を意識します
    std::string s = "hello";
    std::cout << s << std::endl; // 文字列としてそのまま扱うのが最も安全

    // 4. ヌルポインタ参照の防止
    // ポインタを使う場合は、必ず nullptr チェックを行うか、参照（&）を使います
    int val = 100;
    int* p = &val;
    if (p != nullptr) {
        std::cout << "Value: " << *p << std::endl;
    }

    return 0;
}