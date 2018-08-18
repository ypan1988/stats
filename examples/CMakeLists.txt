add_executable(rmath_qbeta rmath_qbeta.cc)
target_link_libraries(rmath_qbeta Statslabs::stats)

add_executable(lmfit lmfit.cc)
target_link_libraries(lmfit Statslabs::stats)
