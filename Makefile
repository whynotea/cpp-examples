.PHONY: default
default: all

.PHONY: all
all: 
	@$(MAKE) build-local

.PHONY: container-build
container-build:
	podman run -u code --rm -it -v "$$(pwd):/workspace" -w /workspace --userns=keep-id ghcr.io/whynotea/devcontainer-cpp:latest make

.PHONY: build-local
build-local:
	mkdir -p build
	bash -c "cd ./build &&\
        cmake .. &&\
        make"

.PHONY: image
image:
	podman build -t whynotea/cpp-examples:latest .

.PHONY: run-%
run-%:
	@podman run --rm -it -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --net=host whynotea/cpp-examples:latest $*

.PHONY: clean
clean:
	rm -rf ./build
