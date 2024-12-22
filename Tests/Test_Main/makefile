CC = g++-11
CFLAGS = -g -O0 --coverage
LDFLAGS =

# Исходные файлы
SRC = Test_Main.cpp
EXEC = Test_Main

# Файлы отчета и их директории
INFO_FILE = Test_Main.info
HTML_DIR = Test_Main_html

# Цель по умолчанию
all: $(EXEC) run_tests generate_coverage_report open_report

# Компиляция программы
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Запуск тестов
run_tests: $(EXEC)
	./$(EXEC)

# Генерация отчета о покрытии
generate_coverage_report: run_tests
	lcov --gcov-tool /usr/bin/gcov-11 --capture --directory . --output-file $(INFO_FILE) --exclude "/usr/include/*" --exclude "/usr/lib/*" --exclude "/boost/*" --rc lcov_file_prefix=./
	genhtml $(INFO_FILE) --output-directory $(HTML_DIR)

# Открытие отчета
open_report: generate_coverage_report
	xdg-open $(HTML_DIR)/index.html

# Очистка сгенерированных файлов
clean:
	rm -f $(EXEC) $(INFO_FILE)
	rm -rf $(HTML_DIR)