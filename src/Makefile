CC=g++
CFLAGS=-std=c++17 -Wpedantic -Wall -Werror -Wextra -Wshadow
SANFLAG=#-fsanitize=address -g
COVFLAGS=-fprofile-arcs -ftest-coverage

# Директории и исходники
LIBRARY = s21_containers.a
TARGET = containers

TEST_DIR = ./tests
C_TEST_FILES = $(shell find $(TEST_DIR) -type f -name "*.cc")
O_TEST_FILES = $(subst .cc,.o, $(C_TEST_FILES))
OUT_TEST=$(TEST_DIR)test.out

# Флаги для тестов
TEST_FLAGS=-lgtest -lgtest_main
# Если компилятор clang ему нужна другая стандартная библиотека для линковки
# временно кидаю к флагам тестовым, не вижу пока что смысла отдельный флаг делать
ifeq ($(CC),clang)
	TEST_FLAGS+=-lc++
endif

#all: $(LIBRARY)

# Собираем библиотеку
#$(LIBRARY): $(BACK_O_FILES)
#ar rcs $@ $^
#ranlib $@

# Компилируем объектные файлы библиотеки и тестов
%.o: %.cc
	$(CC) $(CFLAGS) -c $(SANFLAG) $(COVFLAGS) $< -o $@

test: $(O_TEST_FILES)
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(O_TEST_FILES) -o $(OUT_TEST) $(TEST_FLAGS)

	$(OUT_TEST)

gcov_report:
	@mkdir -p $(TEST_DIR)/coverage
	(cd $(TEST_DIR)/coverage && gcov $(subst tests/,../, $(C_TEST_FILES)))
	@echo ""
	lcov -t "test" -o $(TEST_DIR)/report.info -c -d $(TEST_DIR) --ignore-errors inconsistent
	lcov --remove $(TEST_DIR)/report.info '/usr/*' -o $(TEST_DIR)/report.info
	lcov --remove $(TEST_DIR)/report.info '*src/tests*' -o $(TEST_DIR)/report.info
	genhtml -o $(TEST_DIR)/report $(TEST_DIR)/report.info
	open $(TEST_DIR)/report/index.html

clang:
	@find . -name '*.cc' -exec clang-format -n {} \;
	@find . -name '*.h' -exec clang-format -n {} \;
	@find . -name '*.cc' -exec clang-format -i {} \;
	@find . -name '*.h' -exec clang-format -i {} \;

clean:
	find . -type f -name "*.o" -delete
	find . -type f -name "*.out" -delete
	find . -type f -name "*.gc*" -delete
	rm -rf $(TEST_DIR)/report* $(TEST_DIR)/coverage
	rm -f $(LIBRARY) $(OUT_TEST)

rebuild: clean all

# Докер и валгринд
NAME = hauling$(TARGET)
docker:
	docker build -t $(NAME):v1 .
	docker run -it --name $(NAME) $(NAME):v1 /bin/bash

renew_docker: clean
	docker start $(NAME)
	docker exec $(NAME) rm -rf /code
	docker cp . $(NAME):/code
	docker exec -it $(NAME) /bin/bash

delete_docker:
	docker stop $(NAME)
	docker rm $(NAME)
	docker rmi $(NAME):v1

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--log-file=leaks_log.txt $(OUT_TEST); vim leaks_log.txt

