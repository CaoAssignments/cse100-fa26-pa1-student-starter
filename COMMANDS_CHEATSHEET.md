# Build and test commands

Run these from the repository root.

| Command | Purpose |
| --- | --- |
| `meson setup build` | Configure the C++14 project. |
| `ninja -C build` | Compile all executables with the configured compiler. |
| `ninja -C build test` | Compile and run the GoogleTest tests. |
| `./build/test/bst/mainInt.cpp.executable < data/mainIntInput/mainIntExample.txt` | After implementation, run the integer BST command-line tester with sample input. |
| `ninja -C build cov` | Create a coverage report under `build/meson-logs/coveragereport/`. |
| `meson test -C build --wrapper=valgrind` | Run the tests under Valgrind. |
| `ninja -C build cppcheck` | Run the configured static analysis target. |
| `./create_submission_zip.sh` | Package `src/` and `test/` for Gradescope. |

If configuration becomes stale after changing build files, remove the generated `build/` directory and run `meson setup build` again.
