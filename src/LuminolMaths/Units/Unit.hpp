#pragma once

#include <concepts>

namespace Luminol::Units {

enum class UnitEnum {
    Length,
    Time,
    Angle,
    Velocity,
    Mass,
    Acceleration,
    Energy,
    Force,
};

template <typename T, const T& Num, const T& Den>
struct RefRatio {
    constexpr static auto num = Num;
    constexpr static auto den = Den;
};

template <UnitEnum Type, typename Ratio>
struct UnitType {
    constexpr static auto type = Type;
    using ratio = Ratio;
};

template <std::floating_point T, typename U>
class Unit {
public:
    constexpr Unit(const T& value) : value(value) {}

    template <typename OtherU>
    constexpr Unit(const Unit<T, OtherU>& other)
        : value(other.template as<U>().get_value()) {}

    template <typename OtherU>
    constexpr auto operator=(const Unit<T, OtherU>& other) -> Unit& {
        this->value = other.template as<U>().get_value();
        return *this;
    }

    [[nodiscard]] constexpr auto get_value() const -> T { return this->value; }

    template <typename NewU>
        requires(U::type == NewU::type)
    [[nodiscard]] constexpr auto as() const -> Unit<T, NewU> {
        if constexpr (std::same_as<U, NewU>) {
            return Unit<T, NewU>{this->get_value()};
        } else {
            constexpr auto ratio =
                static_cast<T>(U::ratio::num) / static_cast<T>(U::ratio::den);
            constexpr auto new_ratio = static_cast<T>(NewU::ratio::num) /
                                       static_cast<T>(NewU::ratio::den);

            static_assert(ratio != 0);
            static_assert(new_ratio != 0);

            return Unit<T, NewU>{this->get_value() * ratio / new_ratio};
        }
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator+(const Unit<T, OtherU>& other) const
        -> Unit {
        return Unit<T, U>{
            this->get_value() + other.template as<U>().get_value(),
        };
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator-(const Unit<T, OtherU>& other) const
        -> Unit<T, U> {
        return Unit<T, U>{
            this->get_value() - other.template as<U>().get_value(),
        };
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator*(const Unit<T, OtherU>& other) const
        -> Unit<T, U> {
        return Unit<T, U>{
            this->get_value() * other.template as<U>().get_value(),
        };
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator/(const Unit<T, OtherU>& other) const
        -> Unit<T, U> {
        return Unit<T, U>{
            this->get_value() / other.template as<U>().get_value(),
        };
    }

    [[nodiscard]] constexpr auto operator*(const T& scalar) const -> Unit {
        return Unit<T, U>{this->get_value() * scalar};
    }

    [[nodiscard]] constexpr auto operator/(const T& scalar) const -> Unit {
        return Unit<T, U>{this->get_value() / scalar};
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator==(const Unit<T, OtherU>& other) const
        -> bool {
        return this->get_value() == other.template as<U>().get_value();
    }

    template <typename OtherU>
    [[nodiscard]] constexpr auto operator<=>(const Unit<T, OtherU>& other
    ) const {
        return this->get_value() <=> other.template as<U>().get_value();
    }

    template <typename OtherU>
    constexpr auto operator+=(const Unit<T, OtherU>& other) -> Unit& {
        this->value += other.template as<U>().get_value();
        return *this;
    }

    template <typename OtherU>
    constexpr auto operator-=(const Unit<T, OtherU>& other) -> Unit& {
        this->value -= other.template as<U>().get_value();
        return *this;
    }

    template <typename OtherU>
    constexpr auto operator*=(const Unit<T, OtherU>& other) -> Unit& {
        this->value *= other.template as<U>().get_value();
        return *this;
    }

    template <typename OtherU>
    constexpr auto operator/=(const Unit<T, OtherU>& other) -> Unit& {
        this->value /= other.template as<U>().get_value();
        return *this;
    }

    [[nodiscard]] constexpr auto operator*=(const T& scalar) -> Unit& {
        this->value *= scalar;
        return *this;
    }

    [[nodiscard]] constexpr auto operator/=(const T& scalar) -> Unit& {
        this->value /= scalar;
        return *this;
    }

    [[nodiscard]] constexpr auto operator-() const -> Unit {
        return Unit<T, U>{-this->get_value()};
    }

private:
    T value = {};
};

}  // namespace Luminol::Units
