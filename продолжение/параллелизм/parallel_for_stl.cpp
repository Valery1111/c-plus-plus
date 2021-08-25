#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int main()
{
    auto eval = [](auto fun) {
        const auto t1 = std::chrono::high_resolution_clock::now();
        const auto [name, result] = fun();
        const auto t2 = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << std::setprecision(1) << name << " result "
            << result << " took " << ms.count() << " ms\n";
    };
    {
        const std::vector<double> v(100'000'007, 0.1);

        eval([&v] { return std::pair{ "std::find (double)",
            std::find(v.cbegin(), v.cend(), 0.2) }; });
        eval([&v] { return std::pair{ "std::find (double)",
            std::find(std::execution::par, v.cbegin(), v.cend(), 0.2) }; });
        eval([&v] { return std::pair{ "std::reduce (seq, double)",
            std::reduce(std::execution::seq, v.cbegin(), v.cend()) }; });
        eval([&v] { return std::pair{ "std::reduce (par, double)",
            std::reduce(std::execution::par, v.cbegin(), v.cend()) }; });
        eval([&v] { return std::pair{ "std::count (double)",
            std::count(v.cbegin(), v.cend(), 0.1) }; });
        eval([&v] { return std::pair{ "std::count (double)",
            std::count(std::execution::par, v.cbegin(), v.cend(), 0.1) }; });
    } {
        
    }
}
