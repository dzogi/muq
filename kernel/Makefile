# Copyright (C) 2007, Josip Dzolonga
#
# Description: Master makefile
#
# Based on L4 Pistachio's Makefile
#
# BSD License

SHELL=bash

ifeq ($(strip $(SRCDIR)), )

ifeq ($(strip $(BUILDDIR)), )
# HOWTO
all:
	@echo "This is the source directory";
	@echo "---------------------------------";
	@echo "";
	@echo "1. Run make BUILDDIR=<absolute path of nonexisting directory>"
	@echo "2. Chdir to build directory";
	@echo "3. Run make menuconfig && make";

else
	# BUIILDDIR SET, SRCDIR not set, create the directory
all:
	@if [ "/" != "`echo $(BUILDDIR) | cut -c1`" ]; then \
		echo "$(BUILDDIR) is not an absolute path, aborting."; \
		echo ""; \
		exit -1; \
	 fi

	@if [ -d $(BUILDDIR) ]; then \
		echo "Directory $(BUILDDIR) already exists, aborting."; \
		echo ""; \
		exit -1; \
	 fi

	@echo "Creating the directory"
	@cp -R conf/template $(BUILDDIR)
	@mkdir $(BUILDDIR)/include

	@echo "SRCDIR=$(CURDIR)" >> $(BUILDDIR)/Makeconf.local
	@echo "Done."
	@echo ""
endif

else

.PHONY: create_symlink
# We create this symlink so we can all arch-specific headers are under /
create_symlink:
	@ln -fs $(SRCDIR)/include/arch-$(ARCH) $(BUILDDIR)/include/arch

all: create_symlink $(ARCH)-kernel
	@echo "Done."

include $(SRCDIR)/mk/Makeconf

endif

