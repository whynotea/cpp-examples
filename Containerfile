FROM ghcr.io/whynotea/devcontainer-cpp:latest as builder
FROM scratch
COPY --from=builder /usr/lib64/libstdc++.so.6 /usr/lib64/libm.so.6 /usr/lib64/libgcc_s.so.1 /usr/lib64/libc.so.6 /usr/lib64/ld-linux-x86-64.so.2 /lib64
COPY basic/build/basic /usr/bin/basic
CMD [ "/usr/bin/basic" ]
