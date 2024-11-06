include(get_cpm.cmake)

CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG v1.15.2
    OPTIONS 
        "gtest_force_shared_crt ON" 
        "INSTALL_GTEST OFF" 
        "BUILD_GMOCK OFF"
    EXCLUDE_FROM_ALL
    SYSTEM
)
