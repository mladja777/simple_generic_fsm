#include <iostream>

#define PRINT std::cout << __PRETTY_FUNCTION__ << std::endl

template<typename S, typename E>
auto OnEvent(S&& s, E&& e) {
    PRINT;
    return std::forward<S>(s);
}

#include "fsm.hpp"
#include <cassert>

namespace FSM1 {

namespace S {

struct A {
    A() { PRINT; }
    ~A() {}
    A(const A&) { assert(true); }
    A(A&&) { PRINT; }
    A& operator=(const A&) {
        assert(false);
        return *this;
    }
    A& operator=(A&&) {
        PRINT;
        return *this;
    }
};
struct B {};
struct C {};
struct D {};

} // namespace S

namespace E {

struct A {
    A() { PRINT; }
    ~A() {}
    A(const A&) { assert(true); }
    A(A&&) { PRINT; }
    A& operator=(const A&) {
        assert(false);
        return *this;
    }
    A& operator=(A&&) {
        PRINT;
        return *this;
    }
};
struct B {};
struct C {};
struct D {};

} // namespace E

using States = fsm::States<S::A, S::B, S::C, S::D>;
using Events = fsm::Events<E::A, E::B, E::C, E::D>;

} // namespace FSM1

namespace FSM2 {

namespace S {

struct A {
    A() { PRINT; }
    ~A() {}
    A(const A&) { assert(true); }
    A(A&&) { PRINT; }
    A& operator=(const A&) {
        assert(false);
        return *this;
    }
    A& operator=(A&&) {
        PRINT;
        return *this;
    }
};
struct B {};
struct C {};
struct D {};

} // namespace S

namespace E {

struct A {
    A() { PRINT; }
    ~A() {}
    A(const A&) { assert(true); }
    A(A&&) { PRINT; }
    A& operator=(const A&) {
        assert(false);
        return *this;
    }
    A& operator=(A&&) {
        PRINT;
        return *this;
    }
};
struct B {};
struct C {};
struct D {};

} // namespace E

using States = fsm::States<S::A, S::B, S::C, S::D>;
using Events = fsm::Events<E::A, E::B, E::C, E::D>;

} // namespace FSM2

int main() {
    fsm::StateMachine<FSM1::States, FSM1::Events> fsm1;
    std::cout << "*******************" << std::endl;
    fsm1.Initialize(FSM1::S::A {});
    std::cout << "*******************" << std::endl;
    fsm1.ProcessEvent(FSM1::E::A {});

    return 0;
}
