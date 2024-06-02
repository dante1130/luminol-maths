#include <iostream>

#include <LuminolMaths/Vector.hpp>
#include <LuminolMaths/Matrix.hpp>
#include <LuminolMaths/Units/Angle.hpp>

auto main() -> int {
    std::cout << "Hello, World!\n";

    constexpr auto vector = Luminol::Maths::Vector3{0.0f, 1.0f, -1.0f};

    std::cout << vector.x() << '\n';
    std::cout << vector.y() << '\n';
    std::cout << vector.z() << '\n';

    constexpr auto matrix = Luminol::Maths::Matrix4x4::identity();

    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            std::cout << matrix[i].at(j) << ' ';
        }
        std::cout << '\n';
    }

    constexpr auto angle = Luminol::Units::Degrees{90.0};
    std::cout << angle.as<Luminol::Units::Radian>().get_value() << '\n';

    return 0;
}
