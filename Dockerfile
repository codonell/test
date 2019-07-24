FROM centos:6
COPY vsyscall-test.c /
RUN yum -y install gcc
RUN gcc -o /vsyscall-test /vsyscall-test.c
