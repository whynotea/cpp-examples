FROM fedora:37
RUN dnf install -y @base-x --setopt=install_weak_deps=false --setopt=tsflags=nodocs && dnf clean all && rm -rf /var/cache/yum
COPY build/src/bin/basic/basic /usr/bin/basic
COPY build/src/bin/basic-gui/basic-gui /usr/bin/basic-gui
CMD [ "/usr/bin/basic" ]
