#include <iostream>
#include <vector>

int main() {
    // 1. 未定義動作 (Undefined Behavior)
    // 自動解析はコンパイルオプション（-std=c++17等）を知らないため、
    // 配列の境界外参照などの複雑なデータフローを追えません。
    int arr[3] = {1, 2, 3};
    int x = arr[5]; // ★本来なら「Out of bound access」でレッドカード

    // 2. メモリリーク (Memory Leak)
    // C++のビルド情報がないと、newしたメモリがどこで解放されるべきか計算できません。
    int* leak = new int[100];
    if (x > 0) {
        return 1; // ★本来なら「Memory leak」でレッドカード
    }
    delete[] leak;

    // 3. ヌルポインタ参照 (Null Pointer Dereference)
    int* p = nullptr;
    if (arr[0] == 1) {
        // 複雑な条件分岐の中でのポインタ操作は、
        // プリプロセッサやヘッダーの解釈ができない自動解析ではスルーされます。
        std::cout << *p << std::endl; // ★本来なら「Null pointer dereference」でレッドカード
    }

    return 0;
}