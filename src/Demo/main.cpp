#include <iostream>

#include <LuminolMaths/Vector.hpp>
#include <LuminolMaths/Matrix.hpp>
#include <LuminolMaths/Transform.hpp>
#include <LuminolMaths/Units/Angle.hpp>

namespace {

auto print_matrix(const Luminol::Maths::Matrix4x4f& matrix) -> void {
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            std::cout << matrix[i].at(j) << ' ';
        }
        std::cout << '\n';
    }
}

}  // namespace

auto main() -> int {
    std::cout << "Hello, World!\n";

    constexpr auto vector = Luminol::Maths::Vector3{0.0f, 1.0f, -1.0f};

    std::cout << vector.x() << '\n';
    std::cout << vector.y() << '\n';
    std::cout << vector.z() << '\n';

    constexpr auto matrix = Luminol::Maths::Matrix4x4::identity();

    print_matrix(matrix);

    constexpr auto angle = Luminol::Units::Degrees{90.0};
    std::cout << angle.as<Luminol::Units::Radian>().get_value() << '\n';

    const auto rotation_matrix = Luminol::Maths::Transform::rotate_x<double, 4>(
        angle.as<Luminol::Units::Radian>()
    );

    print_matrix(rotation_matrix);

    return 0;
}
