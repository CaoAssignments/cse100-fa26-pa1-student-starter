project('pa1_bst', 'cpp',
    version : '0.0.1',
    default_options : ['warning_level=3',
                     'b_coverage=true',
                     'cpp_std=c++14'])


# === src dependencies ===
# === end src dependencies ===
subdir('src')


# === test dependencies ===
gtest_dep = dependency('gtest', main: true)
if not gtest_dep.found()
  error('MESON_SKIP_TEST: gtest not installed.')
endif
# === end test dependencies ===
subdir('test')


# === custom commands ===
run_target('cov',
    command : ['./build_scripts/generate_coverage_report'])

run_target('cppcheck', command : ['cppcheck',
    '--enable=all', '--std=c++14', '--suppress=missingInclude',
    join_paths(meson.project_source_root(), 'src'),
    join_paths(meson.project_source_root(), 'test')])
# === end custom commands ===
