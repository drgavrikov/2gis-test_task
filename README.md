## Проект "TwoGisHomeTask"

Этот проект представляет собой решение для тестовой задачи, предложенной компанией 2Gis.

### Сборка проекта

Для сборки проекта выполните следующие шаги:

1. Установите зависимости с помощью Conan:

    ```
    conan install . --build=missing
    ```

2. Перейдите в директорию `build`:

    ```
    cd build
    ```

3. Выполните сборку проекта с помощью CMake:

    ```
    cmake ../ -DCMAKE_TOOLCHAIN_FILE=Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
    ```

4. Запустите компиляцию:

    ```
    cmake --build .
    ```

### Запуск

После успешной сборки проекта, вы можете запустить его и тесты:

- Для запуска основного приложения выполните:

    ```
    ./src/TwoGisHomeTask -h
    ```

- Для запуска тестов выполните:

    ```
    ./test/TwoGisHomeTaskTests
    ```
