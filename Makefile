.PHONY: default
default: all

.PHONY: all
all: 
	@$(MAKE) build-local

.PHONY: container-build
container-build:
	podman run -u root --rm -it -v "$$(pwd):/workspaces/cpp-examples" -w /workspaces/cpp-examples ghcr.io/whynotea/devcontainer-cpp:latest make

.PHONY: build-local
build-local:
	mkdir -p build
	bash -c "cd ./build &&\
        cmake .. -DUSE_ADDER=OFF &&\
        make"

.PHONY: image
image:
	podman build -t ghcr.io/whynotea/cpp-examples:latest .

.PHONY: run-local-%
run-local-%:
	@./build/src/bin/$*/$*

.PHONY: run-%
run-%:
	@podman run --rm -it -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --net=host ghcr.io/whynotea/cpp-examples:latest $*

.PHONY: clean
clean:
	rm -rf ./build
