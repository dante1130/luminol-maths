#pragma once

#include <cmath>

#include <LuminolMaths/Matrix.hpp>
#include <LuminolMaths/Vector.hpp>

#include <LuminolMaths/Units/Angle.hpp>

namespace Luminol::Maths::Transform {

struct PerspectiveMatrixParams {
    Luminol::Units::Degrees_f fov = {0.0f};
    float aspect_ratio = {0.0f};
    float near_plane = {0.0f};
    float far_plane = {0.0f};
};

template <typename T>
struct LookAtParams {
    Vector<T, 3> eye;
    Vector<T, 3> target;
    Vector<T, 3> up_vector;
};

template <typename T>
auto left_handed_perspective_projection_matrix(
    const PerspectiveMatrixParams& params
) -> Matrix<T, 4, 4> {
    const auto& [fov, aspect_ratio, near, far] = params;

    const auto tan_half_fov =
        std::tan(fov.as<Luminol::Units::Radian>().get_value() / 2.0f);

    const auto range = far - near;

    // [A] [0] [0] [0]
    // [0] [B] [0] [0]
    // [0] [0] [C] [D]
    // [0] [0] [E] [0]

    auto perspective_matrix = Matrix4x4f::zero();

    // A
    perspective_matrix[0][0] = 1.0f / (aspect_ratio * tan_half_fov);

    // B
    perspective_matrix[1][1] = 1.0f / tan_half_fov;

    // C
    perspective_matrix[2][2] = far / range;

    // D
    perspective_matrix[2][3] = 1.0f;

    // E
    perspective_matrix[3][2] = -near * far / range;

    return perspective_matrix;
}

template <typename T>
auto left_handed_look_at_matrix(const LookAtParams<T>& params)
    -> Matrix<T, 4, 4> {
    const auto& [eye, target, up_vector] = params;

    const auto forward = (target - eye).normalized();
    const auto right = up_vector.cross(forward).normalized();
    const auto up_vec = forward.cross(right);

    auto result = Matrix<T, 4, 4>::identity();

    result[0][0] = right[0];
    result[0][1] = right[1];
    result[0][2] = right[2];
    result[0][3] = -right.dot(eye);

    result[1][0] = up_vec[0];
    result[1][1] = up_vec[1];
    result[1][2] = up_vec[2];
    result[1][3] = -up_vec.dot(eye);

    result[2][0] = forward[0];
    result[2][1] = forward[1];
    result[2][2] = forward[2];
    result[2][3] = -forward.dot(eye);

    return result;
}

template <size_t M, size_t VectorSize>
concept MatrixLimits = requires {
    (M == 2 && VectorSize == 2) || (M == 3 && VectorSize == 3) ||
        (M == 4 && VectorSize == 3);
};

template <typename T, size_t M, size_t VectorSize>
constexpr auto translate(const Vector<T, VectorSize>& translation)
    -> Matrix<T, M, M>
    requires MatrixLimits<M, VectorSize>
{
    auto translation_matrix = Matrix<T, M, M>::identity();

    for (size_t i = 0; i < VectorSize; ++i) {
        translation_matrix[M - 1].at(i) = translation[i];
    }

    return translation_matrix;
}

template <typename T>
auto rotate_2x2(const Luminol::Units::Angle<T, Luminol::Units::Radian>& angle)
    -> Matrix<T, 2, 2> {
    const auto sin_angle = std::sin(angle.get_value());
    const auto cos_angle = std::cos(angle.get_value());

    auto rotation_matrix = Matrix<T, 2, 2>::identity();

    rotation_matrix[0][0] = cos_angle;
    rotation_matrix[0][1] = sin_angle;
    rotation_matrix[1][0] = -sin_angle;
    rotation_matrix[1][1] = cos_angle;

    return rotation_matrix;
}

template <typename T, size_t M>
auto rotate_x(const Luminol::Units::Angle<T, Luminol::Units::Radian>& angle)
    -> Matrix<T, M, M>
    requires(M == 3 || M == 4)
{
    const auto sin_angle = std::sin(angle.get_value());
    const auto cos_angle = std::cos(angle.get_value());

    auto rotation_matrix = Matrix<T, M, M>::identity();

    rotation_matrix[1][1] = cos_angle;
    rotation_matrix[1][2] = sin_angle;
    rotation_matrix[2][1] = -sin_angle;
    rotation_matrix[2][2] = cos_angle;

    return rotation_matrix;
}

template <typename T, size_t M>
auto rotate_y(const Luminol::Units::Angle<T, Luminol::Units::Radian>& angle)
    -> Matrix<T, M, M>
    requires(M == 3 || M == 4)
{
    const auto sin_angle = std::sin(angle.get_value());
    const auto cos_angle = std::cos(angle.get_value());

    auto rotation_matrix = Matrix<T, M, M>::identity();

    rotation_matrix[0][0] = cos_angle;
    rotation_matrix[0][2] = -sin_angle;
    rotation_matrix[2][0] = sin_angle;
    rotation_matrix[2][2] = cos_angle;

    return rotation_matrix;
}

template <typename T, size_t M>
auto rotate_z(const Luminol::Units::Angle<T, Luminol::Units::Radian>& angle)
    -> Matrix<T, M, M>
    requires(M == 3 || M == 4)
{
    const auto sin_angle = std::sin(angle.get_value());
    const auto cos_angle = std::cos(angle.get_value());

    auto rotation_matrix = Matrix<T, M, M>::identity();

    rotation_matrix[0][0] = cos_angle;
    rotation_matrix[0][1] = sin_angle;
    rotation_matrix[1][0] = -sin_angle;
    rotation_matrix[1][1] = cos_angle;

    return rotation_matrix;
}

template <typename T, size_t M, size_t VectorSize>
constexpr auto scale(const Vector<T, VectorSize>& scale) -> Matrix<T, M, M>
    requires MatrixLimits<M, VectorSize>
{
    auto scale_matrix = Matrix<T, M, M>::identity();

    for (size_t i = 0; i < VectorSize; ++i) {
        scale_matrix[i].at(i) = scale[i];
    }

    return scale_matrix;
}

template <typename T>
constexpr auto translate_2x2(const Vector<T, 2>& translation)
    -> Matrix<T, 2, 2> {
    return translate<T, 2, 2>(translation);
}

template <typename T>
constexpr auto translate_3x3(const Vector<T, 3>& translation)
    -> Matrix<T, 3, 3> {
    return translate<T, 3, 3>(translation);
}

template <typename T>
constexpr auto translate_4x4(const Vector<T, 3>& translation)
    -> Matrix<T, 4, 4> {
    return translate<T, 4, 3>(translation);
}

template <typename T>
constexpr auto scale_2x2(const Vector<T, 2>& scaling) -> Matrix<T, 2, 2> {
    return scale<T, 2, 2>(scaling);
}

template <typename T>
constexpr auto scale_3x3(const Vector<T, 3>& scaling) -> Matrix<T, 3, 3> {
    return scale<T, 3, 3>(scaling);
}

template <typename T>
constexpr auto scale_4x4(const Vector<T, 3>& scaling) -> Matrix<T, 4, 4> {
    return scale<T, 4, 3>(scaling);
}

}  // namespace Luminol::Maths::Transform
