#
# Makefile for hwaddr-rand Linux kernel module
#

ifneq ($(KERNELRELEASE),) # building from the outside


obj-$(CONFIG_HWADDR_RAND) += hwaddr_rand.o


else # building as part of the kernel


EXTRA_FLAGS += -I$(PWD)

KDIR := /lib/modules/$(shell uname -r)/build
MDIR := /lib/modules/$(shell uname -r)
PWD	 := $(shell pwd)

export CONFIG_HWADDR_RAND := m

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

help:
	$(MAKE) -C $(KDIR) M=$(PWD) help

install: hwaddr_rand.ko
	install -m644 -b -D hwaddr_rand.ko ${MDIR}/kernel/drivers/net/hwaddr_rand.ko
	depmod -aq

uninstall:
	rm -f ${MDIR}/kernel/drivers/net/hwaddr_rand.ko
	depmod -aq


endif

.PHONY : all clean install uninstall
