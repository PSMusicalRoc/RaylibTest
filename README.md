## Dependencies

### Windows
- MSYS2 and either MINGW64 or UCRT64
  - MINGW64 packages: `mingw-w64-x86_64-toolchain mingw-w64-x86_64-premake`
  - UCRT64 packages: `mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-premake`

### Linux
- Debian/Ubuntu
  - `sudo apt install build-essential`
  - <a href="https://premake.github.io/">Premake 5</a>
- Fedora
  - @TODO ADD FEDORA DEPENDENCIES

## Development Instructions

```
git clone https://github.com/PSMusicalRoc/RaylibTest.git
cd RaylibTest
git submodule init
premake5 gmake2
make
```