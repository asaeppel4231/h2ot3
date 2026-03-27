# Contributing to h2ot3

Thank you for your interest in contributing to **h2ot3**!  
Contributions of all kinds are welcome — whether you want to fix bugs, improve documentation, add new backends, or help shape the future of the project.

This document explains how to get started, how to report issues, how to submit pull requests, and what standards we follow.

---

## 🧭 Getting Started

### Repository Structure

```sh
src/
core/          # Core engine components
backends/      # Platform-specific backends (dummy, xcb, cocoa, win32, ...)
thirdparty/    # Embedded third-party libraries
build/           # CMake build directory (generated)
```

## Platform Requirements

Depending on the backend you enable, you may need platform-specific dependencies:
- **Linux (xcb backend):**  
  `libxcb1-dev`, `libx11-dev`

- **macOS (cocoa backend):**  
  Xcode Command Line Tools

- **Windows (win32 backend):**  
  MSVC toolchain

If you only use the **dummy backend**, no platform dependencies are required.
The project aims to remain compatible with **ANSI C (C89)** unless debug features are enabled, in which case a **C99-compatible compiler** is required.

---

## 🔧 Building the Project

### 1. Configure the build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

### 2. Backend Selection

h2ot3 supports multiple platform backends. You can enable or disable them manually:

```sh
-DH2OT3_BACKEND_SUPPORT_XCB=ON/OFF
-DH2OT3_BACKEND_SUPPORT_COCOA=ON/OFF
-DH2OT3_BACKEND_SUPPORT_WIN32=ON/OFF
```

### 3. Backend Behavior

If **at least one platform backend** is enabled, only those backends will be built.
If **no backend is explicitly enabled**, the build system automatically falls back to the **dummy backend**.
  The dummy backend is intended for:
    headless builds
    CI environments
    development without platform dependencies

### 4. Build

```sh
cmake --build build --config Debug
```

### 5. Running tests (if available)

```sh
ctest --test-dir build
```
