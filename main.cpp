#include <cstdio>
#include <string>

// マクロ定義: %s で受け取り、.c_str() を自動的に適用
#define MY_LOG(fmt, ...) printf("[LOG] " fmt "\n", ##__VA_ARGS__)

int main() {
    std::string name = "Gemini";
    std::string status = "Active";

    // 1. std::string を .c_str() で渡す
    MY_LOG("User: %s", name.c_str());

    // 2. 複数の string を組み合わせる
    MY_LOG("User: %s, Status: %s", name.c_str(), status.c_str());

    return 0;
}