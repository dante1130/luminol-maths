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

    [[nodiscard]] constexpr auto minor(size_t row, size_t column) const
        -> Matrix<T, M - 1, N - 1>
        requires(M == N && M > 1)
    {
        auto minor_matrix = Matrix<T, M - 1, N - 1>::zero();
        auto minor_row = size_t{0};

        for (size_t i = 0; i < M; ++i) {
            if (i == row) {
                continue;
            }

            auto minor_column = size_t{0};

            for (size_t j = 0; j < N; ++j) {
                if (j == column) {
                    continue;
                }

                minor_matrix[minor_row][minor_column] = this->matrix[i][j];
                ++minor_column;
            }

            ++minor_row;
        }

        return minor_matrix;
    }

    [[nodiscard]] constexpr auto cofactor() const -> Matrix
        requires(M == N)
    {
        auto cofactor_matrix = Matrix<T, M, N>::zero();

        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                const auto sign = ((i + j) % 2 == 0) ? 1 : -1;
                cofactor_matrix[i][j] = this->minor(i, j).determinant() * sign;
            }
        }

        return cofactor_matrix;
    }

    [[nodiscard]] constexpr auto determinant() const -> T
        requires(M == N)
    {
        if constexpr (M == 1) {
            return this->matrix[0][0];
        } else if constexpr (M == 2) {
            return (this->matrix[0][0] * this->matrix[1][1]) -
                   (this->matrix[0][1] * this->matrix[1][0]);
        } else {
            auto result = T{0};
            for (size_t i = 0; i < M; ++i) {
                result += this->matrix[0][i] * this->cofactor()[0][i];
            }
            return result;
        }
    }

    [[nodiscard]] constexpr auto adjugate() const -> Matrix
        requires(M == N)
    {
        return this->cofactor().transpose();
    }

    [[nodiscard]] constexpr auto inverse() const -> Matrix
        requires(M == N)
    {
        const auto det = this->determinant();
        if (det == T{0}) {
            return Matrix::zero();
        }

        return this->adjugate() / det;
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
