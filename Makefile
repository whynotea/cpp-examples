.PHONY: default
default: all

.PHONY: all
all: basic/main.cpp
	mkdir -p ./basic/build
	bash -c "cd ./basic/build && \
					 cmake .. && \
					 make"

.PHONY: image
image:
	podman build -t whynotea/cpp-examples:latest .

.PHONY: run
run:
	@podman run --rm -it whynotea/cpp-examples:latest

.PHONY: clean
clean:
	rm -rf ./basic/build
