.PHONY: default
default: all

.PHONY: all
all: 
	@$(MAKE) build-local
	@$(MAKE) docs
	@$(MAKE) install-local
	@$(MAKE) cpack

.PHONY: container-build
container-build:
	podman run -u root --rm -it -v "$$(pwd):/workspaces/cpp-examples" -w /workspaces/cpp-examples ghcr.io/whynotea/devcontainer-cpp:latest make

.PHONY: build-local
build-local:
	vcpkg install gtest
	vcpkg install fmt
	vcpkg install boost-asio
	mkdir -p build
	cmake -S . -B build -DUSE_ADDER=ON
	cmake --build build

.PHONY: image
image:
	podman build -t ghcr.io/whynotea/cpp-examples:latest .

.PHONY: run-local-%
run-local-%:
	@./build/src/bin/$*/$*

.PHONY: run-%
run-%:
	@podman run --rm -it -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --net=host ghcr.io/whynotea/cpp-examples:latest $*

.PHONY: install-local
install-local:
	mkdir -p install
	cmake --install build --prefix ./install

.PHONY: install
install:
	cmake --install build

.PHONY: cpack
cpack:
	mkdir -p release
	bash -c 'cd build && cpack -B ../release'

.PHONY: docs
docs:
	bash -c 'cd build && make doxygen'

.PHONY: ctest
ctest:
	bash -c 'cd build && ctest'

.PHONY: tag-%
tag-%:
	git tag -a $* HEAD

.PHONY: clean
clean:
	rm -rf ./build
	rm -rf ./install
	rm -rf ./release
