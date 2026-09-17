# Mining Company

Учебный проект: добыча астероидов.

## Зависимости

- Raylib (https://www.raylib.com/)
- C++17, Make, g++
- X11 development libraries (Linux)

### Установка Raylib (Ubuntu/Debian)
```bash
sudo apt-get install libraylib-dev
# Или собрать из исходников:
git clone https://github.com/raysan5/raylib.git
cd raylib/src && make && sudo cp libraylib.a /usr/local/lib/
sudo cp -r ../src/*.h /usr/local/include/