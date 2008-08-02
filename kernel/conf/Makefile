# Build the tools || die

CMLPATH = $(SRCDIR)/tools/cml2
CMLCOMPILE = $(CMLPATH)/cmlcompile.py
CMLCONFIG = $(CMLPATH)/cmlconfigure.py
CMLCONFIGTRANS = $(CMLPATH)/configtrans.py
CMLMODE = -c

CML_INPUT=$(addprefix $(SRCDIR)/conf/, rules.cml)

CMLBATCH_PARAMS ?=
CMLCONFIG_OPTIONS = -o config.out -i config.out \
  $(addprefix -D, $(CMLBATCH_PARAMS)) rules.out

rules.out: $(CML_INPUT)
	@$(CMLCOMPILE) -o $@ $<

.PHONY: always

config.out: rules.out always
	@$(CMLCONFIG) $(CMLMODE) $(CMLCONFIG_OPTIONS)

config.h .config: config.out

	@$(CMLCONFIGTRANS) -h $(@D)/config.h -s $(@D)/.config $<

$(BUILDDIR)/Makeconf.local: .config
	@echo "Rewriting $(@F)";
	@awk -F'[_=]' '/^CONFIG_ARCH_[^_]*=y/ { ARCH=$$3 } END{ { printf(",s/^ARCH *=.*/ARCH=%s/\nwq\n", tolower(ARCH)) }}' $< | ed -s $@

menuconfig: $(BUILDDIR)/Makeconf.local
