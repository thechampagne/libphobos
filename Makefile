BUILD := build
DD := dmd
STATIC := -lib
SHARED := -shared -defaultlib=libphobos2.so
LIBS := $(BUILD)/uri.o $(BUILD)/remainder.o


.PHONY: all

all: $(LIBS)
	$(DD) $(SHARED) $(LIBS) -oflib/libphobos.so
	$(DD) $(STATIC) $(LIBS) -oflib/libphobos.a

$(BUILD)/uri.o: uri/uri.d
	$(DD) -c -od$(BUILD) $<

$(BUILD)/remainder.o: math/remainder.d
	$(DD) -c -od$(BUILD) $<

clean:
	find $(BUILD) -type f -name '*.o' -delete
	find lib -type f \( -name '*.so' -o -name '*.a' \) -delete
