# Переменные компилятора и флагов
CC = gcc
CFLAGS = -Wall -Wextra -O2
LIBS = -lm

# Цели сборки
TARGET = area_calculator
SRCS = main_root.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

# Цель по умолчанию: полная сборка программы
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Цель очистки: удаление исполняемых и объектных файлов
clean:
	rm -f $(TARGET) $(OBJS)
