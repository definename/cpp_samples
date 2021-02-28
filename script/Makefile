.PHONY: all clean

BUILD_DIR = ../build

all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Debug && cmake --build .

clean:
	rm -rf $(BUILD_DIR)
