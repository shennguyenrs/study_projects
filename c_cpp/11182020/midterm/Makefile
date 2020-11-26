obj-m := hello.o

KERNBUILD = /lib/modules/$(shell uname -r)/build

all:
	make -C KERNBUILD M=$(PWD) modules

clean:
	make -C KERNBUILD M=$(PWD) clean
