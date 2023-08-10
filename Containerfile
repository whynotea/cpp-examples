FROM fedora:37
RUN dnf install -y @base-x glew-devel --setopt=install_weak_deps=false --setopt=tsflags=nodocs && dnf clean all && rm -rf /var/cache/yum
COPY build/src/bin/basic/basic /usr/bin/basic
COPY build/src/bin/basic_gui/basic_gui /usr/bin/basic_gui
COPY build/src/bin/design_patterns/design_patterns /usr/bin/design_patterns
CMD [ "/usr/bin/basic" ]
