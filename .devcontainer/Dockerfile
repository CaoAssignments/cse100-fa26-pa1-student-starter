FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential meson ninja-build libgtest-dev \
    lcov valgrind cppcheck gdb git \
    python3 python3-lxml ca-certificates zip unzip \
    && rm -rf /var/lib/apt/lists/*
