.EXPORT_ALL_VARIABLES:

include Makeconf.local

.PHONY: all
all $(filter-out all, $(MAKECMDGOALS)) :
	@ln -fs $(BUILDDIR)/arch $(SRCDIR)/include/arch-$(ARCH)
	@echo $(SRCDIR)
	@$(MAKE) -f $(SRCDIR)/Makefile $@
