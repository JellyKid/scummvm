#include $(DEVKITPRO)/wut/share/wut_rules
#include "$(DEVKITPRO)/devkitPPC/base_tools"
LIBS += "-lwut"

clean: clean_wiiu

clean_wiiu:
	$(RM) $(TARGET).rpx

elf2rpx: $(EXECUTABLE)
	cp $< $*.strip.elf
	$(STRIP) -g $*.strip.elf
	elf2rpl $*.strip.elf $@
	rm $*.strip.elf
	mkdir -p ./wiiu_release/scummvm/data
	mkdir -p ./wiiu_release/scummvm/doc
	cp $(DIST_FILES_THEMES) ./wiiu_release/scummvm/data
	@echo built ... $(notdir $@)
ifdef DIST_FILES_ENGINEDATA
	cp $(DIST_FILES_ENGINEDATA) ./wiiu_release/scummvm/data
endif
ifdef DIST_FILES_NETWORKING
	cp $(DIST_FILES_NETWORKING) ./wiiu_release/scummvm/data
endif
ifdef DIST_FILES_VKEYBD
	cp $(DIST_FILES_VKEYBD) ./wiiu_release/scummvm/data
endif
	cp $(DIST_FILES_DOCS) ./wiiu_release/scummvm/doc/

.PHONY: clean_wiiu elf2rpx
