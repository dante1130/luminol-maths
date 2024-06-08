#include <iostream>

#include <LuminolMaths/Vector.hpp>
#include <LuminolMaths/Matrix.hpp>
#include <LuminolMaths/Transform.hpp>
#include <LuminolMaths/Units/Angle.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Acceleration.hpp>
#include <LuminolMaths/Units/Energy.hpp>
#include <LuminolMaths/Units/Force.hpp>
#include <LuminolMaths/Units/Density.hpp>

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

    constexpr auto perspective_matrix_params =
        Luminol::Maths::Transform::PerspectiveMatrixParams<double>{
            .fov = Luminol::Units::Degrees{90.0},
            .aspect_ratio = 16.0 / 9.0,
            .near_plane = 0.1,
            .far_plane = 100.0
        };

    const auto perspective_matrix =
        Luminol::Maths::Transform::left_handed_perspective_projection_matrix(
            perspective_matrix_params
        );

    print_matrix(perspective_matrix);

    constexpr auto mass = Luminol::Units::Kilograms{1.0};

    std::cout << "1 kg in mg: "
              << mass.as<Luminol::Units::Milligram>().get_value() << '\n';

    constexpr auto acceleration = Luminol::Units::MetersPerSecondSquared{9.81};

    std::cout << "9.81 m/s^2 in cm/s^2: "
              << acceleration.as<Luminol::Units::CentimeterPerSecondSquared>()
                     .get_value()
              << '\n';

    constexpr auto velocity = Luminol::Units::MetersPerSecond{10.0};

    constexpr auto energy = Luminol::Units::Joules{mass, velocity};

    std::cout << "1 kg at 10 m/s: " << energy.get_value() << " J\n";

    constexpr auto force = mass / acceleration;

    std::cout << "Force of 1 kg under 9.81 m/s^2: " << force.get_value()
              << " N\n";

    constexpr auto density = mass / Luminol::Units::CubicMeters{1.0};

    std::cout << "Density of 1 kg in 1 m^3: " << density.get_value()
              << " kg/m^3\n";

    return 0;
}
