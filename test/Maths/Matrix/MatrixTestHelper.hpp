#pragma once

#include <string>
#include <sstream>

#include <LuminolMaths/Matrix.hpp>

namespace MatrixTestHelper {

template <typename T, size_t M, size_t N>
auto convert_matrix_to_string(const Luminol::Maths::Matrix<T, M, N>& matrix)
    -> std::string {
    std::ostringstream output(std::ostringstream::ate);

    output << "Displaying Matrix of size " << M << "x" << N;

    for (size_t row = 0; row < M; ++row) {
        output << "\n[";
        for (size_t column = 0; column < N; ++column) {
            output << "\t" << matrix[row].at(column);
        }
        output << "\t]";
    }

    return output.str();
};

}  // namespace MatrixTestHelper
