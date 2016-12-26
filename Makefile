.PHONY: all static dynamic clean clean_deps clean_objects clean_targets \
   		install format includes test check

PREFIX ?= /usr/local

# Directory constants

BUILD_DIR = build
TESTS_DIR = tests
SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = .dep
INC_DIR = $(BUILD_DIR)/include

# Additional build configuration

NAME = glmm

CFLAGS  += -g -Wall -Wextra -std=c11 -I$(SRC_DIR)
LDFLAGS += -L$(BUILD_DIR)
LDLIBS  +=

# Dynamically get the sources/objects/tests

SOURCES = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(SRC_DIR)/**/*.h $(SRC_DIR)/*.h)
TESTS   = $(patsubst %.c,%,$(wildcard $(TESTS_DIR)/*_test.c))
TARGET  = $(BUILD_DIR)/lib$(NAME)

AR_OBJ_DIR = $(OBJ_DIR)/static
AR_DEP_DIR = $(DEP_DIR)/static
AR_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(AR_OBJ_DIR)/%.o,$(SOURCES))
AR_TARGET  = $(TARGET).a

SO_OBJ_DIR = $(OBJ_DIR)/dynamic
SO_DEP_DIR = $(DEP_DIR)/dynamic
SO_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(SO_OBJ_DIR)/%.o,$(SOURCES))
SO_TARGET  = $(TARGET).so

INC_HEADERS = $(patsubst $(SRC_DIR)/%.h,$(INC_DIR)/%.h,$(HEADERS))

# Create directories to prevent "cannot create file" errors

$(shell mkdir -p $(BUILD_DIR) $(SRC_DIR) $(INC_DIR))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(AR_DEP_DIR)%,$(dir $(SOURCES))))
$(shell mkdir -p $(patsubst $(SRC_DIR)%,$(SO_DEP_DIR)%,$(dir $(SOURCES))))
$(shell mkdir -p $(dir $(AR_OBJECTS) $(SO_OBJECTS)))

# Build the main targets

all: $(AR_TARGET) $(SO_TARGET) includes

$(AR_OBJ_DIR)/%.o : $(SRC_DIR)/%.c
$(AR_OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(AR_DEP_DIR)/%.d
	$(CC) $(CFLAGS) -MM -MP -MT $@ -o $(AR_DEP_DIR)/$*.d $<
	$(CC) $(CFLAGS) -c -o $@ $<

$(SO_OBJ_DIR)/%.o : $(SRC_DIR)/%.c
$(SO_OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(SO_DEP_DIR)/%.d
	$(CC) $(CFLAGS) -MM -MP -MT $@ -o $(SO_DEP_DIR)/$*.d $<
	$(CC) $(CFLAGS) -c -o $@ $<

$(AR_TARGET): $(AR_OBJECTS)
	$(AR) rcs $@ $^
	ranlib $@

$(SO_TARGET): CFLAGS  += -fPIC
$(SO_TARGET): LDFLAGS += -shared
$(SO_TARGET): $(SO_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

includes: $(INC_HEADERS)

$(INC_DIR)/%.h : $(SRC_DIR)/%.h
	@mkdir -p $(dir $@)
	@cp $< $@

# Clean dependencies, objects, or the main target

clean:
	rm -rf $(DEP_DIR) $(OBJ_DIR) $(BUILD_DIR)

clean_deps:
	rm -rf $(DEP_DIR)

clean_objects:
	rm -f $(AR_OBJECTS) $(SO_TARGETS)

clean_targets:
	rm -f $(AR_TARGET) $(SO_TARGET)

# Install to system

install: all
	install -d $(BUILD_DIR)/include/ $(PREFIX)/include/
	install -d $(BUILD_DIR)/lib64/ $(PREFIX)/lib64/

# Format code

format:
	clang-format -i $(SOURCES) $(HEADERS)

# Builds test executables

$(TESTS): $(AR_OBJECTS)
	$(CC) $(CFLAGS) -c -o $@.o $@.c
	$(CC) $(LDFLAGS) -o $@ $@.o $^ $(LDLIBS)
	@rm $@.o

test: CFLAGS  += $(shell pkg-config check --cflags) -DTEST_BUILD
test: LDFLAGS += $(shell pkg-config check --libs-only-L)
test: LDLIBS  += $(shell pkg-config check --libs-only-l) -l$(NAME)
test: clean_objects $(TESTS)
	export LD_LIBRARY_PATH=$(BUILD_DIR); $(addsuffix ;,$(TESTS))
	@rm $(TESTS)
	@rm -f $(AR_OBJECTS)

# Checks for potentially unsafe functions

BADFUNCS = '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true

# Dependency file hacks
# Requires all dependency files, but doesn't error out if they
# aren't there

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d
-include $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(SOURCES))
