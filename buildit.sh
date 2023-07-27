#!/bin/bash
# This is an alternative build mechanism using buildah. The advantage here is
# that the current dev containers root level .so files can be copied into the
# image unlike podman build which only uses paths relative to the Containerfile.
#
# To run as rootless call: buildah unshare ./buildit.sh

set -x

newcontainer=$(buildah from scratch)
scratchmnt=$(buildah mount $newcontainer)

dnf install -y --installroot $scratchmnt @base-x --releasever 38 --setopt=install_weak_deps=false --setopt=tsflags=nodocs
dnf clean all -y --installroot $scratchmnt --releasever 38 && rm -rf /var/cache/yum

buildah copy $newcontainer /usr/lib64/libstdc++.so.6 /lib64
buildah copy $newcontainer /usr/lib64/libm.so.6 /lib64
buildah copy $newcontainer /usr/lib64/libgcc_s.so.1 /lib64
buildah copy $newcontainer /usr/lib64/libc.so.6 /lib64
buildah copy $newcontainer /usr/lib64/ld-linux-x86-64.so.2 /lib64
buildah copy $newcontainer ./build/src/bin/basic/basic /usr/bin/basic
buildah copy $newcontainer ./build/src/bin/basic-gui/basic-gui /usr/bin/basic-gui

buildah config --cmd /usr/bin/basic $newcontainer

# set some config info
buildah config --label name=whynotea/examples $newcontainer

# commit the image
buildah unmount $newcontainer
buildah commit $newcontainer whynotea/examples
