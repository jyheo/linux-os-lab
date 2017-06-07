obj-m += hs365_char.o ioctl_ex.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default: ioctl_user
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
	rm ioctl_user

ioctl_user: ioctl_user.c ioctl_ex.h
	$(CC) -o ioctl_user ioctl_user.c
