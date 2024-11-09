#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> // Para std::setprecision

// Função para reduzir o array de forma serial
int reduceSerial(const std::vector<int>& array) {
    int sum = 0;
    for (int value : array) {
        sum += value;
    }
    return sum;
}

int main() {
    // Array com os tamanhos pedidos
    std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000, 10000000};

    for (int size : sizes) {
        std::vector<int> array(size, 1); // Preenche o array com 1 para simplificar a soma
        auto start = std::chrono::high_resolution_clock::now();

        // Realiza a redução serial
        int result = reduceSerial(array);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        // Calcula o trabalho e passos
        int work = size; // Trabalho total é o número de somas necessárias
        int steps = size; // Passos

        // Exibe os resultados
        std::cout << "Metodo Serial:\n";
        std::cout << "Tamanho do vetor: " << size << "\n";
        std::cout << "Resultado: " << result << "\n";
        std::cout << "Tempo: " << std::fixed << std::setprecision(7) << duration.count() << " segundos\n";
        std::cout << "Trabalho: " << work << "\n";
        std::cout << "Passos: " << steps << "\n\n";
    }
    return 0;
}
