# Makefile для сборки проекта tpmp-lab2-task3
# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

# Директории
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Исходные файлы
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/purchaser_server.c

# Объектные файлы
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Исполняемый файл
TARGET = $(BIN_DIR)/task3

# Цель по умолчанию
all: $(TARGET)

# Создание директорий
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Сборка завершена: $(TARGET)"

# Компиляция объектных файлов
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Очистка завершена"

# Запуск программы
run: $(TARGET)
	$(TARGET) 3

# Проверка с valgrind (для отладки)
memcheck: $(TARGET)
	valgrind --leak-check=full $(TARGET) 3

# Форматирование кода
format:
	clang-format -i $(SRC_DIR)/*.c $(SRC_DIR)/*.h

.PHONY: all clean run memcheck format
