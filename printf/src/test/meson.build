gtest = dependency('gtest', main: true)
test(
    'printf.cpp',
    executable(
        'printf_test',
        sources: ['printf_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)src = include_directories('.')
subdir('test')
