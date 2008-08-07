.EXPORT_ALL_VARIABLES:

include Makeconf.local

.PHONY: all
all $(filter-out all, $(MAKECMDGOALS)) :
	@echo $(SRCDIR)
	@$(MAKE) -f $(SRCDIR)/Makefile $@
