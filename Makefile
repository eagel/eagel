CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Ilib/boost/inc -Iinc

OBJS =		src/main.o

TEST_OBJS = tst/main_tests.o

LIBS =		lib/boost/lib/libboost_system.a

TEST_LIBS = lib/boost/lib/libboost_unit_test_framework.a

TARGET =

TEST_TARGET = dst/main_tests

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) -o $(TEST_TARGET) $(OBJS) $(LIBS) $(TEST_OBJS) $(TEST_LIBS)

all:	$(TARGET) $(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
