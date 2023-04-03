#include <memory>

// RULE OF 0

template <typename T>
class Rules {
public:
    Rules(T* resource)
        : ptr_(resource) {}

    Rules(Rules const& other) = default;             // konstruktor kopiujący
    Rules& operator=(Rules const& other) = default;  // kopiujacy konstruktor przypisania
    Rules(Rules&& other) = default;                  // konstruktor przenoszacy
    Rules& operator=(Rules&& other) = default;       // przenoszacy operator przypisania
    ~Rules() = default;                              // destruktor

private:
    std::shared_ptr<T> ptr_;
};

int main() {
    Rules<int> r{new int{42}};  // konstruktor kopiujacy
    auto r2 = r;                // kopiujacy konstruktor przypisania
    r = r;                      // self assignmed
    auto r3 = std::move(r);     // konstruktor przenoszący
    r = std::move(r3);          // przenoszący operator przypisania
}