# CSE 100 FA26 PA1 starter

Read [PA1-BST.md](PA1-BST.md) for the assignment and method contracts. This repository contains starter code and public tests only. You must add your own tests under `test/bst/` and submit them with your BST code.

## Install the development tools

The recommended path is the included development container. It provides the C++14 compiler, Meson, Ninja, GoogleTest, and test tools, so you do not need to install Meson on your host computer.

1. Install and start [Docker Desktop for macOS](https://docs.docker.com/desktop/setup/install/mac-install/) or [Docker Desktop for Windows](https://docs.docker.com/desktop/setup/install/windows-install/). On Windows, use the Linux containers backend; Docker's Windows guide explains its WSL 2 setup. On Linux, follow the [Docker Engine installation guide](https://docs.docker.com/engine/install/) for your distribution.
2. In a host terminal, run `docker info`. It should display information about the running Docker server. If it reports that it cannot connect, start Docker Desktop before continuing.
3. Install [Visual Studio Code](https://code.visualstudio.com/) and its [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers).
4. Open this repository in VS Code. Run **Dev Containers: Reopen in Container** from the Command Palette. The first build downloads the Ubuntu base image and installs the required packages.
5. In the container terminal, check `meson --version`, `ninja --version`, and `c++ --version`.

These steps follow the current [VS Code Dev Containers guide](https://code.visualstudio.com/docs/devcontainers/containers). If you prefer a native Ubuntu setup, install the same build tools with:

```sh
sudo apt-get update
sudo apt-get install build-essential meson ninja-build libgtest-dev lcov valgrind cppcheck python3 python3-lxml zip
```

Then use the build commands below. See the [Meson installation guide](https://mesonbuild.com/Quick-guide.html) for other systems.

## Build and test

From the repository root, in the container or an equivalent native environment:

```sh
meson setup build
ninja -C build
ninja -C build test
```

The first command configures the build; the second compiles all executables; the third runs the public GoogleTest tests. The starter's placeholder implementations may fail tests until you complete them. A successful compilation alone does not mean the BST is correct.

Executables are under `build/test/bst/`. After implementing the BST methods, run the integer command-line tester with:

```sh
./build/test/bst/mainInt.cpp.executable < data/mainIntInput/mainIntExample.txt
```

To make a Gradescope upload from the repository root:

```sh
./create_submission_zip.sh
```

This writes `submission.zip` with `src/` and `test/` at its root. See [COMMANDS_CHEATSHEET.md](COMMANDS_CHEATSHEET.md) for more commands.
