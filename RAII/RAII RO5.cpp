#include <memory>

// RULE OF 5

template <typename T>
class Rules {
public:
    Rules(T* resource)
        : ptr_(resource) {}

    Rules(Rules const& other)
        : ptr_(new T{*other.ptr_}) {}  // konstruktor kopiujący

    Rules& operator=(Rules const& other) {
        if (&other == this) {
            ptr_ = new T{*other.ptr_};  // self assignmed
        }
        return *this;
    }  // kopiujacy konstruktor przypisania

    Rules(Rules&& other)
        : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }  // konstruktor przenoszacy

    Rules& operator=(Rules&& other) {
        if (&other != this) {
            other.ptr_ = nullptr;
            ptr_ = other.ptr_;  // self assignmed
        }
        return *this;

    }  // przenoszacy operator przypisania

    ~Rules() {
        delete ptr_;
    }

private:
    T* ptr_;
};

int main() {
    Rules<int> r{new int{42}};  // konstruktor kopiujacy
    auto r2 = r;                // kopiujacy konstruktor przypisania
    r = r;                      // self assignmed
    auto r3 = std::move(r);     // konstruktor przenoszący
    r = std::move(r3);          // przenoszący operator przypisania
}