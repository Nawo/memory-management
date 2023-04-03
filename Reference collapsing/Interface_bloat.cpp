#include <iostream>

class Gadget {};
void f(const Gadget&) {
    std::cout << "const Gadget&\n";
}
void f(Gadget&) {
    std::cout << "Gadget&\n";
}
void f(Gadget&&) {
    std::cout << "Gadget&&\n";
}

template <typename G>
void use(G&& g) {
    f(std::forward<G>(g));
}  // perfekcyjne

// zamiast tego niżej

// void use(const Gadget& g) {
//     f(g);
// }  // calls f(const Gadget&)
// void use(Gadget& g) {
//     f(g);
// }  // calls f(Gadget&)
// void use(Gadget&& g) {
//     f(std::move(g));
// }  // calls f(Gadget&&)

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);        // calls use(const Gadget&) then calls f(const Gadget&)
    use(g);         // calls use(Gadget&) then calls f(Gadget&)
    use(Gadget());  // calls use(Gadget&&) then calls f(Gadget&&)
}