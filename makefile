
TARGET := Player
BUILD := build
src := $(wildcard *.c)
obj := $(src:%.c=$(BUILD)/%.o)

$(info $(src))
$(info $(obj))
$(info $(TARGET))

.PHONY: all build clean test

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(obj)
        $(CC) $^ -o $@

$(obj): | $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: %.c
        $(CC) -c  $< -o $@

clean:
	rm -f *.o Player
	rm -rf build

define test_case
        if [ "$(shell echo '$(1)' | ./$(BUILD)/Player)" -eq $(2) ]; then \
                echo "PASS";                            \
        else                                            \
                echo "FAIL - Expected: $(2), Actual: $(shell echo '$(1)' | ./$(BUILD)/Player)";    \
                exit 1;                                 \
        fi;
endef
test: TC1_INP := 3 Hello Enemy abc 3 add Run list quit
test: TC1_OUT := LinkedList [ Run abc Eneymy Hello ] LinkedList is cleared! quit!

test:
	@$(call test_case,$(TC1_INP),$(TC1_OUT))
