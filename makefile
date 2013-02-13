# Directories
S_DIR=source
B_DIR=build

# Files
S_FILES=$(S_DIR)/*.cpp $(S_DIR)/*/*.cpp $(S_DIR)/*.h $(S_DIR)/*/*.h

# Output
EXEC=$(B_DIR)/sdl_app

# Build settings
CC=g++
# SDL options
CC_SDL=-lSDL -lSDL_image `sdl-config --cflags --libs`


all:build_run

build:
	$(CC) -o $(EXEC) -O3 $(S_FILES) $(CC_SDL)

build_run:
	$(CC) -o $(EXEC) $(S_FILES) $(CC_SDL); $(EXEC)

clean:
	rm -rf $(B_DIR)/*
