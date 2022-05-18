
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
test: TC2_INP := 1 Levitating 4 list play clear quit
test: TC2_OUT := LinkedList [ Levitating ] Levitating is now playing! LinkedList is cleared!LinkedList is cleared! quit!
test: TC3_INP := 3 Hello Enemy abc 14 list play next play add Sunshine add Run list next next next next next play quit
test: TC3_OUT := LinkedList [ abc Enemy Hello ]
abc is now playing!
Enemy is now playing!
LinkedList [ Run Sunshine abc Enemy Hello ]
Hello is now playing!
LinkedList is cleared!
quit!

test:

test:
	@$(call test_case,$(TC1_INP),$(TC1_OUT))
	@$(call test_case,$(TC2_INP),$(TC2_OUT))
	@$(call test_case,$(TC3_INP),$(TC3_OUT))
