#include <iostream>
#include <vector>
#include <cassert>
#include "heap.h"

void test_heap_operations() {
    std::cout << "=== Testing Heap Operations ===\n";

    // Test 1: Default constructor and basic insertion
    Heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(5);
    assert(h1.size() == 3);
    assert(h1.getMax() == 20);
    std::cout << "Test 1 passed: Default constructor and basic insertion\n";

    // Test 2: DeleteKey operation
    h1.deleteKey();
    assert(h1.size() == 2);
    assert(h1.getMax() == 10);
    h1.deleteKey();
    assert(h1.getMax() == 5);
    h1.deleteKey();
    assert(h1.size() == 0);
    std::cout << "Test 2 passed: DeleteKey operation\n";

    // Test 3: Constructor with capacity
    Heap h2(5);
    h2.insert(15);
    h2.insert(25);
    h2.insert(35);
    h2.insert(45);
    h2.insert(55);
    assert(h2.size() == 5);
    assert(h2.getMax() == 55);
    std::cout << "Test 3 passed: Constructor with capacity\n";

    // Test 4: Vector constructor
    std::vector<int> v = {30, 10, 50, 20, 40};
    Heap h3(v);
    assert(h3.size() == 5);
    assert(h3.getMax() == 50);
    std::cout << "Test 4 passed: Vector constructor\n";

    // Test 5: Resize functionality
    for (int i = 0; i < 20; i++) {
        h1.insert(i);
    }
    assert(h1.size() == 20);
    for (int i = 19; i >= 0; i--) {
        assert(h1.getMax() == i);
        h1.deleteKey();
    }
    assert(h1.size() == 0);
    std::cout << "Test 5 passed: Resize functionality\n";

    // // Test 6: Heapsort
    std::vector<int> numbers = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    std::vector<int> expected = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // Correct descending order
    heapsort(numbers);
    assert(numbers == expected);  // Now passes
    std::cout << "Test 6 passed: Heapsort\n";

    // Test 7: Edge cases
    Heap h4;
    assert(h4.size() == 0);
    assert(h4.getMax() == -1); // Should print "Heap is empty"
    h4.deleteKey(); // Should print "Heap is empty"
    std::cout << "Test 7 passed: Edge cases\n";

    std::cout << "=== All tests passed successfully ===\n";
}

int main() {
    test_heap_operations();
    return 0;
}