# Include the core environment definitions; this will set $(TOP).
include ../../py/mkenv.mk

# Include py core make definitions.
include $(TOP)/py/py.mk

# Set CFLAGS and libraries.
CFLAGS = -I. -I$(BUILD) -I$(TOP)
#LIBS = -lm

# Define the required object files.
OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

main.exe: $(OBJ)


XBE_TITLE = xbox-python
GEN_XISO = $(XBE_TITLE).iso
SRCS = $(CURDIR)/main.c $(CURDIR)/mphalport.c \
	$(CURDIR)/../../lib/mp-readline/readline.c \
	$(CURDIR)/../../lib/utils/gchelper_generic.c \
	$(CURDIR)/../../lib/utils/pyexec.c \
	$(CURDIR)/../../lib/utils/stdout_helpers.c
NXDK_DIR = $(CURDIR)/../../../nxdk-teufelchen/
include $(NXDK_DIR)/Makefile

# Thanks JayFoxRox 
# µPython need ssize_t in py/parser.c from <unistdh> which nxdk does not implement yet
CFLAGS += $(NXDK_CFLAGS) -Dssize_t=int -DSEEK_SET=0 -DSEEK_CUR=1 -DSEEK_END=2
CXXFLAGS += $(NXDK_CXXFLAGS)
ASFLAGS += $(NXDK_ASFLAGS)
LDFLAGS += $(NXDK_LDFLAGS)

include $(TOP)/py/mkrules.mk
