# C++ Build and Run

Have you gotten tired of typing long commands only to build a C++ file? And then type yet another command to run your freshly-compiled program? This tool makes it easy! With the help of this program you can easily build and run your C++ files using one short command.

## Installation

**1. Clone this repository**

```
git clone git@github.com:jozsefsallai/cpp-build
cd cpp-build
```

**2. Build**

```
make build
```

If you're on Windows and/or can't use make, just build it as you normally would.

```
g++ cpp-build.cpp -o cpp-build.exe
```

**3. Add to PATH**

On *nix:

```
make movebin
```

On Windows: do it manually :)

---

## Usage

It's super easy to use the tool! Just run this command:

```
cpp-build [filename]
```

where **[filename]** is the name of the C++ file without the extension. The program will automatically compile your code and run it for you.

---

## Contributions

Contributions are always welcome and appreciated!

---

(c) József Sallai. All rights reserved.
