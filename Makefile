.PHONY: default
default: all

.PHONY: all
all: 
	@$(MAKE) build-local

.PHONY: container-build
container-build:
	echo "Pre-Container"
	id
	ls -alh
	podman run -u root --rm -it -v "$$(pwd):/workspaces/cpp-examples" -w /workspaces/cpp-examples ghcr.io/whynotea/devcontainer-cpp:latest make
	# echo "Post-Container"

.PHONY: build-local
build-local:
	echo "In Container"
	id
	ls -alh
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
