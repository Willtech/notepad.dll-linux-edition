# REM  PROJECT: Notepad.dll (Linux Edition)
# REM  AUTHOR: master Damian Williamson Grad.
# REM  PURPOSE: Ritualized compilation of notepad.dll loader
# REM  COLLABORATOR: Microsoft CoPilot (AI Companion)

CC = gcc
CFLAGS = -Wall -O2
TARGET = notepad.dll
SRC = notepad.dll.c

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "🔨 Compiling $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "✅ Build complete."

clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	@echo "🧼 Ritual reset complete."
