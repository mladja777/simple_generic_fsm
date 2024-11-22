#ifndef FSM_FSM_HPP
#define FSM_FSM_HPP

#include <variant>

namespace fsm {

template<typename... Ts>
struct Helper {
    using type = std::variant<Ts...>;
};

template<typename... Ts>
using Events = typename Helper<Ts...>::type;

template<typename... Ts>
using States = typename Helper<Ts...>::type;

template<typename S, typename T>
concept ValidState = requires {
    []<typename... Ts>(std::variant<Ts...>) {
        constexpr bool isSame = (std::is_same_v<T, Ts> || ...);
        static_assert(isSame, "Required State does not belong to the State variant.");
    }(S {});
};

template<typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};

template<typename S, typename E>
class StateMachine {
public:
    template<typename T>
        requires ValidState<S, T>
    void Initialize(T&& state) {
        mState = std::forward<T>(state);
    }

    void ProcessEvent(E&& event) {
        mState = std::visit(
            [](S&& state, E&& event) {
                return S { OnEvent(std::forward<S>(state), std::forward<E>(event)) };
            },
            mState,
            std::forward<E>(event));
    }

private:
    S mState;
};

} // namespace fsm

#endif // !FSM_FSM_HPP
