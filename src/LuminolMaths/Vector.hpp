#pragma once

#include <cmath>
#include <array>
#include <stdexcept>

namespace Luminol::Maths {

/**
 * \brief A vector class with N elements, where N is a number between 1 and 4.
 *
 * This vector is mainly designed to be used with 2D, 3D and 4D vectors, and
 * contains a number of helper functions to perform common operations on
 * vectors.
 *
 * The underlying data is guaranteed that it is contiguous in memory,
 * so it can be submitted to graphics APIs that expect vector types.
 *
 * \tparam T The underlying type of the elements in the vector.
 * \tparam N The number of elements in the vector.
 */
template <typename T, size_t N>
    requires(N >= 1 && N <= 4)
class Vector {
public:
    [[nodiscard]] constexpr Vector() = default;

    // NOLINTBEGIN(readability-identifier-length)
    /**
     * \brief Constructs a vector with a size of 1 with the given x component.
     * \param x The x component of the vector.
     * \pre N >= 1
     */
    [[nodiscard]] constexpr Vector(T x)
        requires(N == 1)
        : vector{x} {}

    /**
     * \brief Constructs a vector with a size of 2 with the given x and y
     * components.
     * \param x The x component of the vector.
     * \param y The y component of the vector.
     * \pre N >= 2
     */
    [[nodiscard]] constexpr Vector(T x, T y)
        requires(N == 2)
        : vector{x, y} {}

    /**
     * \brief Constructs a vector with a size of 3 with the given x, y and z
     * components.
     * \param x The x component of the vector.
     * \param y The y component of the vector.
     * \param z The z component of the vector.
     * \pre N >= 3
     */
    [[nodiscard]] constexpr Vector(T x, T y, T z)
        requires(N == 3)
        : vector{x, y, z} {}

    /**
     * \brief Constructs a vector with a size of 4 with the given x, y, z and w
     * components.
     * \param x The x component of the vector.
     * \param y The y component of the vector.
     * \param z The z component of the vector.
     * \param w The w component of the vector.
     * \pre N >= 4
     */
    [[nodiscard]] constexpr Vector(T x, T y, T z, T w)
        requires(N == 4)
        : vector{x, y, z, w} {}
    // NOLINTEND(readability-identifier-length)

    /**
     * \brief Returns the x component of the vector.
     * \pre N >= 1
     * \return The x component of the vector.
     */
    [[nodiscard]] constexpr auto x() const -> T
        requires(N >= 1)
    {
        return this->vector[0];
    }

    /**
     * \brief Returns the x component of the vector.
     * \pre N >= 1
     * \return The x component of the vector.
     */
    [[nodiscard]] constexpr auto x() -> T&
        requires(N >= 1)
    {
        return this->vector[0];
    }

    /**
     * \brief Returns the y component of the vector.
     * \pre N >= 2
     * \return The y component of the vector.
     */
    [[nodiscard]] constexpr auto y() const -> T
        requires(N >= 2)
    {
        return this->vector[1];
    }

    /**
     * \brief Returns the y component of the vector.
     * \pre N >= 2
     * \return The y component of the vector.
     */
    [[nodiscard]] constexpr auto y() -> T&
        requires(N >= 2)
    {
        return this->vector[1];
    }

    /**
     * \brief Returns the z component of the vector.
     * \pre N >= 3
     * \return The z component of the vector.
     */
    [[nodiscard]] constexpr auto z() const -> T
        requires(N >= 3)
    {
        return this->vector[2];
    }

    /**
     * \brief Returns the z component of the vector.
     * \pre N >= 3
     * \return The z component of the vector.
     */
    [[nodiscard]] constexpr auto z() -> T&
        requires(N >= 3)
    {
        return this->vector[2];
    }

    /**
     * \brief Returns the w component of the vector.
     * \pre N == 4
     * \return The w component of the vector.
     */
    [[nodiscard]] constexpr auto w() const -> T
        requires(N == 4)
    {
        return this->vector[3];
    }

    /**
     * \brief Returns the w component of the vector.
     * \pre N == 4
     * \return The w component of the vector.
     */
    [[nodiscard]] constexpr auto w() -> T&
        requires(N == 4)
    {
        return this->vector[3];
    }

    // NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)
    /**
     * \brief Returns the length or magnitude of the vector.
     * \return The length of the vector.
     */
    [[nodiscard]] constexpr auto length() const -> T {
        auto result = T{0};

        for (size_t i = 0; i < N; ++i) {
            result += this->vector[i] * this->vector[i];
        }

        return std::sqrt(result);
    }

    /**
     * \brief Returns a normalized version of the vector. Note that this does
     * not modify the original vector.
     * \return The normalized version of the vector.
     * \return A zero vector if the length of the vector is 0 to avoid division
     * by zero.
     */
    [[nodiscard]] constexpr auto normalized() const -> Vector {
        const auto length = this->length();

        if (length == 0) {
            return Vector{};
        }

        return *this / length;
    }

    /**
     * \brief Returns the dot product of this vector and another vector.
     * \param other The other vector to calculate the dot product with.
     * \return The dot product of this vector and the other vector.
     */
    [[nodiscard]] constexpr auto dot(const Vector& other) const -> T {
        auto result = T{0};

        for (size_t i = 0; i < N; ++i) {
            result += this->vector[i] * other.vector[i];
        }

        return result;
    }

    /**
     * \brief Returns the cross product of this vector and another vector.
     * \param other The other vector to calculate the cross product with.
     * \pre N == 3
     * \return The cross product of this vector and the other vector.
     */
    [[nodiscard]] constexpr auto cross(const Vector& other) const -> Vector
        requires(N == 3)
    {
        return Vector{
            this->y() * other.z() - this->z() * other.y(),
            this->z() * other.x() - this->x() * other.z(),
            this->x() * other.y() - this->y() * other.x(),
        };
    }

    /**
     * \brief Returns the vector component at the given index. E.g. `vector[0]`
     * returns the x component of the vector.
     * \param index The index of the element to return.
     * \pre index < N
     * \throw std::out_of_range If the index is out of range.
     * \return The vector component at the given index.
     */
    [[nodiscard]] constexpr auto operator[](size_t index) -> T& {
        return this->vector.at(index);
    }

    /**
     * \brief Returns the vector component at the given index. E.g. `vector[0]`
     * returns the x component of the vector.
     * \param index The index of the element to return.
     * \pre index < N
     * \throw std::out_of_range If the index is out of range.
     * \return The vector component at the given index.
     */
    [[nodiscard]] constexpr auto operator[](size_t index) const -> const T& {
        return this->vector.at(index);
    }

    /**
     * \brief Returns a vector with the summed components of this vector and
     * another vector.
     * \param other The other vector to add to this vector.
     * \pre N == other.N
     * \return A vector with the summed components of this vector and the other
     * vector.
     */
    [[nodiscard]] constexpr auto operator+(const Vector& other) const
        -> Vector {
        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = this->vector[i] + other.vector[i];
        }
        return result;
    }

    /**
     * \brief Returns a vector with the subtracted components of this vector and
     * another vector.
     * \param other The other vector to subtract from this vector.
     * \pre N == other.N
     * \return A vector with the subtracted components of this vector and the
     * other vector.
     */
    [[nodiscard]] constexpr auto operator-(const Vector& other) const
        -> Vector {
        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = this->vector[i] - other.vector[i];
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator*(const Vector& other) const
        -> Vector {
        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = this->vector[i] * other.vector[i];
        }
        return result;
    }

    /**
     * \brief Returns a vector with the components of this vector multiplied by
     * a scalar.
     * \param scalar The scalar to multiply the components of this
     * vector by.
     * \return A vector with the components of this vector multiplied
     * by a scalar.
     */
    [[nodiscard]] constexpr auto operator*(const T& scalar) const -> Vector {
        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = this->vector[i] * scalar;
        }
        return result;
    }

    /**
     * \brief Returns a vector with the components of this vector divided by a
     * scalar.
     * \param scalar The scalar to divide the components of this vector by.
     * \pre scalar != 0
     * \throw std::runtime_error If the scalar is 0.
     * \return A vector with the components of this vector divided by a scalar.
     */
    [[nodiscard]] constexpr auto operator/(const T& scalar) const -> Vector {
        if (scalar == 0) {
            throw std::runtime_error("Cannot divide by zero");
        }

        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = this->vector[i] / scalar;
        }
        return result;
    }

    /**
     * \brief Adds the components of another vector to this vector.
     * \param other The other vector to add to this vector.
     * \pre N == other.N
     * \return A reference to this vector after the operation.
     */
    constexpr auto operator+=(const Vector& other) -> Vector& {
        for (size_t i = 0; i < N; ++i) {
            this->vector[i] += other.vector[i];
        }
        return *this;
    }

    /**
     * \brief Subtracts the components of another vector from this vector.
     * \param other The other vector to subtract from this vector.
     * \pre N == other.N
     * \return A reference to this vector after the operation.
     */
    constexpr auto operator-=(const Vector& other) -> Vector& {
        for (size_t i = 0; i < N; ++i) {
            this->vector[i] -= other.vector[i];
        }
        return *this;
    }

    constexpr auto operator*=(const Vector& other) -> Vector& {
        for (size_t i = 0; i < N; ++i) {
            this->vector[i] *= other.vector[i];
        }
        return *this;
    }

    /**
     * \brief Multiplies the components of this vector by a scalar.
     * \param scalar The scalar to multiply the components of this vector by.
     * \return A reference to this vector after the operation.
     */
    constexpr auto operator*=(const T& scalar) -> Vector& {
        for (size_t i = 0; i < N; ++i) {
            this->vector[i] *= scalar;
        }
        return *this;
    }

    /**
     * \brief Divides the components of this vector by a scalar.
     * \param scalar The scalar to divide the components of this vector by.
     * \pre scalar != 0
     * \throw std::runtime_error If the scalar is 0.
     * \return A reference to this vector after the operation.
     */
    constexpr auto operator/=(const T& scalar) -> Vector& {
        if (scalar == 0) {
            throw std::runtime_error("Cannot divide by zero");
        }

        for (size_t i = 0; i < N; ++i) {
            this->vector[i] /= scalar;
        }
        return *this;
    }

    /**
     * \brief Returns whether this vector is equal to another vector.
     * \param other The other vector to compare to.
     * \return Whether this vector is equal to the other vector.
     */
    [[nodiscard]] constexpr auto operator==(const Vector& other) const -> bool {
        for (size_t i = 0; i < N; ++i) {
            if (this->vector[i] != other.vector[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * \brief Returns the negated version of this vector.
     * \return The negated version of this vector.
     */
    [[nodiscard]] constexpr auto operator-() const -> Vector {
        auto result = Vector{};
        for (size_t i = 0; i < N; ++i) {
            result.vector[i] = -this->vector[i];
        }
        return result;
    }
    // NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)

private:
    /// A fixed-size array of N components to represent the vector.
    std::array<T, N> vector;
};

using Vector2 = Vector<double, 2>;
using Vector2f = Vector<float, 2>;
using Vector3 = Vector<double, 3>;
using Vector3f = Vector<float, 3>;
using Vector4 = Vector<double, 4>;
using Vector4f = Vector<float, 4>;

}  // namespace Luminol::Maths
