# cpp-examples
A collection of cpp coding examples

## Installation
### Podman
podman run --rm -it ghcr.io/whynotea/cpp-examples:latest

To run gui examples:

podman run --rm -it -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --net=host ghcr.io/whynotea/cpp-examples:latest `<cmd>`

e.g.

podman run --rm -it -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --net=host ghcr.io/whynotea/cpp-examples:latest basic-gui
