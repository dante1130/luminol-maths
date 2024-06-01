#pragma once

#include <array>

namespace Luminol::Maths {

/**
 * A row-major matrix class.
 */
template <typename T, size_t M, size_t N>
class Matrix {
public:
    using Row = std::array<T, N>;
    using MatrixType = std::array<Row, M>;

    [[nodiscard]] constexpr Matrix(const MatrixType& matrix) : matrix{matrix} {}

    // NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)
    template <typename OtherT>
    [[nodiscard]] constexpr Matrix(const Matrix<OtherT, M, N>& other)
        requires(std::is_convertible_v<T, OtherT>)
    {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                this->matrix[i][j] = static_cast<T>(other[i][j]);
            }
        }
    }

    [[nodiscard]] constexpr static auto zero() -> Matrix {
        return Matrix{MatrixType{}};
    }

    [[nodiscard]] constexpr static auto identity() -> Matrix
        requires(M == N)
    {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            result.matrix[i][i] = T{1};
        }
        return result;
    }

    [[nodiscard]] constexpr auto transpose() const -> Matrix<T, N, M> {
        auto result = Matrix<T, N, M>::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result[j][i] = this->matrix[i][j];
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator[](size_t index) -> std::array<T, N>& {
        return this->matrix.at(index);
    }

    [[nodiscard]] constexpr auto operator[](size_t index) const
        -> const std::array<T, N>& {
        return this->matrix.at(index);
    }

    [[nodiscard]] constexpr auto operator+(const Matrix& other) const
        -> Matrix {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.matrix.at(i).at(j) =
                    this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator-(const Matrix& other) const
        -> Matrix {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator*(const Matrix& other) const
        -> Matrix {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                for (size_t k = 0; k < N; ++k) {
                    result.matrix[i][j] +=
                        this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator*(T scalar) const -> Matrix {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.matrix[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator/(T scalar) const -> Matrix {
        auto result = Matrix::zero();
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.matrix[i][j] = this->matrix[i][j] / scalar;
            }
        }
        return result;
    }

    [[nodiscard]] constexpr auto operator==(const Matrix& other) const -> bool {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (this->matrix[i][j] != other.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    constexpr auto operator+=(const Matrix& other) -> Matrix& {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                this->matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    constexpr auto operator-=(const Matrix& other) -> Matrix& {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                this->matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }

    constexpr auto operator*=(const Matrix& other) -> Matrix& {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                for (size_t k = 0; k < N; ++k) {
                    this->matrix[i][j] +=
                        this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return *this;
    }

    constexpr auto operator*=(T scalar) -> Matrix& {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                this->matrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    constexpr auto operator/=(T scalar) -> Matrix& {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                this->matrix[i][j] /= scalar;
            }
        }
        return *this;
    }
    // NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)

private:
    MatrixType matrix;
};

using Matrix2x2 = Matrix<double, 2, 2>;
using Matrix2x2f = Matrix<float, 2, 2>;
using Matrix3x3 = Matrix<double, 3, 3>;
using Matrix3x3f = Matrix<float, 3, 3>;
using Matrix4x4 = Matrix<double, 4, 4>;
using Matrix4x4f = Matrix<float, 4, 4>;

using Matrix2x3 = Matrix<double, 2, 3>;
using Matrix2x3f = Matrix<float, 2, 3>;
using Matrix2x4 = Matrix<double, 2, 4>;
using Matrix2x4f = Matrix<float, 2, 4>;
using Matrix3x2 = Matrix<double, 3, 2>;
using Matrix3x2f = Matrix<float, 3, 2>;
using Matrix3x4 = Matrix<double, 3, 4>;
using Matrix3x4f = Matrix<float, 3, 4>;
using Matrix4x2 = Matrix<double, 4, 2>;
using Matrix4x2f = Matrix<float, 4, 2>;
using Matrix4x3 = Matrix<double, 4, 3>;
using Matrix4x3f = Matrix<float, 4, 3>;

}  // namespace Luminol::Maths
