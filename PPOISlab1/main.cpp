#include "include/CantorSet.hpp"
#include <fstream>
#include <iostream>

void testSetOperations() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ ОПЕРАЦИЙ НАД МНОЖЕСТВАМИ ===" << std::endl;
    
    CantorSet A("{1,2,3,5,4}");
    CantorSet B("{2,3,4,6}");
    
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A + B = " << (A + B) << std::endl;
    std::cout << "A * B = " << (A * B) << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    std::cout << "B - A = " << (B - A) << std::endl;
}



int main() {
    std::string filename = "input.txt";
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return 1;
    }
    
    std::string line;
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::cout << "Исходное: " << line << std::endl;
        CantorSet origin(line);
        
        try {
            CantorSet comp = CantorSet::createCompleteCantorSet(origin);
            std::string CHAR = origin.toDetailedString();
            std::cout<< CHAR;
            std::cout << "---" << std::endl;
            
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
    
    file.close();
    
    
    return 0;
}