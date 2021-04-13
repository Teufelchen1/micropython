# Include the core environment definitions; this will set $(TOP).
include ../../py/mkenv.mk

# Include py core make definitions.
include $(TOP)/py/py.mk

CC = nxdk-cc
SIZE = echo

# Set CFLAGS and libraries.
CFLAGS = -I. -I$(BUILD) -I$(TOP) -Dssize_t=int -DSEEK_SET=0 -DSEEK_CUR=1 -DSEEK_END=2
#LIBS = -lm

# Define the required source files.
SRC_C = \
	main.c \
	mphalport.c \
	lib/mp-readline/readline.c \
	lib/utils/gchelper_generic.c \
	lib/utils/pyexec.c \
	lib/utils/stdout_helpers.c \

# Define the required object files.
OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

# Define the top-level target, the main firmware.
all: $(BUILD)/firmware.elf

# Define how to build the firmware.
$(BUILD)/firmware.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

# Include remaining core make rules.
include $(TOP)/py/mkrules.mk