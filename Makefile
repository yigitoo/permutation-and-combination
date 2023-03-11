ifeq ($(OS), Windows_NT)
clear_console := cls
rmdir := rd /s
exe_format := .exe
pause_cmd := pause
create_file := echo.>
build_folder := .\build\\
else
clear_console := clear
rmdir := rm -rf
exe_format := ""
pause_cmd := ./scripts/pause.sh
create_file := touch 
build_folder := "./build"
endif

CC = g++
CFLAGS = ""

all: clean build run wait

build:
	mkdir build -force
	$(CC) -o build/main$(exe_format) src/main.cc
run:
	build/main$(exe_format)
wait:
	pause
clean: $(build_folder)
	ifeq ("$(wildcard $(build_folder))", "")
	mkdir build
	else
	$(rmdir) $(build_folder)
	mkdir build
	cd build
	$(create_file) .gitkeep
	cd ..
	
	endif
chmod_scripts:
	chmod +x ./scripts/pause.sh

.PHONY: all build run wait clean $(build_folder)