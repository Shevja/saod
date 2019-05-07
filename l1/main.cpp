#include <chrono>
#include <iostream>
#include <functional>
#include <vector>


void oddEvenSort(std::vector<int>& v, std::function<bool(int a, int b)> comparator)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (std::size_t i = 1; i < v.size() - 1; i += 2)
        {
            if (comparator(v[i], v[i+1]))
             {
                std::swap(v[i], v[i+1]);
                isSorted = false;
              }
        }
        for (std::size_t i = 0; i < v.size() - 1; i += 2)
        {
            if (comparator(v[i], v[i+1]))
            {
                std::swap(v[i], v[i+1]);
                isSorted = false;
            }
        }
    }
}

void printArray(std::vector<int> v)
{
   for (auto element : v)
       std::cout << element << " ";
   std::cout << std::endl;
}

void fill_vec_rand(std::vector<int>& v)
{
    for(size_t i = 0; i < v.size(); ++i) {
        v[i] = rand() % 100000;
	}
}

int main()
{
    srand(0);
	std::cout << "size v" << std::endl;
	size_t size;
	std::cin >> size;
    std::vector<int> v(size);
	fill_vec_rand(v);
    //printArray(v);
	auto start = std::chrono::system_clock::now();
    oddEvenSort(v, [](int a, int b) -> bool {
        return a > b;
    });
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = end - start;
    //printArray(v);
	std::cout << "Elapsed time: " << elapsed.count() << "s" << std::endl;
    return 0;
}
