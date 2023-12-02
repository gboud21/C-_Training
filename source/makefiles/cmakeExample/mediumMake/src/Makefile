ROOT_DIR=.
BASE_SRC_DIR=${ROOT_DIR}
ALGORITHM_SRC_DIR=${ROOT_DIR}/algorithm
DRIVER_SRC_DIR=${ROOT_DIR}/driver
TWS_SRC_DIR=${ROOT_DIR}/TWS/client
UTILS_SRC_DIR=${ROOT_DIR}/utils

BUILD_DIR=${ROOT_DIR}/build

INC_DIRS:=$(ALGORITHM_SRC_DIR) $(DRIVER_SRC_DIR) $(TWS_SRC_DIR) $(UTILS_SRC_DIR)
CODE_DIRS:=$(BASE_SRC_DIR) $(INC_DIRS)

INCLUDES:=$(foreach D,$(INC_DIRS),-I$(D))
TARGET=PickIt

CXXFILES=$(foreach D,$(CODE_DIRS),$(wildcard $(D)/*.cpp))

# --- Get all cpp files
MAIN_FILES:=$(shell find $(BASE_SRC_DIR) -name "*.cpp")
TWS_FILES:=$(shell find $(TWS_SRC_DIR) -name "*.cpp")
ALL_FILES=$(MAIN_FILES) $(TWS_FILES)

# --- Convert all cpp files to object files
ALL_OBJECTS:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp,%.o,$(CXXFILES)))

# --- Convert all object files to dependency files
DEPS:=$(patsubst %.o,%.d,$(ALL_OBJECTS))
DEPFLAGS=-MMD -MF $(@:.o=.d)

CXX=g++
PTHREAD_FLAG=-pthread
CXXFLAGS=$(PTHREAD_FLAG) -Wall -Wno-switch -std=c++11 -shared -fPIC

all: $(TARGET)

$(TARGET): $(ALL_OBJECTS)
	$(CXX) $(PTHREAD_FLAG) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	@echo Compiling $< into $@
	@if [ ! -d $(BUILD_DIR)/$(dir $<)/ ]; then mkdir -p $(BUILD_DIR)/$(dir $<); fi
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEPFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning"
	@rm -rf $(TARGET) $(ALL_OBJECTS) $(DEPS) $(BUILD_DIR)


-include $(DEPS)
