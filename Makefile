	
CC = armclang++
CXX = armclang++	
FC = armflang
	
TARGET_EXEC ?= MPC_qpOASES

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := ./include ./include/MPC_qpOASES ../qpOASES_3.2_ARMPL/include ../qpOASES_3.2_ARMPL/include/qpOASES
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -mcpu=native -Wall -Wfloat-equal -DLINUX -O3 -std=c++11 #-DVERBOSE

LDFLAGS = -L/usr/local/lib -L ../qpOASES_3.2_ARMPL/build/libs -L/opt/arm/arm-hpc-compiler-18.1_Generic-AArch64_Ubuntu-16.04_aarch64-linux/lib -L/opt/arm/armpl_time_limited-18.1.0_Generic-AArch64_Ubuntu-16.04_arm-hpc-compiler_18.1_aarch64-linux/lib
LDLIBS = -lqpOASES -lm -larmpl -lhsl_ma57 -lflang -lflangrti -lfakemetis

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p