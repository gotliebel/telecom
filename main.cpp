#include <iostream>
#include <vector>

void InvertBits(std::vector<char>& ptr, size_t start_bit = 0, size_t end_bit = 7);

void InvertBits(std::vector<char>& ptr, char mask);

void InvertBits(std::vector<char>& ptr, std::vector<char>& masks);

void ShowInvertionAllBits();

void ShowInvertionFromToBits();

void ShowInvertionMask();

void ShowInvertionDifferentMasks();

void ShowData(const std::vector<char>&);

std::vector<char> MakeData();

int main() {
    ShowInvertionAllBits();
    ShowInvertionFromToBits();
    ShowInvertionMask();
    ShowInvertionDifferentMasks();
    return 0;
}

void InvertBits(std::vector<char>& ptr, size_t start_bit, size_t end_bit) {
    if (ptr.size() == 0 || start_bit >= end_bit || end_bit >= ptr.size() * 8) {
        std::cout << "Некорректные параметры\n";
        return;
    }

    for (size_t i = 0; i < ptr.size(); ++i) {
        for (size_t j = start_bit; j <= end_bit; ++j) {
            ptr[i] ^= (1 << j);
        }
    }
}

void InvertBits(std::vector<char>& ptr, char mask) {
    if (ptr.size() == 0) {
        std::cout << "Некорректные параметры\n";
        return;
    }

    for (size_t i = 0; i < ptr.size(); ++i) {
        ptr[i] ^= mask;
    }
}

void InvertBits(std::vector<char>& ptr, std::vector<char>& masks) {
    if (ptr.size() == 0 || masks.size() == 0) {
        std::cout << "Некорректные параметры\n";
        return;
    }

    if (ptr.size() > masks.size()) {
        for (int i = masks.size(); i < ptr.size(); i++) {
            masks.push_back(masks[0]);
        }
    }

    for (size_t i = 0; i < ptr.size(); ++i) {
        ptr[i] ^= masks[i];
    }
}

std::vector<char> MakeData() {
    std::vector<char> memory = {'a', 'b', 'c', 'd', 'e'};
    return memory;
}

void ShowData(const std::vector<char>& ptr) {
    for (size_t i = 0; i < ptr.size(); ++i) {
        std::cout << std::bitset<8>(ptr[i]) << " ";
    }
    std::cout << '\n';
}

void ShowInvertionAllBits() {
    std::cout << "InvertionAllBits\n";
    std::vector<char> data = MakeData();
    ShowData(data);
    InvertBits(data);
    ShowData(data);
}

void ShowInvertionFromToBits() {
    std::cout << "InvertionFromToBits\n";
    std::vector<char> data = MakeData();
    ShowData(data);
    InvertBits(data, 1, 4);
    ShowData(data);
}

void ShowInvertionMask() {
    std::cout << "InvertionMask\n";
    std::vector<char> data = MakeData();
    ShowData(data);
    InvertBits(data, 'f');
    ShowData(data);
}

void ShowInvertionDifferentMasks() {
    std::cout << "InvertionDifferentMasks\n";
    std::vector<char> data = MakeData();
    std::vector<char> masks = {'b', 'c', 'd', 'e', 'f'};
    ShowData(data);
    InvertBits(data, masks);
    ShowData(data);
}
